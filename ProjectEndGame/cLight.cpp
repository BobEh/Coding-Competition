#include <string>
#include <vector>
#include <iostream>
#include <glm/vec3.hpp>
#include "cLight.h"
#include "cLightImp.h"

cLight::cLight()
{
	this->pToImp = new cLightImp();
	this->_PositionX = 0.0f;
	this->_PositionY = 0.0f;
	this->_PositionZ = 0.0f;
	this->_ConstAtten = 0.0f;
	this->_LinearAtten = 0.0f;
	this->_QuadraticAtten = 0.0f;
	this->_InnerSpot = 0.0f;
	this->_OuterSpot = 0.0f;
	this->_positionXYZ = glm::vec3(0.0f, 0.0f, 0.0f);
}
cLight::cLight(std::string nodeName, float PositionX, float PositionY, float PositionZ, float ConstAtten, float LinearAtten, float QuadraticAtten, float InnerSpot, float OuterSpot)
{
	this->pToImp = new cLightImp();
	this->_nodeName = nodeName;
	this->_PositionX = PositionX;
	this->_PositionY = PositionY;
	this->_PositionZ = PositionZ;
	this->_ConstAtten = ConstAtten;
	this->_LinearAtten = LinearAtten;
	this->_QuadraticAtten = QuadraticAtten;
	this->_InnerSpot = InnerSpot;
	this->_OuterSpot = OuterSpot;
	this->_positionXYZ = glm::vec3(PositionX, PositionY, PositionZ);
}
cLight::~cLight()
{
	delete this->pToImp;
}

std::string cLight::getNodeName()
{
	return this->_nodeName;
}
void cLight::setNodeName(std::string nodeName)
{
	this->_nodeName = nodeName;
}
//getters
std::vector<std::string> cLight::getAllDataStrings() {
	std::vector<std::string> result;
	result.push_back(std::to_string(this->_PositionX));
	result.push_back(std::to_string(this->_PositionY));
	result.push_back(std::to_string(this->_PositionZ));
	result.push_back(std::to_string(this->_ConstAtten));
	result.push_back(std::to_string(this->_LinearAtten));
	result.push_back(std::to_string(this->_QuadraticAtten));
	result.push_back(std::to_string(this->_InnerSpot));
	result.push_back(std::to_string(this->_OuterSpot));
	return result;
}
float cLight::getPositionX()
{
	return this->_PositionX;
}
float cLight::getPositionY()
{
	return this->_PositionY;
}
float cLight::getPositionZ()
{
	return this->_PositionZ;
}
float cLight::getConstAtten()
{
	return this->_ConstAtten;
}
float cLight::getLinearAtten()
{
	return this->_LinearAtten;
}
float cLight::getQuadraticAtten()
{
	return this->_QuadraticAtten;
}
float cLight::getInnerSpot()
{
	return this->_InnerSpot;
}
float cLight::getOuterSpot()
{
	return this->_OuterSpot;
}
glm::vec3 cLight::getPositionXYZ()
{
	return this->_positionXYZ;
}
//Setters
void cLight::setPositionX(float PositionX)
{
	this->_PositionX = PositionX;
}
void cLight::setPositionY(float PositionY)
{
	this->_PositionY = PositionY;
}
void cLight::setPositionZ(float PositionZ)
{
	this->_PositionZ = PositionZ;
}
void cLight::setConstAtten(float ConstAtten)
{
	this->_ConstAtten = ConstAtten;
}
void cLight::setLinearAtten(float LinearAtten)
{
	this->_LinearAtten = LinearAtten;
}
void cLight::setQuadraticAtten(float QuadraticAtten)
{
	this->_QuadraticAtten = QuadraticAtten;
}
void cLight::setInnerSpot(float InnerSpot)
{
	this->_InnerSpot = InnerSpot;
}
void cLight::setOuterSpot(float OuterSpot)
{
	this->_OuterSpot = OuterSpot;
}
void cLight::setPositionXYZ(glm::vec3 XYZ)
{
	this->_positionXYZ = XYZ;
}

sNVPair cLight::RecieveMessage(sNVPair message)
{
	sNVPair response;
	response.name = "UNKNOWN COMMAND";

	if (message.name == "Position X Down")
	{
		float adjustment = this->getPositionX() - message.fValue;
		this->setPositionX(adjustment);
		response.name = "OK";
		return response;
	}
	if (message.name == "Position X Up")
	{
		float adjustment = this->getPositionX() + message.fValue;
		this->setPositionX(adjustment);
		response.name = "OK";
		return response;
	}
	if (message.name == "Position Y Down")
	{
		float adjustment = this->getPositionY() - message.fValue;
		this->setPositionY(adjustment);
		response.name = "OK";
		return response;
	}
	if (message.name == "Position Y Up")
	{
		float adjustment = this->getPositionY() + message.fValue;
		this->setPositionY(adjustment);
		response.name = "OK";
		return response;
	}
	if (message.name == "Position Z Down")
	{
		float adjustment = this->getPositionZ() - message.fValue;
		this->setPositionZ(adjustment);
		response.name = "OK";
		return response;
	}
	if (message.name == "Position Z Up")
	{
		float adjustment = this->getPositionZ() + message.fValue;
		this->setPositionZ(adjustment);
		response.name = "OK";
		return response;
	}

	return response;
}