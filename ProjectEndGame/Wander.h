#pragma once

#include "Behaviour.h"
#include "iObject.h"

class Wander : public Behaviour {
public:
	Wander(iObject* agent, glm::vec3 target);
	virtual ~Wander(void);

	virtual void update(float dt);

	glm::vec3 mTarget;

private:
	
	iObject* mAgent;
};