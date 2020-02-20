#pragma once
#include "cShooter.h"
#include "cBigShooter.h"


class iObjectBuilder
{
public:
	virtual ~iObjectBuilder() {};

	virtual void SetShooter(cShooter* pShooter) = 0;
	virtual void SetBigShooter(cBigShooter* pBigShooter) = 0;
};