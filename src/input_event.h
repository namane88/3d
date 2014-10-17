#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

#include <SDL2/SDL.h>
#include <vector>

#include "abstract/key_listener.h"
#include "abstract/mouse_listener.h"

class InputEvent
{
	private:
		SDL_Event event;
		
		std::vector<KeyListener *> keyListeners;
		std::vector<MouseListener *> mouseListeners;

	public:
		InputEvent();

		void update();

		void listen(KeyListener &listener);
		void listen(MouseListener &listener);
};

#endif
