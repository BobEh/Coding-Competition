#pragma once

#include <vector>
#include "cLight.h"
#include "iMessageInterface.h"

class cMediator : public iMessageInterface
{
public:

	static cMediator* createMediator();

	// from iMessageInterface
	virtual sNVPair RecieveMessage(sNVPair message);

	std::vector<cLight*> m_vec_pLights;
	std::vector<cLight*> m_vec_pBallLights;

private:
	static cMediator* pMediator;

};