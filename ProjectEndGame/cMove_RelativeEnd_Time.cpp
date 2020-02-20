#include "cMove_RelativeEnd_Time.h"



void cMove_RelativeEnd_Time::Init(std::vector<sPair> vecDetails)
{
	this->m_endPosition = glm::vec3(vecDetails[0].numData);
	this->m_TimeToMove = glm::vec3(vecDetails[1].numData).x;

	// The rest of the information is calculated on the 1st update.

	return;

}

void cMove_RelativeEnd_Time::SetGameObject(cGameObject* pGO)
{
	this->m_pTheGO = pGO;
	return;
}

void cMove_RelativeEnd_Time::Update(double deltaTime)
{
	// 1st time Update has been called? 
	if ( ! this->m_UpdateHasBeeCalled )
	{
		this->m_startPosition = this->m_pTheGO->positionXYZ;

		// Calculate the velocity...
		glm::vec3 moveVector = this->m_endPosition - this->m_startPosition;

		this->m_totalDistance = glm::length(moveVector);

		float speed = this->m_totalDistance / this->m_TimeToMove;

		glm::vec3 direction = glm::normalize(moveVector);

		this->m_velocity = direction * speed;

		this->m_UpdateHasBeeCalled = true;
	}



	glm::vec3 deltaStep = this->m_velocity * (float)deltaTime;

	// This could be done in the physics engine... 
	this->m_pTheGO->positionXYZ += deltaStep;

	return;
}


bool cMove_RelativeEnd_Time::IsDone(void)
{
	// Info is set up on the 1st update, so we need to call Update
	if (this->m_UpdateHasBeeCalled == false)
	{
		return false;
	}

	float distance = glm::distance(this->m_pTheGO->positionXYZ,
								   this->m_startPosition);

	if (distance >= this->m_totalDistance)
	{
		return true;
	}

	return false;
}

// This is if you want your commands to ALSO be command groups:

void cMove_RelativeEnd_Time::AddCommandSerial(iCommand* pCommand)
{
	return;
}

void cMove_RelativeEnd_Time::AddCommandsParallel(std::vector<iCommand*> vec_pCommands)
{
	return;
}