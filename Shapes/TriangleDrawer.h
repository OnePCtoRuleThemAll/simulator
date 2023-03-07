#pragma once
#include "Shape.h"

namespace Shapes
{
	template <typename T>
	class TriangleDrawer :
		Shape<T>
	{
	public:
		TriangleDrawer(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector);
		~TriangleDrawer();

		void rotate(const Geometry2D::Vector<T>& vector) override;
		void translate(const Geometry2D::Point<T>& point) override;

	private:
		float positions[6];
		void setupData();
		void drawTriangle();
		unsigned int vao;
		Shader shader;
	};

	template<typename T>
	inline TriangleDrawer<T>::TriangleDrawer(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector)
	{
		positions[0] = -0.015f;
		positions[1] = -0.005f;
		positions[2] = -0.005f;
		positions[3] = 0.045f;
		positions[4] = 0.005f;
		positions[5] = -0.005f;

		this->setupData();
		this->drawTriangle();
	}

	template<typename T>
	inline TriangleDrawer<T>::~TriangleDrawer()
	{
		delete this->positions;
		glDeleteVertexArrays(1, &this->vao);
	}

	template<typename T>
	inline void TriangleDrawer<T>::rotate(const Geometry2D::Vector<T>& vector)
	{
		return;
	}

	template<typename T>
	inline void TriangleDrawer<T>::translate(const Geometry2D::Point<T>& point)
	{
		return;
	}

	template<typename T>
	inline void TriangleDrawer<T>::setupData()
	{
		glCreateVertexArrays(1, &this->vao);
		glBindVertexArray(vao);

		unsigned int vertexBuffer;
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(this->positions), this->positions, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

		unsigned int indicies[] = { 0, 1, 2 };

		unsigned int indexBuffer;
		glCreateBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_DYNAMIC_DRAW);
	}

	template<typename T>
	inline void TriangleDrawer<T>::drawTriangle()
	{
		ShaderProgramSource source = this->shader.ParseShader("Resources/Shaders/Triangle.shader");

		unsigned int shader = this->shader.CreateShader(source.VertexSource, source.FragmentSource);
		glUseProgram(shader);

		glBindVertexArray(this->vao);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}

}