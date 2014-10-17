#ifndef RENDERABLE_H
#define RENDERABLE_H

#include<vector>
#include<GL/glew.h>
#include "math/vec3.h"

class Renderable
{
	private:
		GLuint vao;
		
		std::vector<float> vertices, normals, texCoords, colors;

		GLenum mode;
	
	public:
		Renderable();
		Renderable(std::vector<float>& vertices, std::vector<float>& normals, std::vector<float>& textureCoords);
	
		GLuint setBuffer(GLuint index, std::vector<float>& data, unsigned components);

		Renderable& setMode(GLenum);

		Renderable& addVertex(float, float, float);

		Renderable& addColor(float, float, float);

		virtual ~Renderable();

		void prepare();

		void render();

		void asLine(){ setMode(GL_LINES); }
		void asTriangle(){ setMode(GL_TRIANGLES); }
		void asPoint(){ setMode(GL_POINTS); }

		Renderable& addVertex(const math::Vec3 &v) { return addVertex(v.x, v.y, v.z);  }
		Renderable& addColor(const math::Vec3 &v) { return addVertex(v.x, v.y, v.z);  }
};

#endif
