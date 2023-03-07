#pragma once
#include "Shape.h"

namespace Shapes
{
	template <typename T>
	class CircleDrawer : Shape
	{
	public:
		CircleDrawer(Geometry2D::Circle<T>& circle);
		~CircleDrawer();

		void rotate(Geometry2D::Vector<T>& vector) override;
		void translate(Geometry2D::Point<T>& point) override;

		void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);

	private:

	};


	template<typename T>
	inline CircleDrawer<T>::CircleDrawer(Geometry2D::Circle<T>& circle)
	{
	}

	template<typename T>
	inline CircleDrawer<T>::~CircleDrawer()
	{
	}

	template<typename T>
	inline void CircleDrawer<T>::rotate(Geometry2D::Vector<T>& vector)
	{
	}

	template<typename T>
	inline void CircleDrawer<T>::translate(Geometry2D::Point<T>& point)
	{
	}

	template<typename T>
	inline void CircleDrawer<T>::drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
	{
		int i;
		int triangleAmount = 20; //# of triangles used to draw circle

		//GLfloat radius = 0.8f; //radius
		GLfloat twicePi = 2.0f * PI;

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