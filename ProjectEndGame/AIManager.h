#pragma once

#include <map>
#include "iObject.h"
#include "Behaviour.h"

class AIManager {
public:
	AIManager(void);
	~AIManager(void);

	void SetBehaviour(iObject* agent, Behaviour* behaviour);
	void RemoveAgent(iObject* agent);

	void update(float dt);

private:
	std::map<iObject*, Behaviour*> mBehaviourMap;
};

typedef std::map<iObject*, Behaviour*>::iterator behaviour_iterator;