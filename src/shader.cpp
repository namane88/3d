#include "shader.h"


namespace gl
{

	Shader::Shader(std::string &vertexSource, std::string &fragmentSource)
	{
		id = glCreateProgram();	

		this->initialize(vertexSource, fragmentSource);
	}

	Shader::~Shader() {
		if (glIsProgram(id)) glDeleteProgram(id);
	}


	void Shader::initialize(std::string &vsource, std::string &fsource)
	{
		GLuint vid = makeShader(vsource, GL_VERTEX_SHADER);
		GLuint fid = makeShader(fsource, GL_FRAGMENT_SHADER);

		glAttachShader(id, vid);
		glAttachShader(id, fid);

		glBindAttribLocation(id, 0, "vertex");
		glBindAttribLocation(id, 1, "normal");
		glBindAttribLocation(id, 2, "texcoord");
		glBindAttribLocation(id, 3, "color");

		glLinkProgram(id);

		checkShader(id, "program");

		glDeleteShader(vid);
		glDeleteShader(fid);
	}

	GLuint Shader::makeShader(std::string &source, GLenum type)
	{
		GLuint sid = glCreateShader(type);
		const GLchar *s = source.c_str();
		GLint len = source.length();

		glShaderSource(sid, 1, &s, &len);

		glCompileShader(sid);

		checkShader(sid, "shader");

		return sid;
	}

	void Shader::checkShader(GLuint sid, const std::string& type)
	{
		std::string err;
		GLsizei size = 64*3;
		char buffer[size];

		type == "program" ? 
			glGetProgramInfoLog(sid, size, &size, buffer) :
			glGetShaderInfoLog(sid, size, &size, buffer);

		if (size) 
		{
			// avoid throwing exceptions on warnings
			err = buffer;

			std::cerr << err << std::endl;
			if ( err.find("ERROR:") != std::string::npos ) {
				throw std::runtime_error(buffer);
			}
		}
	}

	void Shader::use() {
		glUseProgram(id);
	}

	GLint Shader::getAttribLocation(const char *name) {
		return glGetAttribLocation(id, name);
	}

	GLint Shader::getUniformLocation(const char *name){
		return glGetUniformLocation(id, name);
	}

	void Shader::setUniformMatrix4( const char *name, float *value) {
		glUniformMatrix4fv( getUniformLocation(name), 1, GL_FALSE, value); 
	}

	GLuint Shader::getId() {
		return id;
	}
}
