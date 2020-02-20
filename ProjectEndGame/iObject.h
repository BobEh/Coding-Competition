#pragma once

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/quaternion.hpp>
#include <string>
#include <vector>

class iObject
{
public:
	//getters
	virtual std::string getBehaviour() = 0;
	virtual std::vector<glm::vec3> getTestPoints() = 0;
	virtual std::string getMeshName() = 0;
	virtual unsigned int getFriendlyIDNumber() = 0;
	virtual std::string getFriendlyName() = 0;
	virtual glm::vec3 getPositionXYZ() = 0;
	virtual glm::quat getRotationXYZ() = 0;
	virtual float getScale() = 0;
	virtual glm::mat4 getMatWorld() = 0;
	virtual glm::vec4 getObjectColourRGBA() = 0;
	virtual glm::vec4 getDiffuseColour() = 0;
	virtual glm::vec4 getSpecularColour() = 0;
	virtual glm::vec3 getVelocity() = 0;
	virtual float getVelocityX() = 0;
	virtual float getVelocityY() = 0;
	virtual float getVelocityZ() = 0;
	virtual glm::vec3 getAccel() = 0;
	virtual float getInverseMass() = 0;
	virtual std::string getPhysicsShapeType() = 0;
	virtual bool getIsWireframe() = 0;
	virtual glm::vec4 getDebugColour() = 0;
	virtual float get_SPHERE_radius() = 0;
	virtual bool getIsVisible() = 0;
	virtual bool getDisableDepthBufferTest() = 0;
	virtual bool getDisableDepthBufferWrite() = 0;
	virtual std::string getTextures(int index)=0;
	virtual float getTextureRatio(int index)=0;

	virtual float getTransprancyValue()=0;
	virtual bool getIsTranspanrancy()=0;

	//leave this one ( don't need a setter )
	virtual unsigned int getUniqueID(void) = 0;
	//setters
	virtual void setBehaviour(std::string) = 0;
	virtual void addTestPoint(glm::vec3) = 0;
	virtual void setMeshName(std::string name) = 0;
	virtual void setFriendlyIDNumber(unsigned int IDNumber) = 0;
	virtual void setFriendlyName(std::string friendlyName) = 0;
	virtual void setPositionXYZ(glm::vec3 positionXYZ) = 0;
	virtual void setRotationXYZ(glm::quat rotationXYZ) = 0;
	virtual void setScale(float scale) = 0;
	virtual void setMatWorld(glm::mat4 matWorld) = 0;
	virtual void setObjectColourRGBA(glm::vec4 colourRGBA) = 0;
	virtual void setDiffuseColour(glm::vec4 diffuseColourRGBA) = 0;
	virtual void setSpecularColour(glm::vec4 specularColourRGBA) = 0;
	virtual void setVelocity(glm::vec3 velocityXYZ) = 0;
	virtual void setVelocityX(float velocityX) = 0;
	virtual void setVelocityY(float velocityY) = 0;
	virtual void setVelocityZ(float velocityZ) = 0;
	virtual void setAccel(glm::vec3 accelXYZ) = 0;
	virtual void setInverseMass(float inverseMass) = 0;
	virtual void setPhysicsShapeType(std::string physicsShapeType) = 0;
	virtual void setIsWireframe(bool isWireFrame) = 0;
	virtual void setDebugColour(glm::vec4 debugColourRGBA) = 0;
	virtual void set_SPHERE_radius(float radius) = 0;
	virtual void setIsVisible(bool isVisible) = 0;
	virtual void setDisableDepthBufferTest(bool disableDepthBufferTest) = 0;
	virtual void setDisableDepthBufferWrite(bool disableDwpthBufferWrite) = 0;

	virtual void MoveInRelativeDirection(glm::vec3 relativeDirection) = 0;

	virtual void setTexture(std::string tex, int index) = 0;
	virtual void setTextureRatio(float texRatio, int index) = 0;

	virtual void setTransprancyValue(float transprancyValue)=0;
	virtual void setIsTranspanrancy(bool isTranspanrancy)=0;

	//virtual void MoveInRelativeDirection(glm::vec3 relativeDirection) = 0;
};