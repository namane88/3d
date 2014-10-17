#include "window.h"

namespace display
{

Window::Window(const std::string &title, unsigned width, unsigned height)
	: title(title), width(width), height(height)
{
	this->initialize();	
}

Window::~Window()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
}

void Window::initialize()
{
	if ( ! SDL_WasInit(SDL_INIT_VIDEO)) {
		SDL_Init(SDL_INIT_VIDEO);
	}

	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24);

	SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

	window  = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(window);

	glewExperimental = GL_TRUE;

	GLenum status = glewInit();
	if ( GLEW_OK != status ) {
		throw std::runtime_error(reinterpret_cast<const char *>(glewGetErrorString(status)));
	}
}

void Window::swap()
{
	SDL_GL_SwapWindow(window);
}

}
