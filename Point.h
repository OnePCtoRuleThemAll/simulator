#pragma once
#include "Geometry2D/Geometry2D.h"

namespace Geometry2D
{
	/// <summary> Struct representing point. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	class Point
	{
	public:
		/// <summary> Constructor. </summary>
		Point();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "positionX"> Position X of point. </param>
		/// /// <param name = "positionY"> Position Y of point. </param>
		Point(T positionX, T positionY);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Point(const Point<T>& other);


		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Point(Point<T>&& other);

		/// <summary>Destructor. </summary>
		~Point();

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Point<T>& assign(const Point<T>& other);

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Point<T>& operator=(Point<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Point<T>& assign(const Point<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const Point<T>& other);

		/// <summary> Postion X of point. </summary>
		T mPositionX;

		/// <summary> Postion Y of point. </summary>
		T mPositionY;

		/// <summary>Move point by vector. </summary>
		/// <param name = "vector"> Vector. </param>
		void movePointByVector(const Vector<T>& vector);

		/// <summary> Is point on line. </summary>
		/// <param name="point"> Point. </param>
		/// <returns>True if point lies on line. </returns>
		bool isPointIn(const Point<T>& point) override;
	};

	template<typename T>
	inline Point<T>::Point() :
		mPositionX(0),
		mPositionY(0)
	{
	}

	template<typename T>
	inline Point<T>::Point(T positionX, T positionY) :
		mPositionX(positionX),
		mPositionY(positionY)
	{
	}

	template<typename T>
	inline Point<T>::Point(const Point<T>& other) :
		mPositionX(other.mPositionX),
		mPositionY(other.mPositionY)
	{
	}

	template<typename T>
	inline Point<T>::Point(Point<T>&& other) :
		mPositionX(other.mPositionX),
		mPositionY(other.mPositionY)
	{
	}

	template<typename T>
	inline Point<T>::~Point()
	{
		mPositionX = 0;
		mPositionY = 0;
	}

	template<typename T>
	inline Point<T>& Point<T>::assign(const Point<T>& other)
	{
		if (this != &other)
		{
			const Point<T>& otherPoint = static_cast<const Point<T>&>(other);
			mPositionX = otherPoint.mPositionX;
			mPositionY = otherPoint.mPositionY;
		}

		return *this;
	}

	template<typename T>
	inline Point<T>& Point<T>::operator=(Point<T>&& other)
	{
		mPositionX = other.mPositionX;
		mPositionY = other.mPositionY;
		other.mPositionX = 0;
		other.mPositionY = 0;
		return *this;
	}

	template<typename T>
	inline Point<T>& Point<T>::assign(const Point<T>& other)
	{
		if (this != &other)
		{
			mPositionX = other.mPositionX;
			mPositionY = other.mPositionY;
		}

		return *this;
	}

	template<typename T>
	inline bool Point<T>::equals(const Point<T>& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			const Point<T>* otherPoint = dynamic_cast<const Point<T>*>(&other);
			if (otherPoint != nullptr && otherPoint->mPositionX == mPositionX && otherPoint->mPositionY == mPositionY) {
				return true;
			}
		}
		return false;
	}

	

	template<typename T>
	inline void Point<T>::movePointByVector(const Vector<T>& vector)
	{
		mPositionX += vector.mDeltaX;
		mPositionY += vector.mDeltaY;
	}

	template<typename T>
	inline bool Point<T>::isPointIn(const Point<T>& point)
	{
		return this->equals(point);
	}
}