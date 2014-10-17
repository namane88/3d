#include "mouse.h"

namespace device 
{
	Mouse::Mouse() : x(0), y(0), xrel(0), yrel(0) {
		memset(buttons, 0, sizeof(buttons));
	}

	void Mouse::onButtonDown(unsigned btn)
	{
		this->buttons[btn] = 1;
	}

	void Mouse::onButtonUp(unsigned btn)
	{
		this->buttons[btn] = 0;
	}

	void Mouse::onMotion(unsigned x, unsigned y,  int xrel, int yrel )
	{
		this->x = x;
		this->y = y;
		this->xrel = xrel;
		this->yrel = yrel;
	}

	void Mouse::setRelative(bool relativity)
	{
		SDL_SetRelativeMouseMode(relativity ? SDL_TRUE : SDL_FALSE);
	}

	void Mouse::setVisibility(bool visibility)
	{
		SDL_ShowCursor(visibility ? SDL_TRUE : SDL_FALSE);
	}
}
