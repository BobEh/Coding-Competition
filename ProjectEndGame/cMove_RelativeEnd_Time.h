#pragma once
#include "iCommand.h"

class cMove_RelativeEnd_Time : public iCommand
{
public:
	cMove_RelativeEnd_Time()
	{
		this->m_UpdateHasBeeCalled = false;
	}
	// Moves object RELATIVE to where command starts
	// Pass: 
	// - End location (vec3)
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

	glm::vec3 m_startPosition;
	glm::vec3 m_endPosition;
	float m_TimeToMove;

	glm::vec3 m_velocity;
	float m_totalDistance;	// when the object has moved this far, it's done

};