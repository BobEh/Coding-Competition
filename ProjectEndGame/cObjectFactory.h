#pragma once

#include "iObjectBuilder.h"
#include "iObject.h"
#include <string>
#include <vector>

class cObjectFactory
{
public:
	iObject* CreateObject(std::string objectType);

private:
	// The builder method
	void BuildObject(iObject* pObject, std::string objectType);
};