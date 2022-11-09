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

	template<typename T>
	inline GeomteryBase& Point<T>::assign(GeomteryBase& other)
	{
		if(this != &other)
		{
			Point<T>& otherPoint = dynamic_cast<Point<T>&>(other);
			mPositionX = otherPoint.mPositionX;
			mPositionY = otherPoint.mPositionY;
		}

		return *this;
	}

	template<typename T>
	inline bool Point<T>::equals(GeomteryBase& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			Point<T>* otherPoint = dynamic_cast<Point<T>*>(&other);
			if (otherPoint != nullptr && otherPoint->mPositionX == mPositionX && otherPoint->mPositionY == mPositionY) {
			return true;
			}
		}
		return false;
	}

	template<typename T>
	double distanceBetweenPoints(Point<T>& point1, Point<T>& point2);

	template<typename T>
	double distanceBetweenPoints(Point<T>& point1, Point<T>& point2) {
		return sqrt(pow(point1.mPositionX - point2.mPositionX, 2) + pow(point1.mPositionY - point2.mPositionY, 2) * 1.0);
	}


}