#include "cModelLoader.h"

#include <assimp/Importer.hpp>		// To load from a file
#include <assimp/scene.h>			// To handle the scene, mesh, etc. object
#include <assimp/postprocess.h>		// For generating normals, etc.
#include <iostream>

// This is the assimp version of the LoadPlyModel()


bool cModelLoader::LoadModel_Assimp(std::string filename, cMesh& theMesh, std::string& errors)
{

	const aiScene* pScene = NULL;

	// This thing will go away when this function returns.
	Assimp::Importer mImporter;

	unsigned int Flags = aiProcess_Triangulate |
		aiProcess_OptimizeMeshes |
		aiProcess_OptimizeGraph |
		aiProcess_JoinIdenticalVertices |
		aiProcess_GenNormals |
		aiProcess_CalcTangentSpace;

	pScene = mImporter.ReadFile(filename.c_str(), Flags);

	errors.clear();
	errors.append(mImporter.GetErrorString());
	if (errors != "")
	{
		delete pScene;
		return false;
	}

	// NOTE: I'm only loading 1 mesh
	std::cout << std::endl;
	std::cout << "From assimp loader:" << std::endl;
	std::cout << "numMeshes = " << pScene->mNumMeshes << std::endl;

	// Load mesh 1

	for (int vertIndex = 0; vertIndex != pScene->mMeshes[0]->mNumVertices; vertIndex++)
	{
		sPlyVertexXYZ_N_UV curVertex;

		curVertex.x = pScene->mMeshes[0]->mVertices[vertIndex].x;
		curVertex.y = pScene->mMeshes[0]->mVertices[vertIndex].y;
		curVertex.z = pScene->mMeshes[0]->mVertices[vertIndex].z;

		curVertex.nx = pScene->mMeshes[0]->mNormals[vertIndex].x;
		curVertex.ny = pScene->mMeshes[0]->mNormals[vertIndex].y;
		curVertex.nz = pScene->mMeshes[0]->mNormals[vertIndex].z;

		// mTextureCoords[0] is the 1st "set" of coords at this vertex
		// (each vertex can hanve up to 8 sets of coordinates)
		curVertex.u = pScene->mMeshes[0]->mTextureCoords[0][vertIndex].x;
		curVertex.v = pScene->mMeshes[0]->mTextureCoords[0][vertIndex].y;

		theMesh.vecVertices.push_back(curVertex);
	}

	std::cout << "Loaded vertices" << std::endl;

	unsigned int triIndex = 0;				// This goes up by 1 for each triangle
	//unsigned int triIndexOneDArray = 0;		// This goes up by 3 for each triangle
	for (; triIndex != pScene->mMeshes[0]->mNumFaces; triIndex++)
	{
		sPlyTriangle curTri;

		// Each face has another array for each index in the model

		curTri.vert_index_1 = pScene->mMeshes[0]->mFaces[triIndex].mIndices[0];
		curTri.vert_index_2 = pScene->mMeshes[0]->mFaces[triIndex].mIndices[1];
		curTri.vert_index_3 = pScene->mMeshes[0]->mFaces[triIndex].mIndices[2];

		theMesh.vecTriangles.push_back(curTri);
	}
	
	std::cout << "Loaded faces" << std::endl;

	//delete pScene;
	mImporter.FreeScene();
	return true;
}