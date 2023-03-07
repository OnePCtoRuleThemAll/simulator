#pragma once
#include "../Geometry2D/Geometry2D.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstddef>

namespace Shapes 
{
	template<typename T>
	class Shape
	{
	public:
		virtual ~Shape() = 0;

		virtual void rotate(const Geometry2D::Vector<T>& vector) = 0;
		virtual void translate(const Geometry2D::Point<T>& point) = 0;

	private:
		float* positions[];
		virtual void scale(Geometry2D::Point<T>& point) = 0;
	};
}
