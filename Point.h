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

		GeomteryBase& operator=(GeomteryBase& other) override;

		GeomteryBase& assign(GeomteryBase& other)override;

		bool operator==(GeomteryBase& other) override;

		bool equals(GeomteryBase& other) override;

		double distanceToPoint(Point& other);


		T mPositionX;
		T mPositionY;
	};

	template<typename T>
	inline Point<T>::Point()
	{
		this->mPositionX = 0;
		this->mPositionY = 0;
	}

	template<typename T>
	inline Point<T>::Point(T positionX, T positionY)
	{
		this->mPositionX = positionX;
		this->mPositionY = positionY;
	}

	template<typename T>
	inline Point<T>::Point(Point<T>& other)
	{
		this->mPositionX = other.mPositionX;
		this->mPositionY = other.mPositionY;
	}
}