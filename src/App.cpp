#include "App.h"

App::App() : window(nullptr), keyboard(nullptr), mouse(nullptr), renderer(nullptr) {

}

void App::setWindow(Window* window) {
	this->window = window;
}

void App::setKeyboard(Keyboard* keyboard) {
	this->keyboard = keyboard;

	this->inputEventManager.listen(* keyboard);
}

void App::setMouse(Mouse* mouse) {
	this->mouse = mouse;

	this->mouse->setRelative(true);
	this->mouse->setVisibility(true);

	this->inputEventManager.listen(* mouse);
}

void App::setRenderer(Renderer* renderer) {
	this->renderer = renderer;
}

void App::setCamera(Camera *camera) {
	this->camera = camera;
}

Window* App::getWindow() {
	return window;
}

Keyboard* App::getKeyboard() {
	return keyboard;
}

Mouse* App::getMouse() {
	return mouse;
}

Renderer* App::getRenderer() {
	return renderer;
}

Camera* App::getCamera() {
	return camera;
}

FrameInfo& App::getFrameInfo() {
	return frame;
}

InputEvent& App::getInputEventManager() {
	return inputEventManager;
}

void App::onFrameStart() {
	frame.onStart();

	this->mouse->reset();
	this->inputEventManager.update();
}

void App::onFrameEnd() {

	this->renderer->update();
	this->renderer->render();

	this->window->swap();

	frame.onEnd();
}


App::~App() {
}

