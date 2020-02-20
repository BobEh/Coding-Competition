#include "cPhysics.h"
#include "AABBStuff.h"
#include <iostream>

cPhysics::cPhysics()
{
	// This is a typical Earth gravity value. 
	// note that this doesn't mean that the simulation will "look good", though... 
	this->m_Gravity = glm::vec3(0.0f, -9.81f, 0.0f);
	return;
}


void cPhysics::setGravity(glm::vec3 newGravityValue)
{
	this->m_Gravity = newGravityValue;
	return;
}

glm::vec3 cPhysics::getGravity(void)
{
	return this->m_Gravity;
}


void cPhysics::IntegrationStep(std::vector<iObject*>& vec_pGameObjects, float deltaTime)
{


	for (unsigned int index = 0; index != vec_pGameObjects.size(); index++)
	{
		// Get a pointer to the current object (makes the code a little clearer)
		iObject* pCurObj = vec_pGameObjects[index];

		if (pCurObj->getInverseMass() != 0.0f)
		{
			if (pCurObj->getInverseMass() != 0.0f)
			{

				// Forward Explicit Euler Inetegration
				//NewVelocty += Velocity + ( Ax * DeltaTime )

				// 
				//pCurObj->setAccel(this->m_Gravity);


				pCurObj->setVelocity(pCurObj->getVelocity() + pCurObj->getAccel() * deltaTime);
				//		// Or you can do this...
				//		CurObj.velocity += CurObj.accel * deltaTime;

						//NewPosition = Posistion + ( Vx * DeltaTime )

				pCurObj->MoveInRelativeDirection(pCurObj->getVelocity() * deltaTime);
				//pCurObj->setPositionXYZ(pCurObj->getPositionXYZ() + pCurObj->getVelocity() * deltaTime);


			}
			// Forward Explicit Euler Inetegration
			//NewVelocty += Velocity + ( Ax * DeltaTime )

			// 
			//pCurObj->setAccel(this->m_Gravity);


			//pCurObj->setVelocity(pCurObj->getVelocity() + pCurObj->getAccel() * deltaTime);
			//pCurObj->MoveInRelativeDirection(pCurObj->getVelocity() * deltaTime);
			//		// Or you can do this...
			//		CurObj.velocity += CurObj.accel * deltaTime;

					//NewPosition = Posistion + ( Vx * DeltaTime )

			//glm::mat4 matModel = glm::mat4(1.0f);

			//glm::mat4 translation = glm::translate(glm::mat4(1.0f), pCurObj->getPositionXYZ());

			//matModel *= translation;

			//glm::vec4 testPointInModel = matModel * glm::vec4(pCurObj->getPositionXYZ(), 1.0f);

			//pCurObj->setPositionXYZ(pCurObj->getPositionXYZ() + pCurObj->getVelocity() * deltaTime);
			//pCurObj->MoveInRelativeDirection(pCurObj->getPositionXYZ() + pCurObj->getVelocity() * deltaTime);
			
		}

		if (pCurObj->getVelocity().x > 0.0f)
		{
			if (pCurObj->getAccel().x < 0.0f)
				pCurObj->setAccel(glm::vec3(0.0f, pCurObj->getAccel().y, pCurObj->getAccel().z));

			pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x - 0.1f, pCurObj->getAccel().y, pCurObj->getAccel().z));
			pCurObj->setVelocity(glm::vec3(pCurObj->getVelocity().x - 0.1f, pCurObj->getVelocity().y, pCurObj->getVelocity().z));
		}
		//if (pCurObj->getVelocity().y > 0.0f)
		//{
		//	if (pCurObj->getAccel().y < 0.0f)
		//		pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, 0.0f, pCurObj->getAccel().z));

		//	pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, pCurObj->getAccel().y - 0.1f, pCurObj->getAccel().z));
		//	pCurObj->setVelocity(glm::vec3(pCurObj->getVelocity().x, pCurObj->getVelocity().y - 0.1f, pCurObj->getVelocity().z));
		//}
		if (pCurObj->getVelocity().z > 0.0f)
		{
			if (pCurObj->getAccel().z < 0.0f)
				pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, pCurObj->getAccel().y, 0.0f));

			pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, pCurObj->getAccel().y, pCurObj->getAccel().z - 0.1f));
			pCurObj->setVelocity(glm::vec3(pCurObj->getVelocity().x, pCurObj->getVelocity().y, pCurObj->getVelocity().z - 0.1f));
		}


		if (pCurObj->getVelocity().x < 0.0f)
		{
			if (pCurObj->getAccel().x > 0.0f)
			{
				pCurObj->setAccel(glm::vec3(0.0f, pCurObj->getAccel().y, pCurObj->getAccel().z));
				//pCurObj->setVelocity(glm::vec3(0.0f, pCurObj->getVelocity().y, pCurObj->getVelocity().z));
			}
			pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x + 0.1f, pCurObj->getAccel().y, pCurObj->getAccel().z));
			pCurObj->setVelocity(glm::vec3(pCurObj->getVelocity().x + 0.1f, pCurObj->getVelocity().y, pCurObj->getVelocity().z));
		}
		//if (pCurObj->getVelocity().y < 0.0f)
		//{
		//	if (pCurObj->getAccel().y > 0.0f)
		//		pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, 0.0f, pCurObj->getAccel().z));

		//	pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, pCurObj->getAccel().y + 0.1f, pCurObj->getAccel().z));
		//	pCurObj->setVelocity(glm::vec3(pCurObj->getVelocity().x, pCurObj->getVelocity().y + 0.1f, pCurObj->getVelocity().z));
		//}
		if (pCurObj->getVelocity().z < 0.0f)
		{
			if (pCurObj->getAccel().z > 0.0f)
				pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, pCurObj->getAccel().y, 0.0f));

			pCurObj->setAccel(glm::vec3(pCurObj->getAccel().x, pCurObj->getAccel().y, pCurObj->getAccel().z + 0.1f));
			pCurObj->setVelocity(glm::vec3(pCurObj->getVelocity().x, pCurObj->getVelocity().y, pCurObj->getVelocity().z + 0.1f));
		}

	}//for (unsigned int index = 0;

	return;
}



