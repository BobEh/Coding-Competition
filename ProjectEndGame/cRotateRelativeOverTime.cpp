#include "cRotateRelativeOverTime.h"
#include <glm/gtc/quaternion.hpp>

void cRotateRelativeOverTime::Init(std::vector<sPair> vecDetails)
{
	// - End rotation (Euler degrees) (vec3)
	// - Number of seconds to move (x)

	glm::vec3 EulerAngle;
	EulerAngle.x = glm::radians(vecDetails[0].numData.x);
	EulerAngle.y = glm::radians(vecDetails[0].numData.y);
	EulerAngle.z = glm::radians(vecDetails[0].numData.z);

	this->m_endOrientation = glm::quat(EulerAngle);

	this->m_TimeToRotate = vecDetails[1].numData.x;

	return;
}




void cRotateRelativeOverTime::Update(double deltaTime)
{
	if ( ! this->m_UpdateHasBeeCalled )
	{
		this->m_startOrentation = this->m_pTheGO->getQOrientation();

		// https://stackoverflow.com/questions/22157435/difference-between-the-two-quaternions
		glm::quat invStart = glm::inverse(this->m_startOrentation);
		glm::quat qRoationChange = invStart * this->m_endOrientation;

		// How "fast" do we rotation this? 
//		this->m_rotationalSpeed = qRoationChange / this->m_TimeToRotate;

		this->m_UpdateHasBeeCalled = true;
	}

	// Just like updating the position, we scale (SLERP) based on deltaTime
	  
	// get a number between 0.0 and 1.0f
	float AmountOfRotationCompleted = (float)this->m_TimeElapsed / this->m_TimeToRotate; 

	glm::quat qCurrentRotation 
		= glm::slerp( this->m_startOrentation, this->m_endOrientation, 
					  AmountOfRotationCompleted );

	this->m_pTheGO->setOrientation(qCurrentRotation);

	

	this->m_TimeElapsed += deltaTime;


	return;
}


bool cRotateRelativeOverTime::IsDone(void)
{
	if (this->m_TimeElapsed >= this->m_TimeToRotate)
	{
		return true;
	}
	return false;
}











void cRotateRelativeOverTime::SetGameObject(cGameObject* pGO)
{
	this->m_pTheGO = pGO;
	return;
}


// This is if you want your commands to ALSO be command groups:
void cRotateRelativeOverTime::AddCommandSerial(iCommand* pCommand)
{
	return;
}
void cRotateRelativeOverTime::AddCommandsParallel(std::vector<iCommand*> vec_pCommands)
{
	return;
}