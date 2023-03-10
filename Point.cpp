#include "Point.h"

namespace  Geometry2D {

	template<typename T>
	Point<T>::Point() :
		mPositionX(0),
		mPositionY(0)
	{
	}

	template<typename T>
	Point<T>::Point(T positionX, T positionY) :
		mPositionX(positionX),
		mPositionY(positionY)
	{
	}

	template<typename T>
	Point<T>::Point(const Point<T>& other) :
		mPositionX(other.mPositionX),
		mPositionY(other.mPositionY)
	{
	}

	template<typename T>
	Point<T>::Point(Point<T>&& other) :
		mPositionX(other.mPositionX),
		mPositionY(other.mPositionY)
	{
	}

	template<typename T>
	Point<T>::~Point()
	{
		mPositionX = 0;
		mPositionY = 0;
	}

	template<typename T>
	Geometry2D::GeomteryBase& Point<T>::assign(const Geometry2D::GeomteryBase& other)
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
	Point<T>& Point<T>::operator=(Point<T>&& other)
	{
		mPositionX = other.mPositionX;
		mPositionY = other.mPositionY;
		other.mPositionX = 0;
		other.mPositionY = 0;
		return *this;
	}

	template<typename T>
	Point<T>& Point<T>::assign(const Point<T>& other)
	{
		if (this != &other)
		{
			mPositionX = other.mPositionX;
			mPositionY = other.mPositionY;
		}

		return *this;
	}

	template<typename T>
	bool Point<T>::equals(const Geometry2D::GeomteryBase& other)
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
	void Point<T>::movePointByVector(const Geometry2D::Vector<T>& vector)
	{
		mPositionX += vector.mDeltaX;
		mPositionY += vector.mDeltaY;
	}

	template<typename T>
	inline bool Point<T>::isPointIn(const Point<T>& point)
	{
		return this->equals(point);
	}


	/// <summary>Distance between two points. </summary>
	/// <param name = "point1"> First point. </param>
	/// <param name = "point2"> Second point. </param>
	/// <returns> Returns distance between two points. </returns>
	template<typename T>
	double distanceBetweenPoints(Point<T>& point1, Point<T>& point2) {
		return sqrt(pow(point1.mPositionX - point2.mPositionX, 2) + pow(point1.mPositionY - point2.mPositionY, 2));
	}

	/// <summary>Distance between two points. </summary>
	/// <param name = "point1"> First point. </param>
	/// <param name = "point2"> Second point. </param>
	/// <returns> Returns distance between two points. </returns>
	template<typename T>
	double orientationOfPoints(Point<T>& point1, Point<T>& point2, Point<T>& point3) {
		double number = (point2.mPositionY - point1.mPositionY) * (point3.mPositionX - point2.mPositionX) -
			(point2.mPositionX - point1.mPositionX) * (point3.mPositionY - point2.mPositionY);

		if (number == 0) return 0;

		return (number > 0) ? 1 : 2;
	}
}