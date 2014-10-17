#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>

#include <stdexcept>
#include <iostream>
#include <string>

#include <vector>
#include "renderable.h"

namespace render
{
	class Renderer
	{	
		private:
			std::vector<Renderable *> queue;
		public:
			Renderer();

			void addRenderable(Renderable*);

			void update();

			void render();

			void clearScreen();

			void printRenderInfo();
	};
}

#endif
