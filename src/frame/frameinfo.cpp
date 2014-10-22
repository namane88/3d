#include "frameinfo.h"

FrameInfo::FrameInfo() : frames(0), start_tick(0), end_tick(0), delta(0.0), previous_tick(0.0) {}

void FrameInfo::onStart() {
	frames++;

	start_tick = SDL_GetTicks();

	delta = (start_tick - previous_tick) / 1000.0f;

	previous_tick = start_tick;
}

void FrameInfo::onEnd() {
	if (frames == 60) {
		frames = 0;
	}

	end_tick = SDL_GetTicks();
}

FrameInfo::~FrameInfo() {
}

