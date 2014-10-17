#include "keyboard.h"

namespace device
{

#define GETKEY(x) SDL_GetScancodeFromKey(x)

Keyboard::Keyboard()
{
	memset(keys, 0, sizeof(keys));
}

void Keyboard::onKeyDown(unsigned key)
{
	keys[GETKEY(key)] = 1;
}

void Keyboard::onKeyUp(unsigned key)
{
	keys[GETKEY(key)] = 0;
}


bool Keyboard::isKeyDown(unsigned key)
{
	return keys[GETKEY(key)] == 1;
}

}
