#version 420

in vec4 fColour;	
in vec4 fVertWorldLocation;
in vec4 fNormal;
in vec4 fUVx2;
in vec4 fBI;					// idk what these are, something to do with the bones
in vec4 fTAN;					// vertex tan
in vec4 fBoneID;				// bone ID
in vec4 fBoneWeights;			// bone weights
	
uniform vec4 diffuseColour;				
uniform vec4 specularColour;

// Used to draw debug (or unlit) objects
uniform vec4 debugColour;			
uniform bool bDoNotLight;		

uniform vec4 eyeLocation;

uniform vec2 waterOffset;

uniform float seaFloor;
uniform float mountainTop;

// Texture samplers
uniform sampler2D textSamp00;
uniform sampler2D textSamp01;
uniform sampler2D textSamp02;
uniform sampler2D textSamp03;

uniform sampler2D secondPassColourTexture;

uniform float textRatio0;
uniform float textRatio1;
uniform float textRatio2;
uniform float textRatio3;

uniform samplerCube skyBox;
uniform bool bIsSkyBox;

uniform bool bIsWater;

uniform bool bIsSand;

uniform bool bIsIsland;

// For now, we will use the same shader for both passes
// Pass 0 is the pass to the FBO (the 1st one)
// Pass 1 is the "2nd" pass, texturing the "quad"
uniform int passNumber;

uniform vec4 tex_0_3_ratio;




out vec4 pixelColour;			// RGB A   (0 to 1)

// Fragment shader
struct sLight
{
	vec4 position;			
	vec4 diffuse;	
	vec4 specular;	// rgb = highlight colour, w = power
	vec4 atten;		// x = ConstAttenant, y = LinearAttenear, z = quadratic, w = DistanceCutOff
	vec4 direction;	// Spot, directional lights
	vec4 param1;	// x = lightType, y = inner angle, z = outer angle, w = TBD
	                // 0 = pointlight
					// 1 = spot light
					// 2 = directional light
	vec4 param2;	// x = 0 for off, 1 for on
};

const int POINT_LIGHT_TYPE = 0;
const int SPOT_LIGHT_TYPE = 1;
const int DIRECTIONAL_LIGHT_TYPE = 2;

//const int NUMBEROFLIGHTS = 10;
const int NUMBEROFLIGHTS = 2;
uniform sLight theLights[NUMBEROFLIGHTS];  	// 80 uniforms

// Really appears as:
// uniform vec4 theLights[0].position
// uniform vec4 theLights[0].diffuse
// uniform vec4 theLights[0].specular
// uniform vec4 theLights[0].atten
// uniform vec4 theLights[0].direction
// uniform vec4 theLights[0].param1
// uniform vec4 theLights[0].param2

vec4 calcualteLightContrib( vec3 vertexMaterialColour, vec3 vertexNormal, 
                            vec3 vertexWorldPos, vec4 vertexSpecular );

float plot (vec2 st, float pct){
  return  smoothstep( pct-0.01, pct, st.y) -
          smoothstep( pct, pct+0.01, st.y);
}
	 
