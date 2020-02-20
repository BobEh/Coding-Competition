#include "cShaderManager.h"
#include "GLCommon.h"		// glfw.h, etc. (openGL.h)
#include <iostream>

cShaderManager::cShader::cShader()
{
	this->ID = 0;
	this->shaderType = cShader::UNKNOWN;
	return;
}

cShaderManager::cShader::~cShader() 
{
	return;
}

std::string cShaderManager::cShader::getShaderTypeString(void)
{
	switch ( this->shaderType )
	{
	case cShader::VERTEX_SHADER:
		return "VERTEX_SHADER";
		break;
	case cShader::FRAGMENT_SHADER:
		return "FRAGMENT_SHADER";
		break;
	case cShader::UNKNOWN:
	default:
		return "UNKNOWN_SHADER_TYPE";
		break;
	}
	// Should never reach here...
	return "UNKNOWN_SHADER_TYPE";
}


//// TODO: For the students to do, because it's FUN, FUN, FUN
//std::map< std::string /*name of uniform variable*/,
//		    unsigned int /* uniform location ID */ > 
//						mapUniformName_to_UniformLocation;

// Look up the uniform inside the shader, then save it, if it finds it
bool cShaderManager::cShaderProgram::LoadUniformLocation(std::string variableName)
{
	// 
	GLint uniLocation = glGetUniformLocation(this->ID, 
											 variableName.c_str() );
	// Did it find it (not -1)
	if ( uniLocation == -1 )
	{	// Nope.
		return false;
	}
	// Save it
	this->mapUniformName_to_UniformLocation[variableName.c_str()] = uniLocation;

	return true;	
}

// Look up the uniform location and save it.
int cShaderManager::cShaderProgram::getUniformID_From_Name(std::string name)
{
	std::map< std::string /*name of uniform variable*/,
			  int /* uniform location ID */ >::iterator 
		itUniform = this->mapUniformName_to_UniformLocation.find(name);

	if ( itUniform == this->mapUniformName_to_UniformLocation.end() )
	{
		return -1;		// OpenGL uniform not found value
	}

	return itUniform->second;		// second if the "int" value
}

void cShaderManager::cShaderProgram::LoadActiveUniforms(void)
{
	// Find out the max size of the buffer we need.
	int maxNameSize = 0;
	glGetProgramiv(this->ID, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxNameSize);
	std::cout << "Max uniform name size is " << maxNameSize << std::endl;

	// Create a buffer of this max size
	char* uniformName = new char[maxNameSize];
	// Clear it
	memset(uniformName, 0, maxNameSize);

	// How many uniforms?
	int numberOfActiveUniforms = 0;
	glGetProgramiv(this->ID, GL_ACTIVE_UNIFORMS, &numberOfActiveUniforms);
	std::cout << "There are " << numberOfActiveUniforms << " active uniforms" << std::endl;

	for (int index = 0; index < numberOfActiveUniforms; index++)
	{
		const int BUFFERSIZE = 1000;
		char myBuffer[BUFFERSIZE] = { 0 };

		GLsizei numCharWritten = 0;
		GLint sizeOfVariable = 0;
		GLenum uniformType = 0;
		memset(uniformName, 0, maxNameSize);

		glGetActiveUniform(this->ID, index, BUFFERSIZE, &numCharWritten, &sizeOfVariable, &uniformType, uniformName);
	}
}

int cShaderManager::cShaderProgram::getUniformLocID(std::string uniformname)
{
	std::map<std::string /*uniform name*/, int /*uniform location*/>::iterator itUniform = map_UniformNameToLocID.begin();

	if (itUniform != map_UniformNameToLocID.end())
	{
		return itUniform->second;
	}
}