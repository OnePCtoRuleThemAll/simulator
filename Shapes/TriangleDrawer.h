#pragma once
#include "Shape.h"
#include "../Rendering/DrawTriangles.h"

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

	protected:
		float positions[6];
		int startIndex;
		DrawTriangles* pointerToDrawerObject;
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
	}

	template<typename T>
	inline TriangleDrawer<T>::~TriangleDrawer()
	{
		delete this->positions;
	}

	template<typename T>
	inline void TriangleDrawer<T>::rotate(const Geometry2D::Vector<T>& vector)
	{

	}

	template<typename T>
	inline void TriangleDrawer<T>::translate(const Geometry2D::Point<T>& point)
	{

	}

}