
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

using namespace math;

#define WIN_WIDTH 1500
#define WIN_HEIGHT 900

std::vector<std::shared_ptr<Renderable>> renderables;

void addLine(render::Renderer &renderer, Vec3 p1, Vec3 p2, Vec3 color)
{
	Renderable *line = new Renderable;

	line->addVertex(p1).addVertex(p2).addColor(color.x, color.y, color.z).addColor(color.x, color.y, color.z).asLine();
	renderables.push_back(std::shared_ptr<Renderable>(line));
}

Renderable gline1;

void triangleIntersectionTest( render::Renderer &renderer, Vec3 &v1, Vec3 &v2, Vec3 &v3 )
{
	Vec3 p1 (4,4,4), p2(-1,-1,-1);
	Vec3 v12 	= v2 - v1;
	Vec3 v13 	= v3 - v1;
	Vec3 n 		= v12.cross(v13);

	Vec3 p12	= p2 - p1;
	Vec3 p1_v1	= v1 - p1;

	Vec3 p1_projection = p1 + p12 * (n.dot(p1_v1) / n.dot(p12));

	addLine(renderer, p1, p2, Vec3(1,0,0));
	addLine(renderer, p1, p1_projection, Vec3(1,1,0));


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

	shaderManager.fromFile("color.vert", "color.frag")->use();

	glPointSize(5.0);
	glLineWidth(2.0);

	Vec3 v1(-2, 0, 0), v2(+5, 0, 0.5), v3(0, +1, 0);

	Renderable triangle;
	Renderable line1, line2, line3;

	triangle.addVertex(v1).addVertex(v2).addVertex(v3).addColor(1,0,0).addColor(0,1,0).addColor(0,0,1).asTriangle();

	triangleIntersectionTest(renderer, v1, v2, v3);

	renderer.addRenderable(&triangle);

	for(std::shared_ptr<Renderable> r : renderables)
		renderer.addRenderable(r.get());


	while(1)
	{
		mouse.reset();

		event.update();

		if (keyboard.isKeyDown('q')) 
			break;

		if (mouse.hasMotion()) {
			camera.setDirectionFromScreen(mouse.getXRel(), mouse.getYRel());
		}
	
		if (keyboard.isKeyDown('w')) camera.forward();
		if (keyboard.isKeyDown('a')) camera.left();
		if (keyboard.isKeyDown('s')) camera.back();
		if (keyboard.isKeyDown('d')) camera.right();

		shaderManager.getDefaultShader()->setUniformMatrix4( "MVP", camera.getViewMatrix().ref() );
		shaderManager.getDefaultShader()->setUniformMatrix4( "MV", camera.getModelview().ref() );

		renderer.update();

		renderer.render();

		window.swap();
	}
}
