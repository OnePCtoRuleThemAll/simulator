#pragma once

#include "GeometryBase.h"
#include <cmath> 

namespace Geometry2D 
{
	template <typename T> struct Vector;

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
		void movePointByVector(const Vector<T>& vector);
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
	inline GeomteryBase& Point<T>::assign(const GeomteryBase& other)
	{
		if(this != &other)
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
	inline bool Point<T>::equals(const GeomteryBase& other)
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
	inline void Geometry2D::Point<T>::movePointByVector(const Vector<T>& vector)
	{
		mPositionX += vector.mDeltaX;
		mPositionY += vector.mDeltaY;
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

		/// <summary> Angle between vectors. </summary>
		/// <param name = "vector1"> First vector. </param>
		/// <returns> Returns angle between vectors in radians. </returns>
		double angleBetweenVectors(Vector<T>& vector);

		/// <summary> Rotate vector by angle. </summary>
		/// <param name = "vector"> Vector. </param>
		/// <param name = "angle"> Angle in radians. </param>
		void rotateVectorByAngle(double angle);
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
	inline Vector<T>::Vector(const Vector<T>& other) :
		mDeltaX(other.mDeltaX),
		mDeltaY(other.mDeltaY)
	{
	}

	template<typename T>
	inline Vector<T>::Vector(Vector<T>&& other) :
		mDeltaX(other.mDeltaX),
		mDeltaY(other.mDeltaY)
	{
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
			const Vector<T>& otherVector = static_cast<const Vector<T>&>(other);
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
			mDeltaX = other.mDeltaX;
			mDeltaY = other.mDeltaY;
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
			const Vector<T>* otherVector = dynamic_cast<const Vector<T>*>(&other);
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
	double sizeOfVector(Vector<T> vector) 
	{
		return vector.sizeOfVector();
	}

	/// <summary>Vector addtion. </summary>
	/// <param name = "vector1"> First vector. </param>
	/// <param name = "vector2"> Second vector. </param>
	/// <returns> Returns result vector. </returns>
	template<typename T>
	Vector<T>* vectorAddition(Vector<T>& vector1, Vector<T>& vector2) 
	{
		Vector<T>* pResultVector = new Vector<T>(vector1.mDeltaX + vector2.mDeltaX, vector1.mDeltaY + vector2.mDeltaY);
		return pResultVector;
	}

	/// <summary>Vector multiplication. </summary>
	/// <param name = "vector"> First vector. </param>
	/// <param name = "scalary"> Value of scalary. </param>
	template<typename T>
	Vector<T>* vectorMultiplication(const Vector<T>& vector, T scalary) 
	{
		Vector<T>* pResultVector = new Vector<T>(vector);
		pResultVector->vectorMultiplication(scalary);
		return pResultVector;
	}

	/// <summary> Dot product. </summary>
	/// <param name = "vector1"> First vector. </param>
	/// <param name = "vector2"> Second vector. </param>
	/// <returns> Returns dot product. </returns>
	template<typename T>
	T dotProduct(Vector<T>& vector1, Vector<T>& vector2) 
	{
		 return vector1.mDeltaX * vector2.mDeltaX + vector1.mDeltaY * vector2.mDeltaY;
	}


	/// <summary>Move point by vector. </summary>
	/// <param name = "vector"> Vector. </param>
	/// <param name = "point"> Point. </param>
	template<typename T>
	Point<T>* movePointByVector(const Vector<T>& vector, const Point<T>& point) 
	{
		Point<T>* pResultPoint = new Point<T>(point);
		pResultPoint->movePointByVector(vector);
		return pResultPoint;
	}

	template<typename T>
	inline double Geometry2D::Vector<T>::angleBetweenVectors(Vector<T>& vector)
	{
		return acos(dotProduct(*this, vector) / sqrt(this->sizeOfVector() * sizeOfVector(vector)));
	}

	/// <summary> Angle between vectors. </summary>
	/// <param name = "vector1"> First vector. </param>
	/// <param name = "vector2"> Second vector. </param>
	/// <returns> Returns angle between vectors in radians. </returns>
	template<typename T>
	double angleBetweenVectors(Vector<T>& vector1, Vector<T>& vector2) 
	{
		return acos(dotProduct(vector1, vector2) / sqrt(sizeOfVector(vector1) * sizeOfVector(vector2)));
	}

	template<typename T>
	inline void Geometry2D::Vector<T>::rotateVectorByAngle(double angle)
	{
		mDeltaX = mDeltaX * cos(angle) - mDeltaY * sin(angle);
		mDeltaY = mDeltaX * sin(angle) + mDeltaY * cos(angle);
	}

	/// <summary> Rotate vector by angle. </summary>
	/// <param name = "vector"> Vector. </param>
	/// <param name = "degrees"> Angle in radians. </param>
	template<typename T>
	Vector<T>* rotateVectorByAngle(Vector<T>& vector, double angle) 
	{
		Vector<T>* pResultVector = new Vector<T>(vector);
		pResultVector->rotateVectorByAngle(angle);
		return pResultVector;
	}

	/// <summary> Struct representing vector. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct Line
		: GeomteryBase
	{
		/// <summary> Constructor. </summary>
		Line();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "point1"> First point defining line. </param>
		/// /// <param name = "point2"> Second point defining line. </param>
		Line(const Point<T>& point1, const Point<T>& point2);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Line(const Line<T>& other);


		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Line(Line<T>&& other);

		/// <summary>Destructor. </summary>
		~Line();

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		GeomteryBase& assign(const GeomteryBase& other) override;

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Line<T>& operator=(Line<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Line<T>& assign(const Line<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const GeomteryBase& other) override;

		/// <summary> First vector defining line. </summary>
		Point<T>* mPoint1;

		/// <summary> Second vector defining line. </summary>
		Point<T>* mPoint2;

		/// <summary> Gradient of line. </summary>
		/// <returns> Gradient of line. </returns>
		double gradient();

		/// <summary> Y-intercept. </summary>
		/// <returns> Y-intercept of line. </returns>
		double interceptWithAxisY();

		/// <summary> Is point on line. </summary>
		/// <param name="point"> Point. </param>
		/// <returns>True if point lies on line. </returns>
		bool isPointOnLine(const Point<T>& point);

		/// <summary> Moves line by vector. </summary>
		/// <param name="vector"> Vector. </param>
		void moveLineByVector(const Vector<T>& vector);

		/// <summary> Directional vector of line. </summary>
		/// <returns> Directional vector of line. </returns>
		Vector<T>* directionalVector();

		/// <summary> Normalized vector of line. </summary>
		/// <returns> Normalized vector of line. </returns>
		Vector<T>* normalizedVector();

		/// <summary> Coefficient of line. </summary>
		/// <returns> Coefficient of line. </returns>
		double coefficientOfLine();

		/// <summary> Coefficient of line. </summary>
		/// <returns> Coefficient of line. </returns>
		double distancetoPoint(const Point<T>& point);
	};
	
	template<typename T>
	inline Line<T>::Line() :
		mPoint1(Point<T>()),
		mPoint2(Point<T>())
	{
	}

	template<typename T>
	inline Line<T>::Line(const Point<T>& point1, const Point<T>& point2) :
		mPoint1(new Point<T>(point1)),
		mPoint2(new Point<T>(point2))
	{
	}

	template<typename T>
	inline Line<T>::Line(const Line<T>& other) :
		mPoint1(new Point<T>(*(other.mPoint1))),
		mPoint2(new Point<T>(*(other.mPoint2)))
	{
	}

	template<typename T>
	inline Line<T>::Line(Line<T>&& other) :
		mPoint1(other.mPoint1),
		mPoint2(other.mPoint2)
	{
		other.mPoint1 = nullptr;
		other.mPoint2 = nullptr;
	}

	template<typename T>
	inline Line<T>::~Line()
	{
		delete mPoint1;
		delete mPoint2;
		mPoint1 = nullptr;
		mPoint2 = nullptr;
	}

	template<typename T>
	inline GeomteryBase& Line<T>::assign(const GeomteryBase& other)
	{
		if (this != &other)
		{
			const Line<T>& otherLine = static_cast<const Line<T>&>(other);
			mPoint1->assign(*(otherLine.mPoint1));
			mPoint2->assign(*(otherLine.mPoint2));
		}

		return *this;
	}

	template<typename T>
	inline Line<T>& Line<T>::operator=(Line<T>&& other)
	{
		mPoint1 = other.mPoint1;
		mPoint2 - other.mPoint2;
		other.mPoint1 = nullptr;
		other.mPoint2 = nullptr;
		return *this;
	}

	template<typename T>
	inline Line<T>& Line<T>::assign(const Line<T>& other)
	{
		if (this != &other)
		{
			mPoint1->assign(other.mPoint1);
			mPoint2->assign(other.mPoint2);
		}
		return *this;
	}

	template<typename T>
	inline bool Line<T>::equals(const GeomteryBase& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			const Line<T>* otherLine = dynamic_cast<const Line<T>*>(&other);
			if (otherLine != nullptr && otherLine->mPoint1->equals(*(mPoint1)) && otherLine->mPoint2->equals(*(mPoint2))) {
				return true;
			}
		}
		return false;
	}

	template<typename T>
	inline double Line<T>::gradient()
	{
		return (mPoint2->mPositionY - mPoint1->mPositionY) / (mPoint2->mPositionX - mPoint1->mPositionX);
	}

	template<typename T>
	inline double Line<T>::interceptWithAxisY()
	{
		return mPoint1->mPositionY - (this->gradient() * mPoint1->mPositionX);
	}

	template<typename T>
	inline bool Line<T>::isPointOnLine(const Point<T>& point)
	{
		return this->distancetoPoint(point) == 0;
	}

	template<typename T>
	inline void Line<T>::moveLineByVector(const Vector<T>& vector)
	{
		mPoint1->movePointByVector(vector);
		mPoint2->movePointByVector(vector);
	}

	template<typename T>
	inline Vector<T>* Line<T>::directionalVector()
	{
		Vector<T>* pResultVector = new Vector<T>(mPoint2->mPositionX - mPoint1->mPositionX, mPoint2->mPositionY - mPoint1->mPositionY);
		return pResultVector;
	}

	template<typename T>
	inline Vector<T>* Line<T>::normalizedVector()
	{
		Vector<T>* resultVector = new Vector<T>(*this->directionalVector());
		T newDeltaX = resultVector->mDeltaY * -1;
		resultVector->mDeltaY = resultVector->mDeltaX;
		resultVector->mDeltaX = newDeltaX;
		return resultVector;
	}

	template<typename T>
	inline double Line<T>::coefficientOfLine()
	{
		Vector<T>* normalizedVector = this->normalizedVector();
		double result = (normalizedVector->mDeltaX * mPoint1->mPositionX + normalizedVector->mDeltaY * mPoint1->mPositionY) * -1;
		delete normalizedVector;
		return result;
	}

	template<typename T>
	inline double Line<T>::distancetoPoint(const Point<T>& point)
	{
		Vector<T>* normalizedVector = this->normalizedVector();
		double result = abs(normalizedVector->mDeltaX * point.mPositionX + normalizedVector->mDeltaY * point.mPositionY + this->coefficientOfLine()) /
			sqrt(pow(normalizedVector->mDeltaX, 2) + pow(normalizedVector->mDeltaY, 2));
		delete normalizedVector;
		return result;
	}

	/// <summary> Gradient of line. </summary>
	/// <returns> Gradient of line. </returns>
	template<typename T>
	double gradient(Line<T>& line) 
	{
		return (line.mPoint2->mPositionY - line.mPoint1->mPositionY) / (line.mPoint2->mPositionX - line.mPoint1->mPositionX);
	}

	/// <summary> Y-intercept. </summary>
	/// <returns> Y-intercept of line. </returns>
	template<typename T>
	double lineInterceptWithAxisY(Line<T>& line) 
	{
		return line.mPoint1->mPositionY - (line.gradient() * line.mPoint1->mPositionX);
	}

	/// <summary> Is point on line. </summary>
	/// <param name="point"> Point. </param>
	/// <returns>True if point lies on line. </returns>
	template<typename T>
	bool isPointOnLine(Line<T>& line, Point<T>& point) 
	{
		return line.distancetoPoint(point) == 0;
	}

	/// <summary> Moves line by vector. </summary>
	/// <param name="vector"> Vector. </param>
	template<typename T>
	Line<T>& moveLineByVector(Line<T>& line, Vector<T>& vector) 
	{
		line.mPoint1->movePointByVector(vector);
		line.mPoint2->movePointByVector(vector);
	}

	/// <summary> Directional vector of line. </summary>
	/// <returns> Directional vector of line. </returns>
	template<typename T>
	Vector<T>* directionalVectorOfLine(Line<T>& line)
	{
		Vector<T>* pResultVector = new Vector<T>(line.mPoint2->mPositionX - line.mPoint1->mPositionX, line.mPoint2->mPositionY - line.mPoint1->mPositionY);
		return pResultVector;
	}

	/// <summary> Normalized vector of line. </summary>
	/// <returns> Normalized vector of line. </returns>
	template<typename T>
	Vector<T>* normalizedVectorOfLine(Line<T>& line)
	{
		Vector<T>* resultVector = new Vector<T>(*line.directionalVector());
		T newDeltaX = resultVector.mDeltaY * -1;
		resultVector.mDeltaY = resultVector.mDeltaX;
		resultVector.mDeltaX = newDeltaX;
		return resultVector;
	}

	/// <summary> Coefficient of line. </summary>
	/// <returns> Coefficient of line. </returns>
	template<typename T>
	double coefficientOfLine(Line<T>& line)
	{
		return line.coefficientOfLine();
	}

	/// <summary> Coefficient of line. </summary>
	/// <returns> Coefficient of line. </returns>
	template<typename T>
	double distancePointToLine(Line<T>& line, Point<T>& point)
	{
		return line.distancetoPoint(point);
	}

	/// <summary> Struct representing vector. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct LineSegment
		: GeomteryBase
	{
		/// <summary> Constructor. </summary>
		LineSegment();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "point1"> First point defining line. </param>
		/// /// <param name = "point2"> Second point defining line. </param>
		LineSegment(const Point<T>& point1, const Point<T>& point2);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		LineSegment(const LineSegment<T>& other);


		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		LineSegment(LineSegment<T>&& other);

		/// <summary>Destructor. </summary>
		~LineSegment();

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		GeomteryBase& assign(const GeomteryBase& other) override;

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		LineSegment<T>& operator=(LineSegment<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		LineSegment<T>& assign(const LineSegment<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const GeomteryBase& other) override;

		/// <summary> First vector defining line. </summary>
		Point<T>* mPoint1;

		/// <summary> Second vector defining line. </summary>
		Point<T>* mPoint2;

		/// <summary> Is point on line. </summary>
		/// <param name="point"> Point. </param>
		/// <returns>True if point lies on line. </returns>
		bool isPointOnLineSegment(const Point<T>& point);

		/// <summary> Moves line by vector. </summary>
		/// <param name="vector"> Vector. </param>
		void moveLineSegmentByVector(const Vector<T>& vector);

		/// <summary> Directional vector of line. </summary>
		/// <returns> Directional vector of line. </returns>
		Vector<T>* directionalVector();

		/// <summary> Normalized vector of line. </summary>
		/// <returns> Normalized vector of line. </returns>
		Vector<T>* normalizedVector();

		/// <summary> Coefficient of line. </summary>
		/// <returns> Coefficient of line. </returns>
		double coefficientOfLineSegment();

		/// <summary> Coefficient of line. </summary>
		/// <returns> Coefficient of line. </returns>
		double distancetoPoint(const Point<T>& point);
	};

	template<typename T>
	inline LineSegment<T>::LineSegment() :
		mPoint1(Point<T>()),
		mPoint2(Point<T>())
	{
	}

	template<typename T>
	inline LineSegment<T>::LineSegment(const Point<T>& point1, const Point<T>& point2) :
		mPoint1(new Point<T>(point1)),
		mPoint2(new Point<T>(point2))
	{
	}

	template<typename T>
	inline LineSegment<T>::LineSegment(const LineSegment<T>& other) :
		mPoint1(new Point<T>(*(other.mPoint1))),
		mPoint2(new Point<T>(*(other.mPoint2)))
	{
	}

	template<typename T>
	inline LineSegment<T>::LineSegment(LineSegment<T>&& other) :
		mPoint1(other.mPoint1),
		mPoint2(other.mPoint2)
	{
		other.mPoint1 = nullptr;
		other.mPoint2 = nullptr;
	}

	template<typename T>
	inline LineSegment<T>::~LineSegment()
	{
		delete mPoint1;
		delete mPoint2;
		mPoint1 = nullptr;
		mPoint2 = nullptr;
	}

	template<typename T>
	inline GeomteryBase& LineSegment<T>::assign(const GeomteryBase& other)
	{
		if (this != &other)
		{
			const Line<T>& otherLine = static_cast<const Line<T>&>(other);
			mPoint1->assign(*(otherLine.mPoint1));
			mPoint2->assign(*(otherLine.mPoint2));
		}

		return *this;
	}

	template<typename T>
	inline LineSegment<T>& LineSegment<T>::operator=(LineSegment<T>&& other)
	{
		mPoint1 = other.mPoint1;
		mPoint2 - other.mPoint2;
		other.mPoint1 = nullptr;
		other.mPoint2 = nullptr;
		return *this;
	}

	template<typename T>
	inline LineSegment<T>& LineSegment<T>::assign(const LineSegment<T>& other)
	{
		if (this != &other)
		{
			mPoint1->assign(other.mPoint1);
			mPoint2->assign(other.mPoint2);
		}
		return *this;
	}

	template<typename T>
	inline bool LineSegment<T>::equals(const GeomteryBase& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			const LineSegment<T>* otherLine = dynamic_cast<const LineSegment<T>*>(&other);
			if (otherLine != nullptr && otherLine->mPoint1->equals(*(mPoint1)) && otherLine->mPoint2->equals(*(mPoint2))) {
				return true;
			}
		}
		return false;
	}

	template<typename T>
	inline bool LineSegment<T>::isPointOnLineSegment(const Point<T>& point)
	{
		return this->distancetoPoint(point) == 0;
	}

	template<typename T>
	inline void LineSegment<T>::moveLineSegmentByVector(const Vector<T>& vector)
	{
		mPoint1->movePointByVector(vector);
		mPoint2->movePointByVector(vector);
	}

	template<typename T>
	inline Vector<T>* LineSegment<T>::directionalVector()
	{
		Vector<T>* pResultVector = new Vector<T>(mPoint2->mPositionX - mPoint1->mPositionX, mPoint2->mPositionY - mPoint1->mPositionY);
		return pResultVector;
	}

	template<typename T>
	inline Vector<T>* LineSegment<T>::normalizedVector()
	{
		Vector<T>* resultVector = new Vector<T>(*this->directionalVector());
		T newDeltaX = resultVector->mDeltaY * -1;
		resultVector->mDeltaY = resultVector->mDeltaX;
		resultVector->mDeltaX = newDeltaX;
		return resultVector;
	}

	template<typename T>
	inline double LineSegment<T>::coefficientOfLineSegment()
	{
		Vector<T>* normalizedVector = this->normalizedVector();
		double result = (normalizedVector->mDeltaX * mPoint1->mPositionX + normalizedVector->mDeltaY * mPoint1->mPositionY) * -1;
		delete normalizedVector;
		return result;
	}

	template<typename T>
	inline double LineSegment<T>::distancetoPoint(const Point<T>& point)
	{
		Vector<T>* pLineSegment = new Vector<T>(*mPoint1, *mPoint2);
		Vector<T>* pFirstPointAndPoint = new Vector<T>(*mPoint1, point);
		Vector<T>* pSecondPointAndPoint = new Vector<T>(*mPoint2, point);

		double dotProductLineSeg1 = dotProduct(*pLineSegment, *pFirstPointAndPoint);
		double dotProductLineSeg2 = dotProduct(*pLineSegment, *pSecondPointAndPoint);

		double result = 0;

		if (dotProductLineSeg1 > 0) {
			result = pFirstPointAndPoint->sizeOfVector();
		}
		else if (dotProductLineSeg2 < 0) {
			result = pSecondPointAndPoint->sizeOfVector();
		}
		else {
			result = abs((pLineSegment->mDeltaX * pFirstPointAndPoint->mDeltaY) - (pLineSegment->mDeltaY * pFirstPointAndPoint->mDeltaX)) / sqrt(pow(pLineSegment->mDeltaX, 2) + pow(pLineSegment->mDeltaY, 2));
		}
		delete pLineSegment;
		delete pFirstPointAndPoint;
		delete pSecondPointAndPoint;
		return result;
	}

	/// <summary> Gradient of line. </summary>
	/// <returns> Gradient of line. </returns>
	template<typename T>
	double gradient(LineSegment<T>& line)
	{
		return (line.mPoint2->mPositionY - line.mPoint1->mPositionY) / (line.mPoint2->mPositionX - line.mPoint1->mPositionX);
	}

	/// <summary> Y-intercept. </summary>
	/// <returns> Y-intercept of line. </returns>
	template<typename T>
	double lineSegmentInterceptWithAxisY(LineSegment<T>& line)
	{
		return line.mPoint1->mPositionY - (line.gradient() * line.mPoint1->mPositionX);
	}

	/// <summary> Is point on line. </summary>
	/// <param name="point"> Point. </param>
	/// <returns>True if point lies on line. </returns>
	template<typename T>
	bool isPointOnLineSegment(LineSegment<T>& line, Point<T>& point)
	{
		return line.distancetoPoint(point) == 0;
	}

	/// <summary> Moves line by vector. </summary>
	/// <param name="vector"> Vector. </param>
	template<typename T>
	LineSegment<T>& moveLineSegmentByVector(LineSegment<T>& line, Vector<T>& vector)
	{
		line.mPoint1->movePointByVector(vector);
		line.mPoint2->movePointByVector(vector);
	}

	/// <summary> Directional vector of line. </summary>
	/// <returns> Directional vector of line. </returns>
	template<typename T>
	Vector<T>* directionalVectorOfLineSegment(LineSegment<T>& line)
	{
		Vector<T>* pResultVector = new Vector<T>(line.mPoint2->mPositionX - line.mPoint1->mPositionX, line.mPoint2->mPositionY - line.mPoint1->mPositionY);
		return pResultVector;
	}

	/// <summary> Normalized vector of line. </summary>
	/// <returns> Normalized vector of line. </returns>
	template<typename T>
	Vector<T>* normalizedVectorOfLineSegment(LineSegment<T>& line)
	{
		Vector<T>* resultVector = new Vector<T>(*line.directionalVector());
		T newDeltaX = resultVector.mDeltaY * -1;
		resultVector.mDeltaY = resultVector.mDeltaX;
		resultVector.mDeltaX = newDeltaX;
		return resultVector;
	}

	/// <summary> Coefficient of line. </summary>
	/// <returns> Coefficient of line. </returns>
	template<typename T>
	double coefficientOfLineSegment(LineSegment<T>& line)
	{
		return line.coefficientOfLineSegment();
	}

	/// <summary> Coefficient of line. </summary>
	/// <returns> Coefficient of line. </returns>
	template<typename T>
	double distancePointToLineSegment(LineSegment<T>& line, Point<T>& point)
	{
		return line.distancetoPoint(point);
	}
}