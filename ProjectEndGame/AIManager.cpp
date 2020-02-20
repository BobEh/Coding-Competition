#include "AIManager.h"

AIManager::AIManager(void) {

}

AIManager::~AIManager(void) {
	// Perform cleanup
	for (behaviour_iterator itAgent = mBehaviourMap.begin();
		itAgent != mBehaviourMap.end(); itAgent++) {
		if (itAgent->second != 0) {
			delete itAgent->second;
		}
	}
	mBehaviourMap.clear();
}

void AIManager::SetBehaviour(iObject* agent, Behaviour* behaviour)
{
	// Check if the agent is already in the behaviour map
	behaviour_iterator itAgent = mBehaviourMap.find(agent);

	// If the agent is in the map, and there is already a behaviour then delete 
	// the behaviour
	if (itAgent != mBehaviourMap.end() && itAgent->second != 0) {
		delete itAgent->second;
	}

	mBehaviourMap[agent] = behaviour;
}

void AIManager::RemoveAgent(iObject* agent) {
	// Check if the agent is in the map
	behaviour_iterator itAgent = mBehaviourMap.find(agent);

	// if the agent is in the map, delete the behaviour, and remove the agent.
	if (itAgent != mBehaviourMap.end()) {
		if (itAgent->second != 0) {
			delete itAgent->second;
		}
		mBehaviourMap.erase(itAgent);
	}
}

void AIManager::update(float dt) {
	for (behaviour_iterator itAgent = mBehaviourMap.begin();
		itAgent != mBehaviourMap.end(); itAgent++) {
		if (itAgent->second != 0) {
			itAgent->second->update(dt);
		}
	}
}