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

		Point(Point<T>& other);

		~Point();

		GeomteryBase& assign(GeomteryBase& other)override;

		bool equals(GeomteryBase& other) override;

		T mPositionX;
		T mPositionY;
	};

	double distanceBetweenPoints(Point<T>& point1, Point<T>& point2);

	double distanceBetweenPoints(Point<T>& point1, Point<T>& point2) {
		return sqrt(pow(point1. - x1, 2) + pow(y2 - y1, 2) * 1.0);
	}

	template<typename T>
	inline Point<T>::Point()
	{
		mPositionX = 0;
		mPositionY = 0;
	}

	template<typename T>
	inline Point<T>::Point(T positionX, T positionY)
	{
		mPositionX = positionX;
		mPositionY = positionY;
	}

	template<typename T>
	inline Point<T>::Point(Point<T>& other)
	{
		mPositionX = other.mPositionX;
		mPositionY = other.mPositionY;
	}
	template<typename T>
	inline Point<T>::~Point()
	{
		mPositionX = 0;
		mPositionY = 0;
	}
}