#ifndef MOUSE_H
#define MOUSE_H

#include <cstring>
#include "abstract/mouse_listener.h"
#include <SDL2/SDL.h>

namespace device
{
	class Mouse : public MouseListener
	{
		private:
			bool buttons[0];
			unsigned x, y;
			int xrel, yrel;

		public:
			Mouse();

			void onButtonDown(unsigned);
			void onButtonUp(unsigned);

			void onMotion(unsigned, unsigned, int, int);

			void setRelative(bool);
			void setVisibility(bool);

			unsigned getX() { return x; }
			unsigned getY() { return y; }
			int getXRel() { return xrel; }
			int getYRel() { return yrel; }

			void reset() { xrel = 0; yrel = 0; }

			bool hasMotion() { return xrel !=0 || yrel != 0; }
	};
}

#endif
