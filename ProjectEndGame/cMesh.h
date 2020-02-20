#ifndef _cMesh_HG_
#define _cMesh_HG_

#include <vector>		// "smart array"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

// This structure matches the file, so that our life is
//   simpler and happier, and we all get along.
struct sPlyVertexXYZ_N_UV
{
	float x, y, z;
	float nx, ny, nz;	
	float u, v;		//textures added
	// Add this, too:
	float bi_x, bi_y, bi_z;
	float tan_x, tan_y, tan_z;
	float boneID[4];				// Which bone impacts this vertex
	float boneWeights[4];			// How much does each bone get affected
};

struct sPlyTriangle
{
	unsigned int vert_index_1;
	unsigned int vert_index_2;
	unsigned int vert_index_3;
};

class cMesh
{
public:
	cMesh() {};			// Empty c'tor
	~cMesh() {};		// Empty d'tor
	// Store the vertices
	std::vector<sPlyVertexXYZ_N_UV> vecVertices;

	// Store the triangles
	std::vector<sPlyTriangle> vecTriangles;

};

#endif 
