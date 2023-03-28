#pragma once
#include "Geometry2D/Geometry2D.h"

namespace Geometry2D
{
	/// <summary> Abstract parent class of segments of Polyline and Polygon. </summary>
	template<typename T>
	class PolySegment
	{
	public:

		virtual bool isPointOn(const Point<T>& point) = 0;

		virtual double distancetoPoint(const Point<T>& point) = 0;

		virtual void moveByVector(const Vector<T>& vector) = 0;

	};
}