#include "Evade.h"

Evade::Evade(iObject* agent, iObject* target) : mAgent(agent), mTarget(target)
{

}

Evade::~Evade(void)
{

}

void Evade::update(float dt)
{
	float maxVelocity = 10.0f;
	//calculate the number of frames we are looking ahead
	glm::vec3 distance = mTarget->getPositionXYZ() - mAgent->getPositionXYZ();
	int T = (int)glm::length(distance) / (int)maxVelocity;

	//the future target point the vehicle will pursue towards
	glm::vec3 futurePosition = mTarget->getPositionXYZ() + mTarget->getVelocity() * glm::vec3(T);

	/*calculates the desired velocity */
	glm::vec3 desiredVelocity = (futurePosition - mAgent->getPositionXYZ()) * glm::vec3(-1.0f);

	glm::normalize(desiredVelocity);

	desiredVelocity *= maxVelocity;

	/*calculate the steering force */
	glm::vec3 steer = desiredVelocity - mAgent->getVelocity();

	/* add steering force to current velocity*/
	mAgent->setVelocity(steer * 0.03f);

	if (glm::length(mAgent->getVelocity()) > maxVelocity)
	{
		mAgent->setVelocity(glm::normalize(mAgent->getVelocity()) * maxVelocity);
	}
}
