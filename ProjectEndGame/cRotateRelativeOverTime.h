#pragma once
#include "iCommand.h"

class cRotateRelativeOverTime : public iCommand
{
public:
	cRotateRelativeOverTime()
	{
		this->m_UpdateHasBeeCalled = false;
	}
	// Rotate object RELATIVE to where command starts
	// Pass: 
	// - End rotation (Euler degrees) (vec3)
	// - Number of seconds to move (x)
	virtual void Init(std::vector<sPair> vecDetails);
	virtual void SetGameObject(cGameObject* pGO);
	virtual void Update(double deltaTime);
	virtual bool IsDone(void);

	virtual void setName(std::string name) { this->m_Name = name; }
	virtual std::string getName(void) { return this->m_Name; }

	// This is if you want your commands to ALSO be command groups:
	virtual void AddCommandSerial(iCommand* pCommand);
	virtual void AddCommandsParallel(std::vector<iCommand*> vec_pCommands);

private:

	// Flag to see if update has been called once
	bool m_UpdateHasBeeCalled;

	std::string m_Name;

	cGameObject* m_pTheGO;

	glm::quat m_startOrentation;		// Starting location
	glm::quat m_endOrientation;			// Ending location
	glm::quat m_rotationalSpeed;		// Like velocity
	float m_TimeToRotate;

	double m_TimeElapsed;
};