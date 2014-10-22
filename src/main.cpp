
#include "window.h"
#include "input_event.h"
#include "keyboard.h"
#include "mouse.h"
#include "renderer.h"
#include "model_loader.h"
#include "renderable.h"
#include "math/mat4.h"
#include "camera.h"
#include "shader_manager.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <time.h>
#include <vector>
#include <memory>

#include "App.h"

using namespace math;

#define WIN_WIDTH 1500
#define WIN_HEIGHT 900


void update(App &app)
{
	device::Keyboard &keyboard = * app.getKeyboard();
	device::Mouse &mouse = * app.getMouse();
	Camera &camera = * app.getCamera();

	camera.setMovementSpeed(app.getFrameInfo().getFrameDelta() * 10.0f);

	if (mouse.hasMotion()) {
		camera.setDirectionFromScreen(mouse.getXRel(), mouse.getYRel());
	}

	if (keyboard.isKeyDown('w')) camera.forward();
	if (keyboard.isKeyDown('a')) camera.left();
	if (keyboard.isKeyDown('s')) camera.back();
	if (keyboard.isKeyDown('d')) camera.right();

	if (keyboard.isKeyDown('p'))
	{
		app.getRenderer()->togglePolygonMode();
		keyboard.onKeyUp('p');
	}
}

int main(int argc, char **argv)
{

	srand(time(0));

	App app;

	display::Window window("OpenGL", 1500, 800);
	app.setWindow(&window);

	device::Keyboard keyboard;
	app.setKeyboard(&keyboard);

	device::Mouse mouse;
	app.setMouse(&mouse);

	render::Renderer renderer;
	app.setRenderer(&renderer);

	Camera camera(60.0, (float) WIN_WIDTH / (float) WIN_HEIGHT, 0.01, 1000.0);
	app.setCamera(&camera);

	ShaderManager shaderManager;
	shaderManager.fromFile("color.vert", "color_light.frag")->use();
	shaderManager.fromFile("color.vert", "color.frag");

	ModelLoader model("res/models/M4A1/M4A1_tri.obj");
	Renderable map(model.getVertices(), model.getNormals(), model.getTexCoords());
	app.getRenderer()->addRenderable(& map);

	app.getRenderer()->printRenderInfo();

	while( app.isRunning() )
	{
		app.onFrameStart();

		update(app);

		shaderManager.setUniformMatrix4("MVP", camera.getViewMatrix().ref());
		shaderManager.setUniformMatrix4("MV", camera.getModelview().ref());

		app.onFrameRender();

		app.onFrameEnd();
	}
}
