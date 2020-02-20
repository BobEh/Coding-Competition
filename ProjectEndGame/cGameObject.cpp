#include "cGameObject.h"

std::string cGameObject::getBehaviour()
{
	return std::string();
}

std::string cGameObject::getMeshName()
{
	return this->_meshName;
}
std::vector<glm::vec3> cGameObject::getTestPoints()
{
	return this->testPoints;
}
std::string cGameObject::getTextures(int index)
{
	return this->textures[index];
}
float cGameObject::getTextureRatio(int index)
{
	return this->textureRatio[index];
}
float cGameObject::getTransprancyValue()
{
	return this->transprancyValue;
}
bool cGameObject::getIsTranspanrancy()
{
	return this->isTranspanrancy;
}
unsigned int cGameObject::getFriendlyIDNumber()
{
	return this->_friendlyIDNumber;
}
std::string cGameObject::getFriendlyName()
{
	return this->_friendlyName;
}
glm::vec3 cGameObject::getPositionXYZ()
{
	return this->_positionXYZ;
}
glm::quat cGameObject::getRotationXYZ()
{
	return this->qRotation;
}
float cGameObject::getScale()
{
	return this->_scale;
}
glm::mat4 cGameObject::getMatWorld()
{
	return this->_matWorld;
}
glm::vec4 cGameObject::getObjectColourRGBA()
{
	return this->_objectColourRGBA;
}
glm::vec4 cGameObject::getDiffuseColour()
{
	return this->_diffuseColour;
}
glm::vec4 cGameObject::getSpecularColour()
{
	return this->_specularColour;
}
glm::vec3 cGameObject::getVelocity()
{
	return this->_velocity;
}
float cGameObject::getVelocityX()
{
	return this->_velocityX;
}
float cGameObject::getVelocityY()
{
	return this->_velocityY;
}
float cGameObject::getVelocityZ()
{
	return this->_velocityZ;
}
glm::vec3 cGameObject::getAccel()
{
	return this->_accel;
}
float cGameObject::getInverseMass()
{
	return this->_inverseMass;
}
std::string cGameObject::getPhysicsShapeType()
{
	return this->_physicsShapeType;
}
bool cGameObject::getIsWireframe()
{
	return this->_isWireframe;
}
glm::vec4 cGameObject::getDebugColour()
{
	return this->_debugColour;
}
float cGameObject::get_SPHERE_radius()
{
	return this->_SPHERE_radius;
}
bool cGameObject::getIsVisible()
{
	return this->_isVisible;
}
bool cGameObject::getDisableDepthBufferTest()
{
	return this->_disableDepthBufferTest;
}
bool cGameObject::getDisableDepthBufferWrite()
{
	return this->_disableDepthBufferWrite;
}
//setters

void cGameObject::addTestPoint(glm::vec3 testPoint)
{
	
}
void cGameObject::setBehaviour(std::string behaviour)
{
}
void cGameObject::setMeshName(std::string name)
{
	this->_meshName = name;
}
void cGameObject::setFriendlyIDNumber(unsigned int IDNumber)
{
	this->_friendlyIDNumber = IDNumber;
}
void cGameObject::setFriendlyName(std::string friendlyName)
{
	this->_friendlyName = friendlyName;
}
void cGameObject::setPositionXYZ(glm::vec3 positionXYZ)
{
	this->_positionXYZ = positionXYZ;
}
void cGameObject::setRotationXYZ(glm::quat rotationXYZ)
{
	this->qRotation = rotationXYZ;
}
void cGameObject::setScale(float scale)
{
	this->_scale = scale;
}
void cGameObject::setMatWorld(glm::mat4 matWorld)
{
	this->_matWorld = matWorld;
}
void cGameObject::setObjectColourRGBA(glm::vec4 colourRGBA)
{
	this->_objectColourRGBA = colourRGBA;
}
void cGameObject::setDiffuseColour(glm::vec4 diffuseColourRGBA)
{
	this->_diffuseColour = diffuseColourRGBA;
}
void cGameObject::setSpecularColour(glm::vec4 specularColourRGBA)
{
	this->_specularColour = specularColourRGBA;
}
void cGameObject::setVelocity(glm::vec3 velocityXYZ)
{
	this->_velocity = velocityXYZ;
}
void cGameObject::setVelocityX(float velocityX)
{
	this->_velocityX = velocityX;
}
void cGameObject::setVelocityY(float velocityY)
{
	this->_velocityY = velocityY;
}
void cGameObject::setVelocityZ(float velocityZ)
{
	this->_velocityZ = velocityZ;
}
void cGameObject::setAccel(glm::vec3 accelXYZ)
{
	this->_accel = accelXYZ;
}
void cGameObject::setInverseMass(float inverseMass)
{
	this->_inverseMass = inverseMass;
}
void cGameObject::setPhysicsShapeType(std::string physicsShapeType)
{
	this->_physicsShapeType = physicsShapeType;
}
void cGameObject::setIsWireframe(bool isWireFrame)
{
	this->_isWireframe = isWireFrame;
}
void cGameObject::setDebugColour(glm::vec4 debugColourRGBA)
{
	this->_debugColour = debugColourRGBA;
}
void cGameObject::set_SPHERE_radius(float radius)
{
	this->_SPHERE_radius = radius;
}
void cGameObject::setIsVisible(bool isVisible)
{
	this->_isVisible = isVisible;
}
void cGameObject::setDisableDepthBufferTest(bool disableDepthBufferTest)
{
	this->_disableDepthBufferTest = disableDepthBufferTest;
}
void cGameObject::setDisableDepthBufferWrite(bool disableDepthBufferWrite)
{
	this->_disableDepthBufferWrite = disableDepthBufferWrite;
}

