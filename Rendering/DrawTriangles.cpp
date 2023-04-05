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

	glUseProgram(shader);

	glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES, this->numberOfActiveObjects*3, GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	this->clear();
}

void DrawTriangles::setupData()
{
	ShaderProgramSource source = this->shaderObject.ParseShader("Resources/Shaders/Triangle.shader");
	this->shader = this->shaderObject.CreateShader(source.VertexSource, source.FragmentSource);

	glCreateVertexArrays(1, &this->vao);
	glBindVertexArray(this->vao);

	glGenBuffers(1, &this->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->positions), this->positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	glCreateBuffers(1, &this->ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->indicies), this->indicies, GL_STATIC_DRAW);
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

void DrawTriangles::clear()
{
	glDeleteVertexArrays(1, &this->vao);
	glDeleteBuffers(1, &this->vbo);
	glDeleteBuffers(1, &this->ebo);
	glUseProgram(0);
	glDeleteProgram(this->shader);
}
