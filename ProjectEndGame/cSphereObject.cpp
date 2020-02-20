#include "cSphereObject.h"

void cSphereObject::Shoot()
{
	this->pShooter->Shoot();
}

std::vector<glm::vec3> cSphereObject::getTestPoints()
{
	return this->testPoints;
}

std::string cSphereObject::getTextures(int index)
{
	return this->textures[index];
}

float cSphereObject::getTextureRatio(int index)
{
	return this->textureRatio[index];
}

float cSphereObject::getTransprancyValue()
{
	return this->transprancyValue;
}

bool cSphereObject::getIsTranspanrancy()
{
	return this->isTranspanrancy;
}

std::string cSphereObject::getBehaviour()
{
	return this->_Behaviour;
}

std::string cSphereObject::getMeshName()
{
	return this->_meshName;
}
unsigned int cSphereObject::getFriendlyIDNumber()
{
	return this->_friendlyIDNumber;
}
std::string cSphereObject::getFriendlyName()
{
	return this->_friendlyName;
}
glm::vec3 cSphereObject::getPositionXYZ()
{
	return this->_positionXYZ;
}
glm::quat cSphereObject::getRotationXYZ()
{
	return this->qRotation;
}
float cSphereObject::getScale()
{
	return this->_scale;
}
glm::mat4 cSphereObject::getMatWorld()
{
	return this->_matWorld;
}
glm::vec4 cSphereObject::getObjectColourRGBA()
{
	return this->_objectColourRGBA;
}
glm::vec4 cSphereObject::getDiffuseColour()
{
	return this->_diffuseColour;
}
glm::vec4 cSphereObject::getSpecularColour()
{
	return this->_specularColour;
}
glm::vec3 cSphereObject::getVelocity()
{
	return this->_velocity;
}
float cSphereObject::getVelocityX()
{
	return this->_velocityX;
}
float cSphereObject::getVelocityY()
{
	return this->_velocityY;
}
float cSphereObject::getVelocityZ()
{
	return this->_velocityZ;
}
glm::vec3 cSphereObject::getAccel()
{
	return this->_accel;
}
float cSphereObject::getInverseMass()
{
	return this->_inverseMass;
}
std::string cSphereObject::getPhysicsShapeType()
{
	return this->_physicsShapeType;
}
bool cSphereObject::getIsWireframe()
{
	return this->_isWireframe;
}
glm::vec4 cSphereObject::getDebugColour()
{
	return this->_debugColour;
}
float cSphereObject::get_SPHERE_radius()
{
	return this->_SPHERE_radius;
}
bool cSphereObject::getIsVisible()
{
	return this->_isVisible;
}
bool cSphereObject::getDisableDepthBufferTest()
{
	return this->_disableDepthBufferTest;
}
bool cSphereObject::getDisableDepthBufferWrite()
{
	return this->_disableDepthBufferWrite;
}
//setters