// Returns all the triangles and the closest points
void cPhysics::GetClosestTriangleToPoint(Point pointXYZ, cMesh& mesh, glm::vec3& closestPoint, sPhysicsTriangle& closestTriangle)
{

	// Assume the closest distance is REALLY far away
	float closestDistanceSoFar = FLT_MAX;


	for (unsigned int triIndex = 0; triIndex != mesh.vecTriangles.size(); triIndex++)
	{
		sPlyTriangle& curTriangle = mesh.vecTriangles[triIndex];

		// Get the vertices of the triangle
		sPlyVertexXYZ_N_UV triVert1 = mesh.vecVertices[curTriangle.vert_index_1];
		sPlyVertexXYZ_N_UV triVert2 = mesh.vecVertices[curTriangle.vert_index_2];
		sPlyVertexXYZ_N_UV triVert3 = mesh.vecVertices[curTriangle.vert_index_3];

		Point triVertPoint1;
		triVertPoint1.x = triVert1.x;
		triVertPoint1.y = triVert1.y;
		triVertPoint1.z = triVert1.z;

		Point triVertPoint2;
		triVertPoint2.x = triVert2.x;
		triVertPoint2.y = triVert2.y;
		triVertPoint2.z = triVert2.z;

		Point triVertPoint3;
		triVertPoint3.x = triVert3.x;
		triVertPoint3.y = triVert3.y;
		triVertPoint3.z = triVert3.z;

		glm::vec3 curClosetPoint = ClosestPtPointTriangle( pointXYZ, triVertPoint1, triVertPoint2, triVertPoint3);

		// Is this the closest so far?
		float distanceNow = glm::distance(curClosetPoint, pointXYZ);

		// is this closer than the closest distance
		if (distanceNow <= closestDistanceSoFar)
		{
			closestDistanceSoFar = distanceNow;

			closestPoint = curClosetPoint;

			// Copy the triangle information over, as well
			closestTriangle.verts[0].x = triVert1.x;
			closestTriangle.verts[0].y = triVert1.y;
			closestTriangle.verts[0].z = triVert1.z;
			closestTriangle.verts[1].x = triVert2.x;
			closestTriangle.verts[1].y = triVert2.y;
			closestTriangle.verts[1].z = triVert2.z;
			closestTriangle.verts[2].x = triVert3.x;
			closestTriangle.verts[2].y = triVert3.y;
			closestTriangle.verts[2].z = triVert3.z;

			// TODO: Copy the normal, too	
			// Quick is to average the normal of all 3 vertices
			glm::vec3 triVert1Norm = glm::vec3(triVert1.nx, triVert1.ny, triVert1.nz);
			glm::vec3 triVert2Norm = glm::vec3(triVert2.nx, triVert2.ny, triVert2.nz);
			glm::vec3 triVert3Norm = glm::vec3(triVert3.nx, triVert3.ny, triVert3.nz);

			// Average of the vertex normals... 
			closestTriangle.normal = (triVert1Norm + triVert2Norm + triVert3Norm) / 3.0f;

		}

	}//for (unsigned int triIndex = 0;

	return;
}
void cPhysics::GetClosestTriangleToPoint(Point pointXYZ, cMesh* mesh, cAABB* currentAABB, glm::vec3& closestPoint, sPhysicsTriangle& closestTriangle)
{
	// Assume the closest distance is REALLY far away
	float closestDistanceSoFar = FLT_MAX;

	int numLoops = 0;

	for (unsigned int triIndex = 0; triIndex != currentAABB->vecTriangles.size(); triIndex++)
	{
		sPlyTriangle& curTriangle = *currentAABB->vecTriangles[triIndex];

		// Get the vertices of the triangle
		sPlyVertexXYZ_N_UV triVert1 = mesh->vecVertices[curTriangle.vert_index_1];
		sPlyVertexXYZ_N_UV triVert2 = mesh->vecVertices[curTriangle.vert_index_2];
		sPlyVertexXYZ_N_UV triVert3 = mesh->vecVertices[curTriangle.vert_index_3];

		//sPlyVertexXYZ_N triVert1 = currentAABB->triPosition.at(triIndex);
		//sPlyVertexXYZ_N triVert2 = currentAABB->triPosition.at(triIndex);
		//sPlyVertexXYZ_N triVert3 = currentAABB->triPosition.at(triIndex);

		//glm::vec3 triVert1 = currentAABB->triXPosition.at(triIndex);
		//glm::vec3 triVert2 = currentAABB->triYPosition.at(triIndex);
		//glm::vec3 triVert3 = currentAABB->triZPosition.at(triIndex);

		//sPlyVertexXYZ_N triVert1 = currentAABB->triLocation.pointX;
		//sPlyVertexXYZ_N triVert2 = currentAABB->triLocation.pointY;
		//sPlyVertexXYZ_N triVert3 = currentAABB->triLocation.pointZ;

		Point triVertPoint1;
		triVertPoint1.x = triVert1.x;
		triVertPoint1.y = triVert1.y;
		triVertPoint1.z = triVert1.z;

		Point triVertPoint2;
		triVertPoint2.x = triVert2.x;
		triVertPoint2.y = triVert2.y;
		triVertPoint2.z = triVert2.z;

		Point triVertPoint3;
		triVertPoint3.x = triVert3.x;
		triVertPoint3.y = triVert3.y;
		triVertPoint3.z = triVert3.z;

		glm::vec3 curClosetPoint = ClosestPtPointTriangle(pointXYZ, triVertPoint1, triVertPoint2, triVertPoint3);

		// Is this the closest so far?
		float distanceNow = glm::distance(curClosetPoint, pointXYZ);

		// is this closer than the closest distance
		if (distanceNow <= closestDistanceSoFar)
		{
			closestDistanceSoFar = distanceNow;

			closestPoint = curClosetPoint;

			// Copy the triangle information over, as well
			closestTriangle.verts[0].x = triVert1.x;
			closestTriangle.verts[0].y = triVert1.y;
			closestTriangle.verts[0].z = triVert1.z;
			closestTriangle.verts[1].x = triVert2.x;
			closestTriangle.verts[1].y = triVert2.y;
			closestTriangle.verts[1].z = triVert2.z;
			closestTriangle.verts[2].x = triVert3.x;
			closestTriangle.verts[2].y = triVert3.y;
			closestTriangle.verts[2].z = triVert3.z;

			glm::vec3 triVert1Norm = glm::vec3(triVert1.nx, triVert1.ny, triVert1.nz);
			glm::vec3 triVert2Norm = glm::vec3(triVert2.nx, triVert2.ny, triVert2.nz);
			glm::vec3 triVert3Norm = glm::vec3(triVert3.nx, triVert3.ny, triVert3.nz);

			// Average of the vertex normals... 
 			closestTriangle.normal = (triVert1Norm + triVert2Norm + triVert3Norm) / 3.0f;

		}
		//numLoops++;
	}//for (unsigned int triIndex = 0;
	//std::cout << numLoops << std::endl;
	return;
}

