#pragma once
#include "iCommand.h"

class cCommandGroup : public iCommand
{
public: 
	cCommandGroup();
	virtual void SetGameObject(cGameObject* pGO);
	virtual void Init(std::vector<sPair> vecDetails);
	virtual void Update(double deltaTime);
	virtual bool IsDone(void);
	virtual void setName(std::string name) { this->m_Name = name; }
	virtual std::string getName(void) { return this->m_Name; }


	// This is if you want your commands to ALSO be command groups:
	virtual void AddCommandSerial(iCommand* pCommand);
	virtual void AddCommandsParallel(std::vector<iCommand*> vec_pCommands);

private:
	std::string m_Name;

	std::vector< iCommand* > vecSerial;
	std::vector< iCommand* > vecParallel;

	bool m_SerialCommandIsEmpty;
};


