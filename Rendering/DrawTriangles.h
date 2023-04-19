#pragma once
#include "Shader.h"

class DrawTriangles
{
public:
	~DrawTriangles();
	void updateVertex(const int index, const float position);
	void drawElements();
	void setupData();
	void addVertex(const float position);
	int getIndexOfCurrentLastVertex();
	void addActiveObject();
	void clear();

protected:
	static const int maxNumberOfVerticies = 60000;
	float positions[maxNumberOfVerticies];
	int indexBehindLastVertex = 0;
	unsigned int indicies[maxNumberOfVerticies / 2];
	int currentLastPoint = 0;
	int numberOfActiveObjects = 0;
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	unsigned int shader;
	Shader shaderObject;
};

