#include "cMesh.h"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include <vector>
#include <map>

#include "AABBStuff.h"
#include <string>

// This will hold the AABBs for 
std::map<unsigned long long /*ID*/, cAABB*> g_mapAABBs_World;

// Take the space station model
// Figure out which triangles are in which AABB

void CalcAABBsForMeshModel(cMesh& theMesh)
{
	// For the space station, I'll make a size of -5,000 to 5,000
	const float WorldSize = 1000.0f;
	const float WorldHeight = 200.0f;
	const float AABBsize = 25.0f;
	unsigned int totalUnits = 0;
	unsigned int totalAabbSize = AABBsize * AABBsize * AABBsize;
	unsigned long long idAtVeryMin = 0;
	bool aabbAtOrigin = false;
	std::vector<unsigned long long> tempIDTestVec;
	int howManyDoubleIDs = 0;
	for (float x = -WorldSize; x <= WorldSize; x += AABBsize)
	{
		for (float z = -WorldSize; z <= WorldSize; z += AABBsize)
		{
			for (float y = -WorldHeight; y <= WorldHeight; y += AABBsize)
			{
				cAABB* pAABB = new cAABB();
				pAABB->minXYZ.x = x;
				pAABB->minXYZ.y = y;
				pAABB->minXYZ.z = z;
				pAABB->length = 25.0f;

				// Store a pointer to the mesh
				pAABB->pTheMesh = &theMesh;

				if (pAABB->minXYZ.x < -999.0f && pAABB->minXYZ.y < -199.0f && pAABB->minXYZ.z < -999.0f)
				{
					aabbAtOrigin = true;
					idAtVeryMin = pAABB->getID();
				}

				unsigned long long ID = pAABB->getID();

				tempIDTestVec.push_back(ID);

				if (tempIDTestVec.size() > 0)
				{
					for (int i = 0; i < tempIDTestVec.size(); i++)
					{
						if (ID == tempIDTestVec.at(i))
						{
							howManyDoubleIDs++;
						}
					}
				}

				::g_mapAABBs_World.insert({ ID, pAABB });
				totalUnits += totalAabbSize;
			}
		}		
	}
	howManyDoubleIDs;
	cAABB* pTestAABB = g_mapAABBs_World.find(idAtVeryMin)->second;

	// Check which AABB this triangle is in

	for (std::vector<sPlyTriangle>::iterator itTri = theMesh.vecTriangles.begin(); itTri != theMesh.vecTriangles.end(); itTri++)
	{
		glm::vec3 v1;
		sPlyVertexXYZ_N_UV pv1;
		v1.x = theMesh.vecVertices[itTri->vert_index_1].x;
		pv1.x = theMesh.vecVertices[itTri->vert_index_1].x;
		v1.y = theMesh.vecVertices[itTri->vert_index_1].y;
		pv1.y = theMesh.vecVertices[itTri->vert_index_1].y;
		v1.z = theMesh.vecVertices[itTri->vert_index_1].z;
		pv1.z = theMesh.vecVertices[itTri->vert_index_1].z;
		pv1.nx = theMesh.vecVertices[itTri->vert_index_1].nx;
		pv1.ny = theMesh.vecVertices[itTri->vert_index_1].ny;
		pv1.nz = theMesh.vecVertices[itTri->vert_index_1].nz;
		glm::vec3 v2;
		sPlyVertexXYZ_N_UV pv2;
		v2.x = theMesh.vecVertices[itTri->vert_index_2].x;
		pv2.x = theMesh.vecVertices[itTri->vert_index_2].x;
		v2.y = theMesh.vecVertices[itTri->vert_index_2].y;
		pv2.y = theMesh.vecVertices[itTri->vert_index_2].y;
		v2.z = theMesh.vecVertices[itTri->vert_index_2].z;
		pv2.z = theMesh.vecVertices[itTri->vert_index_2].z;
		pv2.nx = theMesh.vecVertices[itTri->vert_index_2].nx;
		pv2.ny = theMesh.vecVertices[itTri->vert_index_2].ny;
		pv2.nz = theMesh.vecVertices[itTri->vert_index_2].nz;
		glm::vec3 v3;
		sPlyVertexXYZ_N_UV pv3;
		v3.x = theMesh.vecVertices[itTri->vert_index_3].x;
		pv3.x = theMesh.vecVertices[itTri->vert_index_3].x;
		v3.y = theMesh.vecVertices[itTri->vert_index_3].y;
		pv3.y = theMesh.vecVertices[itTri->vert_index_3].y;
		v3.z = theMesh.vecVertices[itTri->vert_index_3].z;
		pv3.z = theMesh.vecVertices[itTri->vert_index_3].z;
		pv3.nx = theMesh.vecVertices[itTri->vert_index_3].nx;
		pv3.ny = theMesh.vecVertices[itTri->vert_index_3].ny;
		pv3.nz = theMesh.vecVertices[itTri->vert_index_3].nz;

		// Is the triangle too big?? 
		// Is the length of ANY side longer than the AABB (longer than a half the AABB)

		// Slice the triangle. 


		// Get the ID of the AABB that this vertex is inside of 
		unsigned long long ID_AABB_V1 = cAABB::get_ID_of_AABB_I_Might_Be_In(v1);
		unsigned long long ID_AABB_V2 = cAABB::get_ID_of_AABB_I_Might_Be_In(v2);
		unsigned long long ID_AABB_V3 = cAABB::get_ID_of_AABB_I_Might_Be_In(v3);

		// Add this triangle to that box
		// sPlyTriangle& refTriangle = *itTri;
		// so &refTriangle returns the pointer to the triangle in the vector

		std::map<unsigned long long, cAABB* >::iterator itAABB = ::g_mapAABBs_World.find(ID_AABB_V1);

		if (itAABB == ::g_mapAABBs_World.end())
		{
			bool ohNO = true;
		}
		if (g_mapAABBs_World.find(ID_AABB_V1)->second)
		{
			::g_mapAABBs_World.find(ID_AABB_V1)->second->vecTriangles.push_back(&(*itTri));
			::g_mapAABBs_World.find(ID_AABB_V1)->second->triPosition.push_back(pv1);
		}
		if (g_mapAABBs_World.find(ID_AABB_V2)->second)
		{
			::g_mapAABBs_World.find(ID_AABB_V2)->second->vecTriangles.push_back(&(*itTri));
			::g_mapAABBs_World.find(ID_AABB_V2)->second->triPosition.push_back(pv2);
		}
		if (g_mapAABBs_World.find(ID_AABB_V3)->second)
		{
			::g_mapAABBs_World.find(ID_AABB_V3)->second->vecTriangles.push_back(&(*itTri));
			::g_mapAABBs_World.find(ID_AABB_V3)->second->triPosition.push_back(pv3);
		}
	}

	//	unsigned long long ID = get_ID_of_AABB_I_Might_Be_In(glm::vec3 minXYZ, glm::vec3 testLocation)
	int mapSize = g_mapAABBs_World.size();
	return;
}

