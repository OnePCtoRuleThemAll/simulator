#pragma once
#include "Point.h"
#include <algorithm>

namespace Geometry2D {
	
	/// <summary> Struct representing point. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	class Rectangle
	{
	public:

		/// <summary> Constructor. </summary>
		Rectangle();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "point1"> Top left corner of the world. </param>
		/// <param name = "point2"> Bottom right corner of the world. </param>
		Rectangle(const Point<T>& topPoint, const Point<T>& bottomPoint);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Rectangle(const Rectangle<T>& other);

		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Rectangle(Rectangle<T>&& other);

		/// <summary>Destructor. </summary>
		~Rectangle();

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Rectangle<T>& operator=(Rectangle<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Rectangle<T>& assign(const Rectangle<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const Rectangle<T>& other);

		/// <summary> Evaluates if two rectanles are intersecting or no. </summary>
		/// <param name = "rectangle"> Rectangle with wich we are checking intersection. </param>
		/// <returns> True if rectangles intersect false if they do not. </returns>
		bool intersectionRectangle(Rectangle<T>& rectangle);

		/// <summary> Top left point of rectangle. </summary>
		Point<T>* mTopPoint;

		/// <summary> Bottom right point of rectangle. </summary>
		Point<T>* mBottomPoint;
	};

	template<typename T>
	inline Rectangle<T>::Rectangle() :
		mTopPoint(new Point<T>()),
		mBottomPoint(new Point<T>())
	{
	}

	template<typename T>
	inline Rectangle<T>::Rectangle(const Point<T>& topPoint, const Point<T>& bottomPoint) :
		mTopPoint(new Point<T>(topPoint)),
		mBottomPoint(new Point<T>(bottomPoint))
	{
	}

	template<typename T>
	inline Rectangle<T>::Rectangle(const Rectangle<T>& other) :
		mTopPoint(new Point<T>(*(other.mTopPoint))),
		mBottomPoint(new Point<T>(*(other.mBottomPoint)))
	{
	}

	template<typename T>
	inline Rectangle<T>::Rectangle(Rectangle<T>&& other) :
		mTopPoint(other.mTopPoint),
		mBottomPoint(other.mBottomPoint)
	{
		other.mTopPoint = nullptr;
		other.mBottomPoint = nullptr;
	}

	template<typename T>
	inline Rectangle<T>::~Rectangle()
	{
		delete mTopPoint;
		delete mBottomPoint;
		mTopPoint = nullptr;
		mBottomPoint = nullptr;
	}

	template<typename T>
	inline Rectangle<T>& Rectangle<T>::operator=(Rectangle<T>&& other)
	{
		mTopPoint = other.mTopPoint;
		mBottomPoint = other.mBottomPoint;
		other.mTopPoint = nullptr;
		other.mBottomPoint = nullptr;
		return *this;
	}

	template<typename T>
	inline Rectangle<T>& Rectangle<T>::assign(const Rectangle<T>& other)
	{
		if (this != &other)
		{
			mTopPoint->assign(*other.mTopPoint);
			mBottomPoint->assign(*other.mBottomPoint);
		}
		return *this;
	}

	template<typename T>
	inline bool Rectangle<T>::equals(const Rectangle<T>& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			if (other.mTopPoint->equals(*(mTopPoint)) && other.mBottomPoint->equals(*(mBottomPoint))) {
				return true;
			}
		}
		return false;
	}
	template<typename T>
	inline bool Rectangle<T>::intersectionRectangle(Rectangle<T>& rectangle)
	{
		if (mTopPoint->mPositionX == mBottomPoint->mPositionX || mTopPoint->mPositionY == mBottomPoint->mPositionY || 
			rectangle.mTopPoint->mPositionX == rectangle.mBottomPoint->mPositionX || 
			rectangle.mTopPoint->mPositionY == rectangle.mBottomPoint->mPositionY)
			return false;

		if (mTopPoint->mPositionX > rectangle.mBottomPoint->mPositionX || 
			 rectangle.mTopPoint->mPositionX > mBottomPoint->mPositionX)
			return false;

		if (mBottomPoint->mPositionY < rectangle.mTopPoint->mPositionY || 
			rectangle.mBottomPoint->mPositionY < mTopPoint->mPositionY)
			return false;


		return true;
	}
}
