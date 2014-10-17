#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <string>
#include <stdexcept>
#include <iostream>

namespace display
{
	class Window
	{
	private:
		std::string title;
		unsigned width, height;

		SDL_Window *window;
		SDL_GLContext context;

		void initialize();

	public:
		Window(const std::string&, unsigned width, unsigned height);
		~Window();

		void swap();
	};
}

#endif
