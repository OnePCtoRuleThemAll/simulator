#pragma once
#include "Shape.h"

namespace Shapes
{
	template <typename T>
	class CircleDrawer : 
		Shape<T>
	{
	public:
		CircleDrawer(Geometry2D::Circle<T>& circle);
		~CircleDrawer();

		void rotate(const Geometry2D::Vector<T>& vector) override;
		void translate(const Geometry2D::Point<T>& point) override;

	private:
		void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
		Shader shader;
	};


	template<typename T>
	inline CircleDrawer<T>::CircleDrawer(Geometry2D::Circle<T>& circle)
	{
		this->drawFilledCircle((GLfloat)circle.mCenter->mPositionX, (GLfloat)circle.mCenter->mPositionY, (GLfloat)circle.mRadius);
	}

	template<typename T>
	inline CircleDrawer<T>::~CircleDrawer()
	{
	}

	template<typename T>
	inline void CircleDrawer<T>::rotate(const Geometry2D::Vector<T>& vector)
	{
	}

	template<typename T>
	inline void CircleDrawer<T>::translate(const Geometry2D::Point<T>& point)
	{
	}

	template<typename T>
	inline void CircleDrawer<T>::drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
	{
		ShaderProgramSource source = this->shader.ParseShader("Resources/Shaders/Circle.shader");

		unsigned int shader = this->shader.CreateShader(source.VertexSource, source.FragmentSource);
		glUseProgram(shader);

		int i;
		int triangleAmount = 40; //# of triangles used to draw circle

		//GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * atan(1) * 4;

		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i * twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
	}

}