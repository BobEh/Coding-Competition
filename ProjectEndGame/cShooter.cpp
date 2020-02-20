#include "cShooter.h"
#include "cSphereObject.h"


void cShooter::Shoot()
{
	iObject* pBall = new cSphereObject();

	pBall->setPositionXYZ(this->position);
	pBall->setInverseMass(1.0f);
	pBall->setVelocity(glm::vec3(15.0f, 20.0f, 0.0f));
	pBall->setAccel(glm::vec3(0.0f, 0.0f, 0.0f));
	pBall->setDiffuseColour(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));
}

glm::vec3 cShooter::getPosition()
{
	return this->position;
}

void cShooter::setPosition(glm::vec3 newPosition)
{
	this->position = newPosition;
}
