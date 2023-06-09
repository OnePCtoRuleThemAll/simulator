#pragma once
#include "Shape.h"

namespace Shapes {
	template <typename T>
	class StaticShape :
		public Shape<T>
	{
	public:
		StaticShape(Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd);
		virtual void draw() = 0;
	};
	template<typename T>
	inline StaticShape<T>::StaticShape(Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd):
		Shape<T>::Shape(worldStart, worldEnd)
	{
	}

}

