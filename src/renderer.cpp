#include "renderer.h"

namespace render
{
	Renderer::Renderer()
	{
		glEnable(GL_DEPTH_TEST);

		glPointSize(4.0);
		glLineWidth(3.0);
	}

	void Renderer::clearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::addRenderable(Renderable *element)
	{
		element->prepare();

		queue.push_back(element);
	}

	void Renderer::togglePolygonMode() {
		GLint mode;

		glGetIntegerv(GL_POLYGON_MODE, &mode);

		glPolygonMode( GL_FRONT_AND_BACK, mode == GL_FILL ? GL_LINE : GL_FILL );
	}

	
	void Renderer::update()
	{
		
	}

	void Renderer::render()
	{
		clearScreen();

		for(Renderable *elm : queue) {
			elm->render();
		}
	}

	void Renderer::printRenderInfo()
	{
		std::cout 
		<< "OpenGL: " << glGetString(GL_VERSION) << std::endl
		<< "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	}
}
