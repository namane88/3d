#ifndef MOUSE_INPUT_LISTENER
#define MOUSE_INPUT_LISTENER

class MouseListener
{
public:
	virtual void onButtonDown(unsigned button) = 0;
	virtual void onButtonUp(unsigned button) = 0;


	virtual void onMotion(unsigned x, unsigned y, int xrel, int yrel) = 0;
};

#endif