glm::vec3 cAABB::getMaxXYZ(glm::vec3 minXYZ, float length)
{
	glm::vec3 max = minXYZ + length;

	return max;
}

glm::vec3 cAABB::getCentre()
{
	glm::vec3 center = this->minXYZ + (this->length / 2);

	return center;
}

std::vector<glm::vec3> cAABB::getVecBoxPoints()
{
	std::vector<glm::vec3> pointVec;

	pointVec.push_back(this->minXYZ);
	pointVec.push_back(glm::vec3(this->minXYZ.x + this->length, this->minXYZ.y, this->minXYZ.z));
	pointVec.push_back(glm::vec3(this->minXYZ.x, this->minXYZ.y, this->minXYZ.z + this->length));
	pointVec.push_back(glm::vec3(this->minXYZ.x + this->length, this->minXYZ.y, this->minXYZ.z + this->length));

	pointVec.push_back(glm::vec3(this->minXYZ.x, this->minXYZ.y + this->length, this->minXYZ.z));
	pointVec.push_back(glm::vec3(this->minXYZ.x + this->length, this->minXYZ.y + this->length, this->minXYZ.z));
	pointVec.push_back(glm::vec3(this->minXYZ.x, this->minXYZ.y + this->length, this->minXYZ.z + this->length));
	pointVec.push_back(glm::vec3(this->minXYZ.x + this->length, this->minXYZ.y + this->length, this->minXYZ.z + this->length));

	return pointVec;
}