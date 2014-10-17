#include "renderable.h"


Renderable::Renderable() : vao(0), mode(GL_TRIANGLES) {}
Renderable::~Renderable() {
	if (vao)
		glDeleteVertexArrays(1, &vao);
}

Renderable::Renderable(std::vector<float>& vertices, std::vector<float>& normals, std::vector<float>& textureCoords) : vao(0), mode(GL_TRIANGLES)
{
	this->vertices = vertices;
	this->normals = normals;
	this->texCoords = textureCoords;
}


Renderable& Renderable::addVertex(float x, float y, float z)
{
	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);

	return *this;
}

Renderable& Renderable::addColor(float r, float g, float b)
{
	colors.push_back(r);
	colors.push_back(g);
	colors.push_back(b);

	return *this;
}


Renderable& Renderable::setMode(GLenum mode)
{
	this->mode = mode;

	return *this;
}

GLuint Renderable::setBuffer(GLuint index, std::vector<float>& data, unsigned components)
{
	GLuint bufferId;
	
	glGenBuffers(1, &bufferId);

	glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, components, GL_FLOAT, GL_FALSE, 0, 0);

	return bufferId;
}

void Renderable::prepare()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// vertices
	setBuffer(0, vertices, 3);

	// normals
	if (normals.size())
		setBuffer(1, normals, 3);


	// texture coordinates
	if (texCoords.size())
		setBuffer(2, texCoords, 2);

	// colors
	if (colors.size())
		setBuffer(3, colors, 3);

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderable::render()
{
	glBindVertexArray(vao);

	glDrawArrays(mode, 0, vertices.size() / 3);

	glBindVertexArray(0);
}