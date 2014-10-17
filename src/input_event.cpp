#include "input_event.h"

InputEvent::InputEvent()
{
	
}


void InputEvent::update()
{
	while (SDL_PollEvent(&event)) 
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:
			case SDL_KEYUP:

				for(auto &listener : keyListeners) {
					event.type == SDL_KEYDOWN ?
						listener->onKeyDown(event.key.keysym.sym) :
						listener->onKeyUp(event.key.keysym.sym);
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:

				for(auto &listener : mouseListeners) {
					event.type == SDL_MOUSEBUTTONDOWN ?
						listener->onButtonDown(event.button.button) :
						listener->onButtonUp(event.button.button);
				}
			break;

			case SDL_MOUSEMOTION:

				for(auto &listener : mouseListeners) {
					listener->onMotion(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);
				}
			break;
		}
	}
}


void InputEvent::listen(KeyListener &listener)
{
	keyListeners.push_back(&listener);
}

void InputEvent::listen(MouseListener &listener)
{
	mouseListeners.push_back(&listener);
}
