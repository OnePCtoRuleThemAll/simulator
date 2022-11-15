#pragma once

#include "GeometryBase.h"
#include <cmath> 

namespace Geometry2D 
{
	/// <summary> Struct representing point. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct Point 
		: GeomteryBase
	{
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
		GeomteryBase& assign(const GeomteryBase& other) override;

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
		bool equals(const GeomteryBase& other) override;

		/// <summary> Postion X of point. </summary>
		T mPositionX;

		/// <summary> Postion Y of point. </summary>
		T mPositionY;

		/// <summary>Move point by vector. </summary>
		/// <param name = "vector"> Vector. </param>
		/// <param name = "point"> Point. </param>
		//template<typename T>
		//void movePointByVector(const Vector<T> vector);
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
	inline Point<T>::Point(const Point<T>& other)
	{
		this->assign(other);
	}

	template<typename T>
	inline Point<T>::Point(Point<T>&& other) :
		mPositionX(other.mPositionX),
		mPositionY(other.mPositionY)
	{
		other.mPositionX = 0;
		other.mPositionY = 0;
	}

	template<typename T>
	inline Point<T>::~Point()
	{
		mPositionX = 0;
		mPositionY = 0;
	}

	template<typename T>
	inline GeomteryBase& Point<T>::assign(const GeomteryBase& other)
	{
		if(this != &other)
		{
			Point<T>& otherPoint = static_cast<Point<T>&>(other);
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
			Point<T>& otherPoint = Point<T>&(other);
			mPositionX = otherPoint.mPositionX;
			mPositionY = otherPoint.mPositionY;
		}

		return *this;
	}

	template<typename T>
	inline bool Point<T>::equals(const GeomteryBase& other)
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


	/// <summary>Distance between two points. </summary>
	/// <param name = "point1"> First point. </param>
	/// <param name = "point2"> Second point. </param>
	/// <returns> Returns distance between two points. </returns>
	template<typename T>
	double distanceBetweenPoints(Point<T>& point1, Point<T>& point2) {
		return sqrt(pow(point1.mPositionX - point2.mPositionX, 2) + pow(point1.mPositionY - point2.mPositionY, 2));
	}

	/// <summary> Struct representing vector. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct Vector
		: GeomteryBase
	{
		/// <summary> Constructor. </summary>
		Vector();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "deltaX"> Delta X of vector. </param>
		/// /// <param name = "deltaY"> Delta Y  of vector. </param>
		Vector(T deltaX, T deltaY);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Vector(const Vector<T>& other);


		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Vector(Vector<T>&& other);

		/// <summary>Destructor. </summary>
		~Vector();

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		GeomteryBase& assign(const GeomteryBase& other) override;

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Vector<T>& operator=(Vector<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Vector<T>& assign(const Vector<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const GeomteryBase& other) override;

		/// <summary> Delta X of vector. </summary>
		T mDeltaX;

		/// <summary> Delta Y of vector. </summary>
		T mDeltaY;

		/// <summary>Size of vector. </summary>
		/// <param name = "Vector"> Vector. </param>
		/// <returns> Returns size of vector. </returns>
		double sizeOfVector();

		/// <summary>Vector addtion. </summary>
		/// <param name = "vector"> First vector. </param>
		/// <returns> Returns result vector. </returns>
		void vectorAddition(Vector<T>& vector);

		/// <summary>Vector multiplication. </summary>
		/// <param name = "scalary"> Value of scalary. </param>
		void vectorMultiplication(T scalary);
	};

	template<typename T>
	inline Vector<T>::Vector() :
		mDeltaX(0),
		mDeltaY(0)
	{
	}

	template<typename T>
	inline Vector<T>::Vector(T deltaX, T deltaY) :
		mDeltaX(deltaX),
		mDeltaY(deltaY)
	{
	}

	template<typename T>
	inline Vector<T>::Vector(const Vector<T>& other)
	{
		this->assign(other);
	}

	template<typename T>
	inline Vector<T>::Vector(Vector<T>&& other) :
		mDeltaX(other.mDeltaX),
		mDeltaY(other.mDeltaY)
	{
		other.mDeltaX = 0;
		other.mDeltaY = 0;
	}

	template<typename T>
	inline Vector<T>::~Vector()
	{
		mDeltaX = 0;
		mDeltaY = 0;
	}

	template<typename T>
	inline GeomteryBase& Vector<T>::assign(const GeomteryBase& other)
	{
		if (this != &other)
		{
			Vector<T>& otherVector = static_cast<Vector<T>&>(other);
			mDeltaX = otherVector.mDeltaX;
			mDeltaY = otherVector.mDeltaY;
		}

		return *this;
	}

	template<typename T>
	inline Vector<T>& Vector<T>::operator=(Vector<T>&& other)
	{
		mDeltaX = other.mDeltaX;
		mDeltaY = other.mDeltaY;
		other.mDeltaX = 0;
		other.mDeltaY = 0;
		return *this;
	}

	template<typename T>
	inline Vector<T>& Vector<T>::assign(const Vector<T>& other)
	{
		if (this != &other)
		{
			Vector<T>& otherVector = Vector<T>&(other);
			mDeltaX = otherVector.mDeltaX;
			mDeltaY = otherVector.mDeltaY;
		}

		return *this;
	}

	template<typename T>
	inline bool Vector<T>::equals(const GeomteryBase& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			Vector<T>* otherVector = dynamic_cast<Vector<T>*>(&other);
			if (otherVector != nullptr && otherVector->mDeltaX == mDeltaX && otherVector->mDeltaY == mDeltaY) {
				return true;
			}
		}
		return false;
	}

	template<typename T>
	inline double Vector<T>::sizeOfVector()
	{
		return sqrt(pow(mDeltaX, 2) + pow(mDeltaY, 2));
	}

	template<typename T>
	inline void Geometry2D::Vector<T>::vectorAddition(Vector<T>& vector)
	{
		mDeltaX += vector.mDeltaX;
		mDeltaY += vector.mDeltaY;
	}

	template<typename T>
	inline void Geometry2D::Vector<T>::vectorMultiplication(T scalary)
	{
		mDeltaX *= scalary;
		mDeltaY *= scalary;
	}

	/// <summary>Size of vector. </summary>
	/// <param name = "Vector"> Vector. </param>
	/// <returns> Returns size of vector. </returns>
	template<typename T>
	double sizeOfVector(Vector<T> vector) {
		return vector.sizeOfVector();
	}

	/// <summary>Vector addtion. </summary>
	/// <param name = "vector1"> First vector. </param>
	/// <param name = "vector2"> Second vector. </param>
	/// <returns> Returns result vector. </returns>
	template<typename T>
	Vector<T>& vectorAddition(Vector<T>& vector1, Vector<T>& vector2) {
		Vector<T>* pResultVector = new Vector<T>(vector1.mDeltaX + vector2.mDeltaX, vector1.mDeltaY + vector2.mDeltaY);
		return *pResultVector;
	}

	/// <summary>Vector multiplication. </summary>
	/// <param name = "vector"> First vector. </param>
	/// <param name = "scalary"> Value of scalary. </param>
	template<typename T>
	Vector<T>& vectorMultiplication(const Vector<T>& vector, T scalary) {
		Vector<T>* pResultVector = new Vector<T>(vector);
		pResultVector->vectorMultiplication(scalary);
		return *pResultVector;
	}

	/// <summary> Dot product. </summary>
	/// <param name = "vector1"> First vector. </param>
	/// <param name = "vector2"> Second vector. </param>
	/// <returns> Returns dot product. </returns>
	template<typename T>
	T dotProduct(Vector<T>& vector1, Vector<T>& vector2) {
		 return vector1.mDeltaX * vector2.mDeltaX + vector1.mDeltaY * vector2.mDeltaY;
	}

	/// <summary>Move point by vector. </summary>
	/// <param name = "vector"> Vector. </param>
	/// <param name = "point"> Point. </param>
	template<typename T>
	Point<T>& movePointByVector(const Vector<T>& vector, const Point<T>& point) {
		point.mPositionX += vector.mDeltaX;
		point.mPositionY += vector.mDeltaY;
		Point<T>* pResultPoint = new Point<T>(point);
		pResultPoint->mPositionX;
	}

	/// <summary> Angle between vectors. </summary>
	/// <param name = "vector1"> First vector. </param>
	/// <param name = "vector2"> Second vector. </param>
	/// <returns> Returns angle between vectors in radians. </returns>
	template<typename T>
	double angleBetweenVectors(Vector<T>& vector1, Vector<T>& vector2) {
		return acos(dotProduct(vector1, vector2) / sqrt(sizeOfVector(vector1) * sizeOfVector(vector2)));
	}

	/// <summary> Rotate vector by angle. </summary>
	/// <param name = "vector"> Vector. </param>
	/// <param name = "degrees"> Angle in radians. </param>
	template<typename T>
	void rotateVectorByAngle(Vector<T>& vector, double angle) {
		vector.mDeltaX = vector.mDeltaX * cos(angle) - vector.mDeltaY * sin(angle);
		vector.mDeltaY = vector.mDeltaX * sin(angle) + vector.mDeltaY * cos(angle);
	}
}