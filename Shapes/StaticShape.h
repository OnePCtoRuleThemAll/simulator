#pragma once
#include "Shape.h"

namespace Shapes {
	template <typename T>
	class StaticShape :
		Shape<T>
	{
	public:
		StaticShape(Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd);
	};
	template<typename T>
	inline StaticShape<T>::StaticShape(Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd):
		Shape<T>::Shape(worldStart, worldEnd)
	{
	}
}

