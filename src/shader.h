#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <stdexcept>
#include <GL/glew.h>

#include <iostream>

namespace gl 
{

class Shader
{
private:
	// Program id
	GLuint id;

	GLuint makeShader(std::string &source, GLenum type);

	void initialize(std::string &, std::string &);

	void checkShader(GLuint id, const std::string& type);

public:
	Shader(std::string &vertexSource, std::string &fragmentSource);
	~Shader();

	GLuint getId();

	void use();

	GLint getAttribLocation(const char *name);
	GLint getUniformLocation(const char *name);

	void setUniformMatrix4( const char *name, float *);
};

}

#endif
