#pragma once

#include "Behaviour.h"
#include "iObject.h"

class Seek : public Behaviour {
public:
	Seek(iObject* agent, iObject* target);
	virtual ~Seek(void);

	virtual void update(float dt);

private:
	iObject* mTarget;
	iObject* mAgent;
};