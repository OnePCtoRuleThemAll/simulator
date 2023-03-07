#pragma once
#include "Shape.h"

namespace Shapes
{
	template <typename T>
	class TriangleDrawer : Shape
	{
	public:
		TriangleDrawer(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector);
		~TriangleDrawer();

		void rotate(Geometry2D::Vector<T>& vector) override;
		void translate(Geometry2D::Point<T>& point) override;

	};

	template<typename T>
	inline TriangleDrawer<T>::TriangleDrawer(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector)
	{
		positions = new float [6];
	}

	template<typename T>
	inline TriangleDrawer<T>::~TriangleDrawer()
	{
		delete positions;
	}

	template<typename T>
	inline void TriangleDrawer<T>::rotate(Geometry2D::Vector<T>& vector)
	{
	}

	template<typename T>
	inline void TriangleDrawer<T>::translate(Geometry2D::Point<T>& point)
	{
	}

}