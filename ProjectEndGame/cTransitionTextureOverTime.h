#pragma once
#include "iCommand.h"

class cTransitionTextureOverTime : public iCommand
{
public:
	// Transitions one texture to another over a set time
	// - Start texture
	// - End texture
	// - time to transition (x)
	cTransitionTextureOverTime()
	{
		this->m_UpdateHasBeenCalled = false;
	}
	// Moves object RELATIVE to where command starts
	// Pass: 
	// - End location (vec3)
	// - Number of seconds to move (x)
	virtual void Init(std::vector<sPair> vecDetails);
	virtual void SetGameObject(cGameObject* pGO);
	virtual void Update(double deltaTime);
	virtual bool IsDone(void);

	virtual void setName(std::string name) { this->m_Name = name; }
	virtual std::string getName(void) { return this->m_Name; }

	// This is if you want your commands to ALSO be command groups:
	virtual void AddCommandSerial(iCommand* pCommand);
	virtual void AddCommandsParallel(std::vector<iCommand*> vec_pCommands);

private:

	// Flag to see if update has been called once
	std::string startTexture;
	std::string endTexture;

	float m_TimeToTransition;
	float m_CurrentBlendRatio;
	float m_BlendChangePerSecond;

	cGameObject* m_pTheGO;

	std::string m_Name;

	bool m_UpdateHasBeenCalled;

};