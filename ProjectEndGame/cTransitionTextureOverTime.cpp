#include "cTransitionTextureOverTime.h"

void cTransitionTextureOverTime::Init(std::vector<sPair> vecDetails)
{
	this->startTexture = vecDetails[0].stringData;
	this->endTexture = vecDetails[1].stringData;
	this->m_TimeToTransition = vecDetails[2].numData.x;

	// Goes from 0.0 to 1.0 in so many seconds
	this->m_BlendChangePerSecond = 1.0f / this->m_TimeToTransition;

	return;
}

void cTransitionTextureOverTime::SetGameObject(cGameObject* pGO)
{
	this->m_pTheGO = pGO;
	return;
}

void cTransitionTextureOverTime::Update(double deltaTime)
{
	if (!this->m_UpdateHasBeenCalled)
	{
		this->m_pTheGO->textures[0] = this->startTexture;
		this->m_pTheGO->textures[1] = this->endTexture;
		this->m_pTheGO->textureRatio[0] = 1.0f; 
		this->m_pTheGO->textureRatio[1] = 0.0f;
		this->m_UpdateHasBeenCalled = true;
	}

	this->m_CurrentBlendRatio += (this->m_BlendChangePerSecond * (float)deltaTime);

	this->m_pTheGO->textureRatio[0] = 1.0f - this->m_CurrentBlendRatio;
	this->m_pTheGO->textureRatio[1] = this->m_CurrentBlendRatio;

	return;
}

bool cTransitionTextureOverTime::IsDone(void)
{
	if (this->m_CurrentBlendRatio >= 1.0f)
	{
		return true;
	}
	return false;
}

// This is if you want your commands to ALSO be command groups:
void cTransitionTextureOverTime::AddCommandSerial(iCommand* pCommand)
{
	return;
}
void cTransitionTextureOverTime::AddCommandsParallel(std::vector<iCommand*> vec_pCommands)
{
	return;
}
