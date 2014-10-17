#include "shader_manager.h"

ShaderManager::ShaderManager() : defaultShader(nullptr) {
	path = "res/shaders/";
}

ShaderManager::~ShaderManager()
{
	for(Shader *s : shaders)
		delete s;
}


Shader* ShaderManager::getDefaultShader()
{
	return defaultShader;
}

Shader* ShaderManager::fromFile(const char* vertShader, const char* fragShader)
{
	std::string 
	vertSource = util::File::contents( (path + vertShader).c_str() ),
	fragSource = util::File::contents( (path + fragShader).c_str() );

	Shader *shader = new Shader(vertSource, fragSource);

	addShader(shader);

	return shader;
}

void ShaderManager::addShader(Shader *shader)
{
	if ( ! shader) 	return;

	for( Shader *s : shaders )
		if (shader == s )
			return;

	shaders.push_back(shader);	

	if ( ! getDefaultShader()) setDefaultShader(shader);
}

void ShaderManager::setDefaultShader(Shader *shader)
{
	defaultShader = shader;
}
