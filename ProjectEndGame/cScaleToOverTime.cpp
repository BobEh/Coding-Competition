#include "cScaleRelativeToOverTime.h"

void cScaleRelativeToOverTime::Init(std::vector<sPair> vecDetails)
{
	// Scales the object over time
	// Pass: 
	// - Ending Scale
	// - Number of seconds this will take
	// Initial scale is set on the 1st Update()

	//this->m_

}
void cScaleRelativeToOverTime::SetGameObject(cGameObject* pGO);
void cScaleRelativeToOverTime::Update(double deltaTime);
bool cScaleRelativeToOverTime::IsDone(void);

void cScaleRelativeToOverTime::AddCommandSerial(iCommand* pCommand);
void cScaleRelativeToOverTime::AddCommandsParallel(std::vector<iCommand*> vec_pCommands);
