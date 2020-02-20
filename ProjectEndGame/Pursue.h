#pragma once

#include "Behaviour.h"
#include "iObject.h"

class Pursue : public Behaviour {
public:
	Pursue(iObject* agent, iObject* target);
	virtual ~Pursue(void);

	virtual void update(float dt);

private:
	iObject* mTarget;
	iObject* mAgent;
};