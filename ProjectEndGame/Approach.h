#pragma once

#include "Behaviour.h"
#include "iObject.h"

class Approach : public Behaviour {
public:
	Approach(iObject* agent, iObject* target);
	virtual ~Approach(void);

	virtual void update(float dt);

private:
	iObject* mTarget;
	iObject* mAgent;
};