void main()  
{
	// What pass is this?
	// Is it the 2nd pass?
	if ( passNumber == 1)
	{
		//pixelColour = vec4(0.0f, 1.0f, 0.0f, 1.0f);
		float bo = 0.01f;		// For "blurr offset"
		
		// *  *  *
		// *  O  *
		// *  *  *
		
		// This is a Gaussian Kernel (Goo
		// * * * * *          *
		// * * * * *          *
		// * * O * *		**O**
		// * * * * *          *
		// * * * * *          *
		
		vec3 texRGB1 = texture( secondPassColourTexture, vec2(fUVx2.s + 0.0f, fUVx2.t + 0.0f) ).rgb;
		
		vec3 texRGB2 = texture( secondPassColourTexture, vec2(fUVx2.s - bo, fUVx2.t + 0.0f) ).rgb;
		vec3 texRGB3 = texture( secondPassColourTexture, vec2(fUVx2.s + bo, fUVx2.t + 0.0f) ).rgb;
		vec3 texRGB4 = texture( secondPassColourTexture, vec2(fUVx2.s + 0.0f, fUVx2.t - bo) ).rgb;
		vec3 texRGB5 = texture( secondPassColourTexture, vec2(fUVx2.s + 0.0f, fUVx2.t + bo) ).rgb;
		
		vec3 RGB = 0.5f * texRGB1 +
		           0.125f * texRGB2 +
				   0.125f * texRGB3 +
				   0.125f * texRGB4 +
				   0.125f * texRGB5;

		vec3 texFBO_RGB = texture( secondPassColourTexture, fUVx2.st ).rgb;
		//pixelColour.rgb = texFBO_RGB;
		pixelColour.rgb = RGB;
		pixelColour.a = 1.0f;

		return;
	}

	if ( bDoNotLight )
	{
		pixelColour.rgb = debugColour.rgb;
		pixelColour.a = 1.0f;				// NOT transparent
		return;
	}

	if ( bIsSkyBox )
	{
		// I sample the skybox using the normal from the surface
		vec3 skyColour = texture( skyBox, fNormal.xyz ).rgb;
		pixelColour.rgb = skyColour.rgb;
//		pixelColour.rgb *= 0.01f;
//		pixelColour.rgb = fNormal.xyz;
		pixelColour.a = 1.0f;				// NOT transparent
		
//		pixelColour.rgb *= 1.5f;		// Make it a little brighter
		return;
	}
	
	
	vec4 materialColour = diffuseColour;

	vec3 tex0_RGB = texture( textSamp00, fUVx2.st ).rgb;
	vec3 tex1_RGB = texture( textSamp01, fUVx2.st ).rgb;
	vec3 tex2_RGB = texture( textSamp02, fUVx2.st ).rgb;

	float tex0_ratio = 0.6f;
	float tex1_ratio = 0.4f;
	float tex2_ratio = 0.0f; 

		vec3 texRGB =   ( tex0_ratio * tex0_RGB ) 
				  + ( tex1_ratio * tex1_RGB ) 
				  + ( tex2_ratio * tex2_RGB );

	if (bIsSand)
	{
		vec3 texRGB =   ( 0.6f * tex0_RGB ) 
			+ ( 0.4f * tex1_RGB ) 
			+ ( tex2_ratio * tex2_RGB );
	}

	if (bIsIsland)
	{
		if (fVertWorldLocation.y < seaFloor)
		{
			discard;
		}
		if (fVertWorldLocation.y > 100.0f)
		{
			texRGB = ( 1.0f * tex0_RGB ) 
				  + ( 0.0f * tex1_RGB ) 
				  + ( 0.0f * tex2_RGB );
			
		}
		if (fVertWorldLocation.y < 30.0f)
		{
			texRGB = ( 0.0f * tex0_RGB ) 
				  + ( 0.0f * tex1_RGB ) 
				  + ( 1.0f * tex2_RGB );
		}
		if (fVertWorldLocation.y > 30.0f && fVertWorldLocation.y < 100.0f)
		{
			texRGB = ( 0.0f * tex0_RGB ) 
				  + ( 1.0f * tex1_RGB ) 
				  + ( 0.0f * tex2_RGB );
		}
//		if (fVertWorldLocation.y > 90.0f && fVertWorldLocation.y < 110.0f)
//		{
//			float smoothTransitionLocationY = smoothstep(90.0f, 110.0f, 100.0f);
//			vec4 smoothTransitionLocation = vec3(fVertWorldLocation.x, smoothTransitionLocationY, fVertWorldLocation.z, 1.0f);
//			texRGB = ( 1.0f * tex0_RGB ) 
//				  + ( 0.0f * tex1_RGB ) 
//				  + ( 0.0f * tex2_RGB );
//
//			vec3 rgbTex1 = (1.0f * tex0_RGB);
//			vec3 rgbTex2 = (1.0f * tex1_RGB);
//
//			float smoothTransitionR = smoothstep(rgbTex1.r, rgbTex2.r, 1.0f);
//			float smoothTransitionG = smoothstep(rgbTex1.g, rgbTex2.g, 1.0f);
//			float smoothTransitionB = smoothstep(rgbTex1.b, rgbTex2.b, 1.0f);
//
//			vec3 smoothTransitionColour = vec3(smoothTransitionR, smoothTransitionG, smoothTransitionB);
//
//			vec4 outColour = calcualteLightContrib( smoothTransition, fNormal.xyz, 
//													smoothTransitionLocation, specularColour );
//			pixelColour = outColour;
//
//			pixelColour.a = diffuseColour.a;
//			return;
//			
//		}
	}
	
	if (bIsWater)
	{
		//fVertWorldLocation.y *= (tex1_RGB.r + tex1_RGB.g + tex1_RGB.b) / 10.0f;
		//tex1_RGB.xy += waterOffset;
		vec2 offset = fUVx2.st + waterOffset;

		vec3 tex0_RGB = texture( textSamp00, offset ).rgb;
		vec3 tex1_RGB = texture( textSamp01, offset ).rgb;
		vec3 tex2_RGB = texture( textSamp02, offset ).rgb;


		float tex0_ratio = 0.0f;
		float tex1_ratio = 1.0f;
		float tex2_ratio = 0.0f; 

		vec3 texRGB =   ( tex0_ratio * tex0_RGB ) 
				  + ( tex1_ratio * tex1_RGB ) 
				  + ( tex2_ratio * tex2_RGB );
		vec4 outColour = calcualteLightContrib( texRGB.rgb, fNormal.xyz, 
												fVertWorldLocation.xyz, specularColour );

											
		pixelColour = outColour;

		pixelColour.a = diffuseColour.a;
		return;
	}

//	vec4 materialColour = vec4(1.0f, 1.0f, 1.0f, 1.0f);
//	vec4 specColour = vec4(0.0f,0.0f,0.0f,1.0f);// materialColour;
	

	vec4 outColour = calcualteLightContrib( texRGB.rgb, fNormal.xyz, 
	                                        fVertWorldLocation.xyz, specularColour );

											
	pixelColour = outColour;

	pixelColour.a = diffuseColour.a;

//	if (bIsIsland)
//	{
//		if (fVertWorldLocation.y > 85.0f && fVertWorldLocation.y < 115.0f)
//		{
//			vec2 st = vec2(0.5f);
//			texRGB = ( 1.0f * tex0_RGB ) 
//				  + ( 0.0f * tex1_RGB ) 
//				  + ( 0.0f * tex2_RGB );
//			vec4 outColour1 = calcualteLightContrib( texRGB.rgb, fNormal.xyz, 
//													fVertWorldLocation.xyz, specularColour );
//			
//			texRGB = ( 0.0f * tex0_RGB ) 
//				  + ( 1.0f * tex1_RGB ) 
//				  + ( 0.0f * tex2_RGB );
//			vec4 outColour2 = calcualteLightContrib( texRGB.rgb, fNormal.xyz, 
//										fVertWorldLocation.xyz, specularColour );
//
//			vec4 pct = vec4(st.x);
//			
//			outColour = mix(outColour1, outColour2, pct);
//
//			pixelColour = outColour;
//			pixelColour.a = diffuseColour.a;
//			
//		}
//		if (fVertWorldLocation.y < 30.0f)
//		{
//			texRGB = ( 0.0f * tex0_RGB ) 
//				  + ( 0.0f * tex1_RGB ) 
//				  + ( 1.0f * tex2_RGB );
//		}
//	}
	
//	pixelColour.rgb += vec3(0.5f, 0.5f, 0.5f);
	
//	pixelColour.rgb += fNormal.xyz;
//	pixelColour.rgb += fVertWorldLocation.xyz;
	
}	// Ooops


