#ifndef SRC_FRAME_FRAMEINFO_H_
#define SRC_FRAME_FRAMEINFO_H_

#include <SDL2/SDL.h>

#include <iostream>

class FrameInfo {

	unsigned frames;
	Uint32 start_tick, end_tick, previous_tick;

	float delta;

public:
	FrameInfo();
	virtual ~FrameInfo();

	void onStart();
	void onEnd();

	float getFrameDelta() { return delta; }
};

#endif