// Will return the closest triangles that are within the range "distanceRange".
// This can be used as a "closest triangles to sphere"
void cPhysics::GetClosestTrianglesToSphere(iObject& testSphere, float distanceRange, cMesh& mesh, std::vector<sPhysicsTriangle>& vecClosestTriangles)
{



}

// Test each object with every other object
void cPhysics::TestForCollisions(std::vector<iObject*>& vec_pGameObjects)
{
	// This will store all the collisions in this frame
	std::vector<sCollisionInfo> vecCollisions;

	sCollisionInfo collisionInfo;

	for (unsigned int outerLoopIndex = 0;
		 outerLoopIndex != vec_pGameObjects.size(); outerLoopIndex++)
	{
		for (unsigned int innerLoopIndex = 0;
			 innerLoopIndex != vec_pGameObjects.size(); innerLoopIndex++)
		{ 
			iObject* pA = vec_pGameObjects[outerLoopIndex];
			iObject* pB = vec_pGameObjects[innerLoopIndex];
			if ( pA->getUniqueID() == pB->getUniqueID() )
			{	
				// It's the same object
				// Do nothing
			}
			else if (pA->getPhysicsShapeType() == "SPHERE" && pB->getPhysicsShapeType() == "SPHERE")
			{
				if (DoSphereSphereCollisionTest(pA, pB, collisionInfo))
				{
					vecCollisions.push_back(collisionInfo);
				}
			}
			else if (pA->getPhysicsShapeType() == "SPHERE" && pB->getPhysicsShapeType() == "MESH")
			{
				if (DoShphereMeshCollisionTest(pA, pB, collisionInfo))
				{
					vecCollisions.push_back(collisionInfo);
				}
			}
		
		
		}//for (unsigned int innerLoopIndex = 0;
	}//for (unsigned int outerLoopIndex = 0;

}

