#pragma once

#include "cMesh.h"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include <vector>
#include <map>

#include "cMesh.h"			// for the triangle information

class triPoint
{
public:
	sPlyVertexXYZ_N_UV pointX;
	sPlyVertexXYZ_N_UV pointY;
	sPlyVertexXYZ_N_UV pointZ;
};
class cAABB
{
public:
	cAABB() {};
	glm::vec3 minXYZ;			// 0.0, 0.0, 0.0
	float length;
	glm::vec3 getMaxXYZ(glm::vec3 minXYZ, float length);
	glm::vec3 getCentre();
	std::vector<glm::vec3> getVecBoxPoints();

	cMesh* pTheMesh;
	std::vector< sPlyTriangle* > vecTriangles;
	std::vector<sPlyVertexXYZ_N_UV> triPosition;
	//std::vector<sPlyVertexXYZ_N> triYPosition;
	//std::vector<sPlyVertexXYZ_N> triZPosition;

	// 300-399    700-799    2400-2499
//	glm::vec3 shipLocation = glm::vec3( )

	// Test to see where our player (ship, whatever) is (which AABB it's in)
	static unsigned long long get_ID_of_AABB_I_Might_Be_In(glm::vec3 testLocation)
	{
		//glm::vec3 testMinLocation = glm::vec3(0.0f,0.0f,0.0f);
		//if (fabs(testLocation.x) > 99.0f || fabs(testLocation.y) > 99.0f || fabs(testLocation.z) > 99.0f)
		//{			
		//	testMinLocation.x = (int)(fabs(testLocation.x) / 100);
		//	testMinLocation.x *= 100;
		//	testMinLocation.y = (int)(fabs(testLocation.y) / 100);
		//	testMinLocation.y *= 100;
		//	testMinLocation.z = (int)(fabs(testLocation.z) / 100);
		//	testMinLocation.z *= 100;
		//}
		//else if (fabs(testLocation.x) > 9.0f || fabs(testLocation.y) > 9.0f || fabs(testLocation.z) > 9.0f)
		//{
		//	testMinLocation.x = (int)(fabs(testLocation.x) / 10);
		//	testMinLocation.x *= 10;
		//	testMinLocation.y = (int)(fabs(testLocation.y) / 10);
		//	testMinLocation.y *= 10;
		//	testMinLocation.z = (int)(fabs(testLocation.z) / 10);
		//	testMinLocation.z *= 10;
		//}
		//else if (fabs(testLocation.x) > 999.0f || fabs(testLocation.y) > 999.0f || fabs(testLocation.z) > 999.0f)
		//{
		//	testMinLocation.x = (int)(fabs(testLocation.x) / 1000);
		//	testMinLocation.x *= 1000;
		//	testMinLocation.y = (int)(fabs(testLocation.y) / 1000);
		//	testMinLocation.y *= 1000;
		//	testMinLocation.z = (int)(fabs(testLocation.z) / 1000);
		//	testMinLocation.z *= 1000;
		//}
		//else
		//{
		//	testMinLocation = testLocation;
		//}
		return cAABB::calcID(testLocation);
	}

	static unsigned long long calcID(glm::vec3 testLocation)
	{
		unsigned long long ID;		// x, y, z

			// Make sure these are rounded to the nearest 100 (length)
		unsigned long long ulX = 0;
		unsigned long long ulY = 0;
		unsigned long long ulZ = 0;

		// Are these negative
		if (testLocation.x < 0.0f)
		{
			ulX += 100000;		// 000,000   100,000   100300
		}
		if (testLocation.y < 0.0f)
		{
			ulY += 100000;		// 000,000   100,000
		}
		if (testLocation.z < 0.0f)
		{
			ulZ += 100000;		// 000,000   100,000
		}

		ulX += ((unsigned long long) fabs(floor(testLocation.x / 25))) * 25;	// -300	
		ulY += ((unsigned long long) fabs(floor(testLocation.y / 25))) * 25;	// 700
		ulZ += ((unsigned long long) fabs(floor(testLocation.z / 25))) * 25;	// -2400

		unsigned long long oneMillion = 1000000;

		// Side length of my box is 100

	//		32 bit ---> 0 to 4,000,000,000  9
	//		64 bit ---> 0 to 16   ,000,000    ,000,000   ,000,000

		ulX *= oneMillion * oneMillion;			// 100 * 100
		ulY *= oneMillion;
		ulZ *= 1;

		ID = ulX + ulY + ulZ;

		// 300, 700, 2400 ->      300,000700,002,400
		// -300, 700, -2400 -> 100300,000700,102,400


		return ID;


	}

	// NOTE: it's unsigned and it's 64 bit
	// This returns the ID the specific AABB
	unsigned long long getID()
	{
		unsigned long long ID = cAABB::calcID(this->minXYZ);		// x, y, z

		return ID;

		//		// Make sure these are rounded to the nearest 100 (length)
		//
		//		unsigned long long ulX = (unsigned long long) fabs(this->minXYZ.x);	// -300	
		//		unsigned long long ulY = (unsigned long long) fabs(this->minXYZ.y);	// 700
		//		unsigned long long ulZ = (unsigned long long) fabs(this->minXYZ.z);	// -2400
		//
		//		unsigned long long oneMillion = 1000000;
		//
		//		// Are these negative
		//		if (this->minXYZ.x < 0.0f)
		//		{
		//			ulX += 100000;		// 000,000   100,000   100300
		//		}
		//		if (this->minXYZ.y < 0.0f)
		//		{
		//			ulY += 100000;		// 000,000   100,000
		//		}
		//		if (this->minXYZ.z < 0.0f)
		//		{
		//			ulZ += 100000;		// 000,000   100,000
		//		}
		//		// Side length of my box is 100
		//
		////		32 bit ---> 0 to 4,000,000,000  9
		////		64 bit ---> 0 to 16   ,000,000    ,000,000   ,000,000
		//
		//		ulX *= oneMillion * oneMillion;			// 100 * 100
		//		ulY *= oneMillion;
		//		ulZ *= 1;
		//
		//		ID = ulX + ulY + ulZ;
		//
		//		// 300, 700, 2400 ->      300,000700,002,400
		//		// -300, 700, -2400 -> 100300,000700,102,400
		//
		//
		//		return ID;
	}


	bool isVertInside(glm::vec3 VertexXYZ)
	{
		if (VertexXYZ.x < minXYZ.x)	
			return false;
		if (VertexXYZ.x > (minXYZ.x + length)) 
			return false;
		if (VertexXYZ.y < minXYZ.y)	
			return false;
		if (VertexXYZ.y > (minXYZ.y + length)) 
			return false;
		if (VertexXYZ.z < minXYZ.z)	
			return false;
		if (VertexXYZ.z > (minXYZ.z + length)) 
			return false;

		// It's inside!

	};
};