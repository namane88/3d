#ifndef KEY_INPUT_LISTENER_H
#define KEY_INPUT_LISTENER_H

class KeyListener
{
public:
	virtual void onKeyDown(unsigned key) = 0;
	virtual void onKeyUp(unsigned key) = 0;

	virtual bool isKeyDown(unsigned key) = 0;
};

#endif