void cSphereObject::addTestPoint(glm::vec3 testPoint)
{
	this->testPoints.push_back(testPoint);
}
void cSphereObject::setBehaviour(std::string behaviour)
{
	this->_Behaviour = behaviour;
}
void cSphereObject::setMeshName(std::string name)
{
	this->_meshName = name;
}
void cSphereObject::setFriendlyIDNumber(unsigned int IDNumber)
{
	this->_friendlyIDNumber = IDNumber;
}
void cSphereObject::setFriendlyName(std::string friendlyName)
{
	this->_friendlyName = friendlyName;
}
void cSphereObject::setPositionXYZ(glm::vec3 positionXYZ)
{
	this->_positionXYZ = positionXYZ;
}
void cSphereObject::setRotationXYZ(glm::quat rotationXYZ)
{
	this->qRotation = rotationXYZ;
}
void cSphereObject::setScale(float scale)
{
	this->_scale = scale;
}
void cSphereObject::setMatWorld(glm::mat4 matWorld)
{
	this->_matWorld = matWorld;
}
void cSphereObject::setObjectColourRGBA(glm::vec4 colourRGBA)
{
	this->_objectColourRGBA = colourRGBA;
}
void cSphereObject::setDiffuseColour(glm::vec4 diffuseColourRGBA)
{
	this->_diffuseColour = diffuseColourRGBA;
}
void cSphereObject::setSpecularColour(glm::vec4 specularColourRGBA)
{
	this->_specularColour = specularColourRGBA;
}
void cSphereObject::setVelocity(glm::vec3 velocityXYZ)
{
	this->_velocity = velocityXYZ;
}
void cSphereObject::setVelocityX(float velocityX)
{
	this->_velocityX = velocityX;
}
void cSphereObject::setVelocityY(float velocityY)
{
	this->_velocityY = velocityY;
}
void cSphereObject::setVelocityZ(float velocityZ)
{
	this->_velocityZ = velocityZ;
}
void cSphereObject::setAccel(glm::vec3 accelXYZ)
{
	this->_accel = accelXYZ;
}
void cSphereObject::setInverseMass(float inverseMass)
{
	this->_inverseMass = inverseMass;
}
void cSphereObject::setPhysicsShapeType(std::string physicsShapeType)
{
	this->_physicsShapeType = physicsShapeType;
}
void cSphereObject::setIsWireframe(bool isWireFrame)
{
	this->_isWireframe = isWireFrame;
}
void cSphereObject::setDebugColour(glm::vec4 debugColourRGBA)
{
	this->_debugColour = debugColourRGBA;
}
void cSphereObject::set_SPHERE_radius(float radius)
{
	this->_SPHERE_radius = radius;
}
void cSphereObject::setIsVisible(bool isVisible)
{
	this->_isVisible = isVisible;
}
void cSphereObject::setDisableDepthBufferTest(bool disableDepthBufferTest)
{
	this->_disableDepthBufferTest = disableDepthBufferTest;
}
void cSphereObject::setDisableDepthBufferWrite(bool disableDepthBufferWrite)
{
	this->_disableDepthBufferWrite = disableDepthBufferWrite;
}

cSphereObject::cSphereObject()
{
	this->_scale = 0.0f;
	this->_isVisible = true;

	this->_isWireframe = false;
	this->_debugColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	this->_velocity = glm::vec3(0.0f, 0.0f, 0.0f);
	this->_accel = glm::vec3(0.0f, 0.0f, 0.0f);
	this->_inverseMass = 0.0f;	// Infinite mass
	this->_physicsShapeType = "UNKNOWN";

	// Set the unique ID
	// Take the value of the static int, 
	//  set this to the instance variable
	this->_m_uniqueID = cSphereObject::next_uniqueID;
	// Then increment the static variable
	cSphereObject::next_uniqueID++;

	this->_disableDepthBufferTest = false;
	this->_disableDepthBufferWrite = false;


	return;
}

void cSphereObject::MoveInRelativeDirection(glm::vec3 relativeDirection)
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

void cSphereObject::setTexture(std::string tex, int index)
{
	this->textures[index] = tex;
}

void cSphereObject::setTextureRatio(float texRatio, int index)
{
	this->textureRatio[index] = texRatio;
}

void cSphereObject::setTransprancyValue(float transprancyValue)
{
	this->transprancyValue = transprancyValue;
}

void cSphereObject::setIsTranspanrancy(bool isTranspanrancy)
{
	this->isTranspanrancy = isTranspanrancy;
}

//void cSphereObject::MoveInRelativeDirection(glm::vec3 relativeDirection)
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

unsigned int cSphereObject::getUniqueID(void)
{
	return this->_m_uniqueID;
}

// this variable is static, so common to all objects.
// When the object is created, the unique ID is set, and 
//	the next unique ID is incremented
//static 
unsigned int cSphereObject::next_uniqueID = 1000;	// Starting at 1000, just because
