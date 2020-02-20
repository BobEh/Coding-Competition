#pragma once
#include "iCommand.h"

class cMoveTo_Start_End_Time : public iCommand
{
public:
	// Pass: 
	// - Start location (vec3)
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
	std::string m_Name;

	cGameObject* m_pTheGO;

	glm::vec3 m_startPosition;
	glm::vec3 m_endPosition;
	float m_TimeToMove;

	glm::vec3 m_velocity;
	float m_totalDistance;	// when the object has moved this far, it's done

};