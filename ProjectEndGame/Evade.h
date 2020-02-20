#pragma once

#include "Behaviour.h"
#include "iObject.h"

class Evade : public Behaviour {
public:
	Evade(iObject* agent, iObject* target);
	virtual ~Evade(void);

	virtual void update(float dt);

private:
	iObject* mTarget;
	iObject* mAgent;
};