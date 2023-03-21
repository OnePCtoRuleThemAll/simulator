#include "DrawTriangles.h"

DrawTriangles::~DrawTriangles()
{
}

void DrawTriangles::updateVertex(const int index, const float position)
{
	this->positions[index] = position;
}

void DrawTriangles::drawElements()
{
	this->setupData();
	ShaderProgramSource source = this->shader.ParseShader("Resources/Shaders/Triangle.shader");

	unsigned int shader = this->shader.CreateShader(source.VertexSource, source.FragmentSource);
	glUseProgram(shader);

	glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES, this->numberOfActiveObjects*3, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

void DrawTriangles::setupData()
{
	glCreateVertexArrays(1, &this->vao);
	glBindVertexArray(vao);

	unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->positions), this->positions, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	unsigned int indexBuffer;
	glCreateBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indicies), this->indicies, GL_DYNAMIC_DRAW);
}

void DrawTriangles::addVertex(const float position)
{
	this->positions[this->indexBehindLastVertex] = position;
	this->indexBehindLastVertex++;
	this->indicies[this->currentLastPoint] = this->currentLastPoint;
	this->currentLastPoint++;
}

int DrawTriangles::getIndexOfCurrentLastVertex()
{
	return this->indexBehindLastVertex;
}

void DrawTriangles::addActiveObject()
{
	this->numberOfActiveObjects++;
}
