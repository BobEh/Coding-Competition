#pragma once
#include <string>
#include <vector>
#include "cGameObject.h"
#include <glm/glm.hpp>
#include <glm/vec4.hpp>

struct sPair
{
	sPair() {};
	sPair(std::string stringData, glm::vec4 numData)
	{
		this->stringData = stringData;
		this->numData = numData;
	}
	sPair(std::string stringData)
	{
		this->stringData = stringData;
	}
	sPair(glm::vec4 numData)
	{
		this->numData = numData;
	}
	sPair(glm::vec3 numData)
	{
		this->numData = glm::vec4( numData, 1.0f );
	}
	sPair(float num)
	{
		this->numData.x = num;
	}
	std::string stringData;
	glm::vec4 numData;
};

// This is the base interface for all commands and command groups
class iCommand
{
public:
	virtual ~iCommand() {};
	virtual void SetGameObject( cGameObject* pGO ) = 0;
	virtual void Init( std::vector<sPair> vecDetails ) = 0;
	virtual void Update( double deltaTime ) = 0;
	virtual bool IsDone(void) = 0;

	virtual void setName(std::string name) = 0;
	virtual std::string getName(void) = 0;

	// This is if you want your commands to ALSO be command groups:
	virtual void AddCommandSerial( iCommand* pCommand ) = 0;
//	virtual void AddCommandParallel( iCommand* pCommand ) = 0;
	virtual void AddCommandsParallel( std::vector<iCommand*> vec_pCommands ) = 0;
};
//
//class cMoveTo : public iCommand
//{
//	virtual void Init(std::vector<sPair> vecDetails);
//
//	virtual void Update(double deltaTime)
//	{
//		Step the values...
//	}
//
//	virtual bool IsDone(void)
//	{
//		Has the time passed? 
//		Am I at the location?
//		Have I moved the right distance?
//	}
//};
//
//if PositionXYZ == vec3( 10.0f, 20.0f, 13.0f )
//
//class cCloseGripper : public iCommand
//{
//	virtual void Init(std::vector<sPair> vecDetails) = 0;
//	virtual void Update(double deltaTime) = 0;
//	virtual bool IsDone(void) = 0;
//};
//
//class cOpenGripper : public iCommand
//{
//	virtual void Update(double deltaTime) = 0;
//};
//
////cCommandGroup X;
////X.AddCommandSerial(cOpenGrippercCloseGripper);
////X.AddCommandSerial(cCloseGripper);
////X.AddCommandSerial(cRaiseArm);
////X.AddCommandSerial(cAim);
////X.AddCommandSerial(cShoot);
//
//
//class cCommandGroup : public iCommand
//{
//
//};