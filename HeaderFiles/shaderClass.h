#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
public:
	// id of the shader
	GLuint ID;
	// builds a shader program from 2 shaders
	Shader(const char* vertexFile, const char* fragmentFile);

	// activates the Shader Program
	void Activate();
	// deletes the Shader Program
	void Delete();
};
#endif