vec4 calcualteLightContrib( vec3 vertexMaterialColour, vec3 vertexNormal, 
                            vec3 vertexWorldPos, vec4 vertexSpecular )
{
	vec3 norm = normalize(vertexNormal);
	
	vec4 finalObjectColour = vec4( 0.0f, 0.0f, 0.0f, 1.0f );
	
	for ( int index = 0; index < NUMBEROFLIGHTS; index++ )
	{	
		// ********************************************************
		// is light "on"
		if ( theLights[index].param2.x == 0.0f )
		{	// it's off
			continue;
		}
		
		// Cast to an int (note with c'tor)
		int intLightType = int(theLights[index].param1.x);
		
		// We will do the directional light here... 
		// (BEFORE the attenuation, since sunlight has no attenuation, really)
		if ( intLightType == DIRECTIONAL_LIGHT_TYPE )		// = 2
		{
			// This is supposed to simulate sunlight. 
			// SO: 
			// -- There's ONLY direction, no position
			// -- Almost always, there's only 1 of these in a scene
			// Cheapest light to calculate. 

			vec3 lightContrib = theLights[index].diffuse.rgb;
			
			// Get the dot product of the light and normalize
			float dotProduct = dot( -theLights[index].direction.xyz,  
									   normalize(norm.xyz) );	// -1 to 1

			dotProduct = max( 0.0f, dotProduct );		// 0 to 1
		
			lightContrib *= dotProduct;		
			
			finalObjectColour.rgb += (vertexMaterialColour.rgb * theLights[index].diffuse.rgb * lightContrib); 
									 //+ (materialSpecular.rgb * lightSpecularContrib.rgb);
			// NOTE: There isn't any attenuation, like with sunlight.
			// (This is part of the reason directional lights are fast to calculate)


			return finalObjectColour;		
		}
		
		// Assume it's a point light 
		// intLightType = 0
		
		// Contribution for this light
		vec3 vLightToVertex = theLights[index].position.xyz - vertexWorldPos.xyz;
		float distanceToLight = length(vLightToVertex);	
		vec3 lightVector = normalize(vLightToVertex);
		// -1 to 1
		float dotProduct = dot(lightVector, vertexNormal.xyz);	 
		
		// If it's negative, will clamp to 0 --- range from 0 to 1
		dotProduct = max( 0.0f, dotProduct );	
		
		vec3 lightDiffuseContrib = dotProduct * theLights[index].diffuse.rgb;
			

		// Specular 
		vec3 lightSpecularContrib = vec3(0.0f);
			
		vec3 reflectVector = reflect( -lightVector, normalize(norm.xyz) );

		// Get eye or view vector
		// The location of the vertex in the world to your eye
		vec3 eyeVector = normalize(eyeLocation.xyz - vertexWorldPos.xyz);

		// To simplify, we are NOT using the light specular value, just the object’s.
		float objectSpecularPower = vertexSpecular.w; 
		
//		lightSpecularContrib = pow( max(0.0f, dot( eyeVector, reflectVector) ), objectSpecularPower )
//			                   * vertexSpecular.rgb;	//* theLights[lightIndex].Specular.rgb
		lightSpecularContrib = pow( max(0.0f, dot( eyeVector, reflectVector) ), objectSpecularPower )
			                   * theLights[index].specular.rgb;
							   
		// Attenuation
		float attenuation = 1.0f / 
				( theLights[index].atten.x + 										
				  theLights[index].atten.y * distanceToLight +						
				  theLights[index].atten.z * distanceToLight*distanceToLight );  	
				  
		// total light contribution is Diffuse + Specular
		lightDiffuseContrib *= attenuation;
		lightSpecularContrib *= attenuation;
		
		
		// But is it a spot light
		if ( intLightType == SPOT_LIGHT_TYPE )		// = 1
		{	
		

			// Yes, it's a spotlight
			// Calcualate light vector (light to vertex, in world)
			vec3 vertexToLight = vertexWorldPos.xyz - theLights[index].position.xyz;

			vertexToLight = normalize(vertexToLight);

			float currentLightRayAngle
					= dot( vertexToLight.xyz, theLights[index].direction.xyz );
					
			currentLightRayAngle = max(0.0f, currentLightRayAngle);

			//vec4 param1;	
			// x = lightType, y = inner angle, z = outer angle, w = TBD

			// Is this inside the cone? 
			float outerConeAngleCos = cos(radians(theLights[index].param1.z));
			float innerConeAngleCos = cos(radians(theLights[index].param1.y));
							
			// Is it completely outside of the spot?
			if ( currentLightRayAngle < outerConeAngleCos )
			{
				// Nope. so it's in the dark
				lightDiffuseContrib = vec3(0.0f, 0.0f, 0.0f);
				lightSpecularContrib = vec3(0.0f, 0.0f, 0.0f);
			}
			else if ( currentLightRayAngle < innerConeAngleCos )
			{
				// Angle is between the inner and outer cone
				// (this is called the penumbra of the spot light, by the way)
				// 
				// This blends the brightness from full brightness, near the inner cone
				//	to black, near the outter cone
				float penumbraRatio = (currentLightRayAngle - outerConeAngleCos) / 
									  (innerConeAngleCos - outerConeAngleCos);
									  
				lightDiffuseContrib *= penumbraRatio;
				lightSpecularContrib *= penumbraRatio;
			}
						
		}// if ( intLightType == 1 )
		
		
					
		finalObjectColour.rgb += (vertexMaterialColour.rgb * lightDiffuseContrib.rgb)
								  + (vertexSpecular.rgb  * lightSpecularContrib.rgb );

	}//for(intindex=0...
	
	finalObjectColour.a = 1.0f;
	
	return finalObjectColour;
}
