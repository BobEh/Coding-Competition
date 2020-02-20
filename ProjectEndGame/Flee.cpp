#include "Flee.h"

Flee::Flee(iObject* agent, iObject* target) : mAgent(agent), mTarget(target)
{

}

Flee::~Flee(void)
{
}

void Flee::update(float dt)
{
	if (mAgent == 0 || mTarget == 0) return;

	/*calculates the desired velocity */
		/*Seek uses target position - current position*/
		/*Flee uses current position - target position*/
	glm::vec3 desiredVelocity = (mTarget->getPositionXYZ() - mAgent->getPositionXYZ()) * glm::vec3(-1.0f);

	/* get the distance from target */
	float dist = glm::distance(mAgent->getPositionXYZ(), mTarget->getPositionXYZ());

	glm::normalize(desiredVelocity);

	float maxVelocity = 3.0f;
	float slowingRadius = 5.0f;

	/*is the game object within the radius around the target */
	if (dist > slowingRadius)
	{
		/* game object is approaching the target and slows down*/
		desiredVelocity = desiredVelocity * maxVelocity * (dist / slowingRadius);
	}
	else
	{
		/* target is far away from game object*/
		desiredVelocity *= maxVelocity;
	}

	/*calculate the steering force */
	glm::vec3 steer = desiredVelocity - mAgent->getVelocity();

	/* add steering force to current velocity*/
	mAgent->setVelocity(steer * 0.03f);

	if (glm::length(mAgent->getVelocity()) > maxVelocity)
	{
		mAgent->setVelocity(glm::normalize(mAgent->getVelocity()) * maxVelocity);
	}
}