bool cPhysics::DoSphereSphereCollisionTest(iObject* pA, iObject* pB, sCollisionInfo& collisionInfo)
{
	// TODO: 
	// Run the sphere-sphere collision test
	// If collided, load the collisionInfo struct and return true
	// else return false;

	return false;
}
bool cPhysics::DoShphereMeshCollisionTest(iObject* pA, iObject* pB,	sCollisionInfo& collisionInfo)
{
	// TODO: Do the sphere-Mesh collision test
	// If collided, load the collisionInfo struct and return true
	//  else return false


	return true;
}

// Takes a mesh in "model space" and converts it into "world space"
void cPhysics::CalculateTransformedMesh(cMesh& originalMesh, glm::mat4 matWorld, cMesh& mesh_transformedInWorld)
{
	// Make a copy of the mesh...

	mesh_transformedInWorld = originalMesh;

	// Using the same thing that happens in the shader, 
	// we transform the vertices of the mesh by the world matrix
	// 
	// From the vertex shader:
	// fVertWorldLocation = matModel * vec4(vertPosition.xyz, 1.0);
	//

	for (std::vector<sPlyVertexXYZ_N_UV>::iterator itVert = mesh_transformedInWorld.vecVertices.begin();
		itVert != mesh_transformedInWorld.vecVertices.end(); itVert++)
	{
		glm::vec4 vertex = glm::vec4(itVert->x, itVert->y, itVert->z, 1.0f);

		// boom goes the dynamite
		// https://www.youtube.com/watch?v=W45DRy7M1no
		glm::vec4 vertexWorldTransformed = matWorld * vertex;

		// Update 
		itVert->x = vertexWorldTransformed.x;
		itVert->y = vertexWorldTransformed.y;
		itVert->z = vertexWorldTransformed.z;


		// CALCAULTE THE NORMALS for the this mesh, too (for the response)
		// for the normal, do the inverse transpose of the world matrix
		glm::mat4 matWorld_Inv_Transp = glm::inverse(glm::transpose(matWorld));


		glm::vec4 normal = glm::vec4(itVert->nx, itVert->ny, itVert->nz, 1.0f);

		// boom goes the dynamite
		// https://www.youtube.com/watch?v=W45DRy7M1no
		glm::vec4 normalWorldTransformed = matWorld_Inv_Transp * normal;


		// Update 
		itVert->nx = normalWorldTransformed.x;
		itVert->ny = normalWorldTransformed.y;
		itVert->nz = normalWorldTransformed.z;
	}

	return;
}
