#ifndef SRC_APP_H_
#define SRC_APP_H_

#include "window.h"
#include "keyboard.h"
#include "mouse.h"
#include "renderer.h"
#include "camera.h"
#include "frame/frameinfo.h"
#include "input_event.h"


using namespace display;
using namespace device;
using namespace render;

class App {

	Window *window;
	Keyboard *keyboard;
	Mouse *mouse;
	Renderer *renderer;
	Camera *camera;
	FrameInfo frame;
	InputEvent inputEventManager;

	bool running;

public:
	App();
	virtual ~App();

	void setWindow(Window* window);
	void setKeyboard(Keyboard* keyboard);
	void setMouse(Mouse* mouse);
	void setRenderer(Renderer* renderer);
	void setCamera(Camera *camera);

	Window* getWindow();
	Keyboard* getKeyboard();
	Mouse* getMouse();
	Renderer* getRenderer();
	Camera *getCamera();

	FrameInfo& getFrameInfo();
	InputEvent& getInputEventManager();

	void onFrameStart();

	void onFrameRender();

	void onFrameEnd();

	bool isRunning();
};

#endif
