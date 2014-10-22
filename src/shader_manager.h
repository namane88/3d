#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "shader.h"
#include <vector>
#include <string>
#include "util/file.h"

using namespace gl;

class ShaderManager
{
	private:
		std::vector<Shader*> shaders;

		Shader *defaultShader;

		std::string path;

	public:
		ShaderManager();
		~ShaderManager();


		Shader* getDefaultShader();

		Shader* fromFile(const char* vertexShader, const char* fragmentShader);

		void addShader(Shader *shader);

		void setDefaultShader(Shader *shader);

		void setUniformMatrix4(const char*, float *);
};

#endif
