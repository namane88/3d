#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL2/SDL.h>
#include "abstract/key_listener.h"

#define MAX_KEYS SDL_NUM_SCANCODES

namespace device
{
	class Keyboard : public KeyListener
	{
		private:
			bool keys[ SDL_NUM_SCANCODES ];

		public:
			Keyboard();

			void onKeyDown(unsigned key);
			void onKeyUp(unsigned key);

			bool isKeyDown(unsigned key);
	};
}

#endif
