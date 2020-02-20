#include "cMoveTo_Start_End_Time.h"

void cMoveTo_Start_End_Time::Init(std::vector<sPair> vecDetails)
{
	this->m_startPosition = glm::vec3(vecDetails[0].numData);
	this->m_endPosition = glm::vec3(vecDetails[1].numData);
	this->m_TimeToMove = glm::vec3(vecDetails[2].numData).x;

	// Calculate the velocity...
	glm::vec3 moveVector = this->m_endPosition - this->m_startPosition;

	this->m_totalDistance = glm::length( moveVector );

	float speed = this->m_totalDistance / this->m_TimeToMove;

	glm::vec3 direction = glm::normalize(moveVector);

	this->m_velocity = direction * speed;

	return;
}

void cMoveTo_Start_End_Time::SetGameObject(cGameObject* pGO)
{
	this->m_pTheGO = pGO;
	return;
}

void cMoveTo_Start_End_Time::Update(double deltaTime)
{
	glm::vec3 deltaStep = this->m_velocity * (float)deltaTime; 

	// This could be done in the physics engine... 
	this->m_pTheGO->positionXYZ += deltaStep;

	return;
}

bool cMoveTo_Start_End_Time::IsDone(void)
{
	float distance = glm::distance( this->m_pTheGO->positionXYZ, 
								    this->m_startPosition );

	if ( distance >= this->m_totalDistance )
	{
		return true;
	}

	return false;
}

// This is if you want your commands to ALSO be command groups:

void cMoveTo_Start_End_Time::AddCommandSerial(iCommand* pCommand)
{
	return;
}

void cMoveTo_Start_End_Time::AddCommandsParallel(std::vector<iCommand*> vec_pCommands)
{
	return;
}