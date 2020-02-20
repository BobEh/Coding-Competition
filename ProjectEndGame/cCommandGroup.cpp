#include "cCommandGroup.h"
#include <iostream>

cCommandGroup::cCommandGroup()
{
	this->m_SerialCommandIsEmpty = true;
	return;
}


void cCommandGroup::Init(std::vector<sPair> vecDetails)
{
	// The command group doesn't need to process any commands. 
	return;
}

void cCommandGroup::Update(double deltaTime)
{
	// For serial commands, run the "next" command until it's done.
	if ( ! this->vecSerial.empty() )
	{
		iCommand* pCurrent = *this->vecSerial.begin();

//		std::cout << pCurrent->getName() << std::endl;

		if ( !pCurrent->IsDone())
		{
			pCurrent->Update(deltaTime);
		}
		else
		{
			delete pCurrent;
			// remove this command from the vector
			this->vecSerial.erase( this->vecSerial.begin() );
		}

	}

	// parallel  : run Update on ALL the parallel commands. 
	//             ONLY IF THEY RETURN FALSE on IsDone();
	for ( std::vector< iCommand* >::iterator itCommand = this->vecParallel.begin(); 
		  itCommand != this->vecParallel.end(); itCommand++ )
	{
		iCommand* pCurrent = *this->vecSerial.begin();

		if ( !pCurrent->IsDone() )
		{
			pCurrent->Update(deltaTime);
		}

	}
	return;
}

bool cCommandGroup::IsDone(void)
{
	bool bAllDone = true; 

	// Serial commands
	for (std::vector< iCommand* >::iterator itCommand = this->vecSerial.begin();
		 itCommand != this->vecSerial.end(); itCommand++)
	{
		iCommand* pCurrent = *itCommand;

		if ( !pCurrent->IsDone() )
		{
			bAllDone = false;
		}
	}

	// Parallel commands
	for (std::vector< iCommand* >::iterator itCommand = this->vecParallel.begin();
		 itCommand != this->vecParallel.end(); itCommand++)
	{
		iCommand* pCurrent = *itCommand;

		if (!pCurrent->IsDone())
		{
			bAllDone = false;
		}
	}

	return bAllDone;
}

void cCommandGroup::AddCommandSerial(iCommand* pCommand)
{

	this->vecSerial.push_back( pCommand );

	return;
}

void cCommandGroup::AddCommandsParallel(std::vector<iCommand*> vec_pCommands)
{
	//TODO
	return;
}

void cCommandGroup::SetGameObject(cGameObject* pGO)
{
	return;
}
