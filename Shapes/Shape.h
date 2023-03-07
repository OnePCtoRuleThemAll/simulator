#pragma once
#include "../Geometry2D/Geometry2D.h"
#include "../Rendering/Shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstddef>
#include <math.h>

namespace Shapes 
{
	template<typename T>
	class Shape
	{
	public:

		virtual void rotate(const Geometry2D::Vector<T>& vector) = 0;
		virtual void translate(const Geometry2D::Point<T>& point) = 0;

	protected:
		//virtual void scale(Geometry2D::Point<T>& point) = 0;
	};
}
