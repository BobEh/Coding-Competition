#pragma once

#include "Behaviour.h"
#include "iObject.h"

class Flee : public Behaviour {
public:
	Flee(iObject* agent, iObject* target);
	virtual ~Flee(void);

	virtual void update(float dt);

private:
	iObject* mTarget;
	iObject* mAgent;
};