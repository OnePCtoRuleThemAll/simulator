#pragma once
#include "StaticShape.h"

namespace Shapes
{
	template <typename T>
	class CircleDrawer : 
		StaticShape<T>
	{
	public:
		CircleDrawer(Geometry2D::Circle<T>& circle, Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd);
		~CircleDrawer();

	private:
		void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
		Shader shader;
	};


	template<typename T>
	inline CircleDrawer<T>::CircleDrawer(Geometry2D::Circle<T>& circle,	Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd):
		StaticShape<T>::StaticShape(worldStart, worldEnd)
	{
		this->drawFilledCircle((GLfloat)circle.mCenter->mPositionX, (GLfloat)circle.mCenter->mPositionY, (GLfloat)circle.mRadius);
	}

	template<typename T>
	inline CircleDrawer<T>::~CircleDrawer()
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