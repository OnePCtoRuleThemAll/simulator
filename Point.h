#pragma once

#include "GeometryBase.h"

namespace Geometry2D 
{
	/// <summary> Struct representing point. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct Point 
		: GeomteryBase
	{
		Point();

		Point(T positionX, T positionY);

		~Point();

		GeomteryBase& operator=(GeomteryBase& other) override;

		GeomteryBase& assign(GeomteryBase& other)override;

		bool operator==(GeomteryBase& other) override;

		bool equals(GeomteryBase& other) override;

		double distanceToPoint(Point& other);


		T mPositionX = 0;
		T mPositionY = 0;
	};
}