cGameObject::cGameObject()
{
	this->_scale = 0.0f;
	this->_isVisible = true;

	this->_isWireframe = false;
	this->_debugColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	this->_velocity = glm::vec3(0.0f,0.0f,0.0f);
	this->_accel = glm::vec3(0.0f,0.0f,0.0f);
	this->_inverseMass = 0.0f;	// Infinite mass
	this->_physicsShapeType = "UNKNOWN";

	// Set the unique ID
	// Take the value of the static int, 
	//  set this to the instance variable
	this->_m_uniqueID = cGameObject::next_uniqueID;
	// Then increment the static variable
	cGameObject::next_uniqueID++;

	this->_disableDepthBufferTest = false;
	this->_disableDepthBufferWrite = false;


	return;
}

void cGameObject::MoveInRelativeDirection(glm::vec3 relativeDirection)
{
	// The "forward" vector is +ve Z
	// (the 4th number is because we need a vec4 later)
	glm::vec4 forwardDirObject = glm::vec4(relativeDirection, 1.0f);

	glm::mat4 matModel = glm::mat4(1.0f);	// Identity

	// Roation
	// Constructor for the GLM mat4x4 can take a quaternion
	glm::mat4 matRotation = glm::mat4(this->getRotationXYZ());
	matModel *= matRotation;
	// *******************

	// Like in the vertex shader, I mulitly the test points
	// by the model matrix (MUST be a VEC4 because it's a 4x4 matrix)
	glm::vec4 forwardInWorldSpace = matModel * forwardDirObject;


	// Add this to the position of the object
	this->setPositionXYZ(this->getPositionXYZ() + glm::vec3(forwardInWorldSpace));

	return;
}

void cGameObject::setTexture(std::string tex, int index)
{
	this->textures[index] = tex;
}

void cGameObject::setTextureRatio(float texRatio, int index)
{
	this->textureRatio[index] = texRatio;
}

void cGameObject::setTransprancyValue(float transprancyValue)
{
	this->transprancyValue = transprancyValue;
}

void cGameObject::setIsTranspanrancy(bool isTranspanrancy)
{
	this->isTranspanrancy = isTranspanrancy;
}

//void cGameObject::MoveInRelativeDirection(glm::vec3 relativeDirection)
//{
//	// The "forward" vector is +ve Z
//	// (the 4th number is because we need a vec4 later)
//	glm::vec4 forwardDirObject = glm::vec4(relativeDirection, 1.0f);
//
//	glm::mat4 matModel = glm::mat4(1.0f);	// Identity
//
//	// Roation
//	// Constructor for the GLM mat4x4 can take a quaternion
//	glm::mat4 matRotation = glm::mat4(this->getRotationXYZ());
//	matModel *= matRotation;
//	// *******************
//
//	// Like in the vertex shader, I mulitly the test points
//	// by the model matrix (MUST be a VEC4 because it's a 4x4 matrix)
//	glm::vec4 forwardInWorldSpace = matModel * forwardDirObject;
//
//
//	// Add this to the position of the object
//	this->setPositionXYZ(this->getPositionXYZ() + glm::vec3(forwardInWorldSpace));
//
//	return;
//}


unsigned int cGameObject::getUniqueID(void)
{
	return this->_m_uniqueID;
}

// this variable is static, so common to all objects.
// When the object is created, the unique ID is set, and 
//	the next unique ID is incremented
//static 
unsigned int cGameObject::next_uniqueID = 1000;	// Starting at 1000, just because
