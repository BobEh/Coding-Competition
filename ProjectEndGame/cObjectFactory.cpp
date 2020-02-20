#include "cObjectFactory.h"
#include "cGameObject.h"
#include "cSphereObject.h"
#include "cMeshObject.h"


iObject* cObjectFactory::CreateObject(std::string objectType)
{
	iObject* pTheObject = NULL;		// 0

	if (objectType == "unknown")
	{
		pTheObject = new cGameObject();
	}
	else if (objectType == "sphere")
	{
		pTheObject = new cSphereObject();
	}
	else if (objectType == "mesh")
	{
		pTheObject = new cMeshObject();
	}

	return pTheObject;
}

void cObjectFactory::BuildObject(iObject* pObject, std::string objectType)
{
	if (objectType == "shpere")
	{
		((cSphereObject*)pObject)->pShooter = new cShooter();
	}
	else if (objectType == "mesh")
	{
		((cMeshObject*)pObject)->pBigShooter = new cBigShooter();
	}

}