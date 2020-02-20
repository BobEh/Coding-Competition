#include "cTestObject.h"

std::string cTestObject::getMeshName()
{
	return this->_meshName;
}
unsigned int cTestObject::getFriendlyIDNumber()
{
	return this->_friendlyIDNumber;
}
std::string cTestObject::getFriendlyName()
{
	return this->_friendlyName;
}
glm::vec3 cTestObject::getPositionXYZ()
{
	return this->_positionXYZ;
}
glm::quat cTestObject::getRotationXYZ()
{
	return this->qRotation;
}
float cTestObject::getScale()
{
	return this->_scale;
}
glm::mat4 cTestObject::getMatWorld()
{
	return this->_matWorld;
}
glm::vec4 cTestObject::getObjectColourRGBA()
{
	return this->_objectColourRGBA;
}
glm::vec4 cTestObject::getDiffuseColour()
{
	return this->_diffuseColour;
}
glm::vec4 cTestObject::getSpecularColour()
{
	return this->_specularColour;
}
glm::vec3 cTestObject::getVelocity()
{
	return this->_velocity;
}
float cTestObject::getVelocityX()
{
	return this->_velocityX;
}
float cTestObject::getVelocityY()
{
	return this->_velocityY;
}
float cTestObject::getVelocityZ()
{
	return this->_velocityZ;
}
glm::vec3 cTestObject::getAccel()
{
	return this->_accel;
}
float cTestObject::getInverseMass()
{
	return this->_inverseMass;
}
std::string cTestObject::getPhysicsShapeType()
{
	return this->_physicsShapeType;
}
bool cTestObject::getIsWireframe()
{
	return this->_isWireframe;
}
glm::vec4 cTestObject::getDebugColour()
{
	return this->_debugColour;
}
float cTestObject::get_SPHERE_radius()
{
	return this->_SPHERE_radius;
}
bool cTestObject::getIsVisible()
{
	return this->_isVisible;
}
bool cTestObject::getDisableDepthBufferTest()
{
	return this->_disableDepthBufferTest;
}
bool cTestObject::getDisableDepthBufferWrite()
{
	return this->_disableDepthBufferWrite;
}
//setters
void cTestObject::setMeshName(std::string name)
{
	this->_meshName = name;
}
void cTestObject::setFriendlyIDNumber(unsigned int IDNumber)
{
	this->_friendlyIDNumber = IDNumber;
}
void cTestObject::setFriendlyName(std::string friendlyName)
{
	this->_friendlyName = friendlyName;
}
void cTestObject::setPositionXYZ(glm::vec3 positionXYZ)
{
	this->_positionXYZ = positionXYZ;
}
void cTestObject::setRotationXYZ(glm::quat rotationXYZ)
{
	this->qRotation = rotationXYZ;
}
void cTestObject::setScale(float scale)
{
	this->_scale = scale;
}
void cTestObject::setMatWorld(glm::mat4 matWorld)
{
	this->_matWorld = matWorld;
}
void cTestObject::setObjectColourRGBA(glm::vec4 colourRGBA)
{
	this->_objectColourRGBA = colourRGBA;
}
void cTestObject::setDiffuseColour(glm::vec4 diffuseColourRGBA)
{
	this->_diffuseColour = diffuseColourRGBA;
}
void cTestObject::setSpecularColour(glm::vec4 specularColourRGBA)
{
	this->_specularColour = specularColourRGBA;
}
void cTestObject::setVelocity(glm::vec3 velocityXYZ)
{
	this->_velocity = velocityXYZ;
}
void cTestObject::setVelocityX(float velocityX)
{
	this->_velocityX = velocityX;
}
void cTestObject::setVelocityY(float velocityY)
{
	this->_velocityY = velocityY;
}
void cTestObject::setVelocityZ(float velocityZ)
{
	this->_velocityZ = velocityZ;
}
void cTestObject::setAccel(glm::vec3 accelXYZ)
{
	this->_accel = accelXYZ;
}
void cTestObject::setInverseMass(float inverseMass)
{
	this->_inverseMass = inverseMass;
}
void cTestObject::setPhysicsShapeType(std::string physicsShapeType)
{
	this->_physicsShapeType = physicsShapeType;
}
void cTestObject::setIsWireframe(bool isWireFrame)
{
	this->_isWireframe = isWireFrame;
}
void cTestObject::setDebugColour(glm::vec4 debugColourRGBA)
{
	this->_debugColour = debugColourRGBA;
}
void cTestObject::set_SPHERE_radius(float radius)
{
	this->_SPHERE_radius = radius;
}
void cTestObject::setIsVisible(bool isVisible)
{
	this->_isVisible = isVisible;
}
void cTestObject::setDisableDepthBufferTest(bool disableDepthBufferTest)
{
	this->_disableDepthBufferTest = disableDepthBufferTest;
}
void cTestObject::setDisableDepthBufferWrite(bool disableDepthBufferWrite)
{
	this->_disableDepthBufferWrite = disableDepthBufferWrite;
}

cTestObject::cTestObject()
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
	this->_m_uniqueID = cTestObject::next_uniqueID;
	// Then increment the static variable
	cTestObject::next_uniqueID++;

	this->_disableDepthBufferTest = false;
	this->_disableDepthBufferWrite = false;


	return;
}


unsigned int cTestObject::getUniqueID(void)
{
	return this->_m_uniqueID;
}

// this variable is static, so common to all objects.
// When the object is created, the unique ID is set, and 
//	the next unique ID is incremented
//static 
unsigned int cTestObject::next_uniqueID = 1000;	// Starting at 1000, just because
