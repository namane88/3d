
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

#include "frame/frameinfo.h"

using namespace math;

#define WIN_WIDTH 1500
#define WIN_HEIGHT 900


void update()
{

}

int main(int argc, char **argv)
{

	srand(time(0));

	display::Window window("OpenGL", 1500, 800);
	device::Keyboard keyboard;
	device::Mouse mouse;
	render::Renderer renderer;
	InputEvent event;
	ShaderManager shaderManager;

	mouse.setRelative(true);
	mouse.setVisibility(true);

	event.listen(keyboard);
	event.listen(mouse);

	Camera camera(60.0, (float) WIN_WIDTH / (float) WIN_HEIGHT, 0.01, 1000.0);
	camera.setLocation(0, 0, -2);

	renderer.printRenderInfo();

	shaderManager.fromFile("color.vert", "color_light.frag")->use();

	ModelLoader model("res/models/M4A1/M4A1_tri.obj");

	Renderable map(model.getVertices(), model.getNormals(), model.getTexCoords());

	renderer.addRenderable(&map);


	FrameInfo frame;

	while(1)
	{

		frame.onStart();

		mouse.reset();
		event.update();

		if (keyboard.isKeyDown('q')) 
			break;

		camera.setMovementSpeed(frame.getFrameDelta() * 10.0f);

		if (mouse.hasMotion()) {
			camera.setDirectionFromScreen(mouse.getXRel(), mouse.getYRel());
		}
	
		if (keyboard.isKeyDown('w')) camera.forward();
		if (keyboard.isKeyDown('a')) camera.left();
		if (keyboard.isKeyDown('s')) camera.back();
		if (keyboard.isKeyDown('d')) camera.right();

		shaderManager.getDefaultShader()->setUniformMatrix4( "MVP", camera.getViewMatrix().ref() );
		shaderManager.getDefaultShader()->setUniformMatrix4( "MV", camera.getModelview().ref() );

		update();
		renderer.update();
		renderer.render();

		window.swap();

		frame.onEnd();
	}
}
