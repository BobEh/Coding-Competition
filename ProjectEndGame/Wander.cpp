#include "Wander.h"

Wander::Wander(iObject* agent, glm::vec3 target) : mAgent(agent), mTarget(target)
{

}

Wander::~Wander(void)
{
}

void Wander::update(float dt)
{
	if (mAgent == 0) return;

	/*calculates the desired velocity */
		/*Seek uses target position - current position*/
		/*Flee uses current position - target position*/
	glm::vec3 desiredVelocity = mTarget - mAgent->getPositionXYZ();

	/* get the distance from target */
	float dist = glm::distance(mAgent->getPositionXYZ(), mTarget);

	glm::normalize(desiredVelocity);

	float maxVelocity = 3.0f;

	/* target is far away from game object*/
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