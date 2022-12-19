#pragma once

#include "../Geometry2D/GeometryBase.h"
#include <cmath> 
#include <float.h>

namespace Geometry2D 
{
	template <typename T> struct Vector;
	template <typename T> class PolySegment;

#pragma region Point

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

	/// <summary>Distance between two points. </summary>
	/// <param name = "point1"> First point. </param>
	/// <param name = "point2"> Second point. </param>
	/// <returns> Returns distance between two points. </returns>
	template<typename T>
	double orientationOfPoints(Point<T>& point1, Point<T>& point2, Point<T>& point3) {
		double number = (point2.mPositionY - point1.mPositionY) * (point3.mPositionX - point2.mPositionX) -
			(point2.mPositionX - point1.mPositionX) * (point3.mPositionY - point2.mPositionY;

		if (number == 0) return 0;

		return (number > 0) ? 1 : 2;
	}
#pragma endregion

#pragma region Vector
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

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "deltaX"> Delta X of vector. </param>
		/// /// <param name = "deltaY"> Delta Y  of vector. </param>
		Vector(const Point<T>& point1, const Point<T>& point2);

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
	inline Vector<T>::Vector(const Point<T>& point1, const Point<T>& point2) :
		mDeltaX(point2.mPositionX - point2.mPositionX),
		mDeltaY(point2.mPositionY - point1.mPositionY)
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
		T deltaX = mDeltaX;
		mDeltaX = deltaX * cos(angle) - mDeltaY * sin(angle);
		mDeltaY = deltaX * sin(angle) + mDeltaY * cos(angle);
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
#pragma endregion

#pragma region Line
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
			mPoint1->assign(*other.mPoint1);
			mPoint2->assign(*other.mPoint2);
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
#pragma endregion

#pragma region LineSegment
	/// <summary> Struct representing vector. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct LineSegment
		: GeomteryBase, PolySegment<T>
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
		~LineSegment() override;

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
		bool isPointOn(const Point<T>& point) override;

		/// <summary> Moves line by vector. </summary>
		/// <param name="vector"> Vector. </param>
		void moveByVector(const Vector<T>& vector) override;

		/// <summary> Directional vector of line. </summary>
		/// <returns> Directional vector of line. </returns>
		Vector<T>* directionalVector();

		/// <summary> Normalized vector of line. </summary>
		/// <returns> Normalized vector of line. </returns>
		Vector<T>* normalizedVector();

		/// <summary> Coefficient of line. </summary>
		/// <returns> Coefficient of line. </returns>
		double coefficient();

		/// <summary> Coefficient of line. </summary>
		/// <returns> Coefficient of line. </returns>
		double distancetoPoint(const Point<T>& point) override;

		bool intersectionWithLineSegment(const LineSegment<T>& line);
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
		mPoint2 = other.mPoint2;
		other.mPoint1 = nullptr;
		other.mPoint2 = nullptr;
		return *this;
	}

	template<typename T>
	inline LineSegment<T>& LineSegment<T>::assign(const LineSegment<T>& other)
	{
		if (this != &other)
		{
			mPoint1->assign(*other.mPoint1);
			mPoint2->assign(*other.mPoint2);
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
	inline bool LineSegment<T>::isPointOn(const Point<T>& point)
	{
		return this->distancetoPoint(point) == 0;
	}

	template<typename T>
	inline void LineSegment<T>::moveByVector(const Vector<T>& vector)
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
	inline double LineSegment<T>::coefficient()
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

	template<typename T>
	inline bool LineSegment<T>::intersectionWithLineSegment(const LineSegment<T>& line)
	{
		int orientation1 = orientationOfPoints(*mPoint1, *mPoint2, *line.mPoint1);
		int orientation2 = orientationOfPoints(*mPoint1, *mPoint2, *line.mPoint2);
		int orientation3 = orientationOfPoints(*line.mPoint1, *line.mPoint2, *mPoint1);
		int orientation4 = orientationOfPoints(*line.mPoint1, *line.mPoint2, *mPoint2);

		if (orientation1 != orientation2 && orientation3 != orientation4)
			return true;

		if (orientation1 == 0 && isPointOn(*line.mPoint1)) return true;

		if (orientation2 == 0 && isPointOn(*line.mPoint2)) return true;

		if (orientation3 == 0 && isPointOnLineSegment(line, *mPoint1)) return true;

		if (orientation4 == 0 && isPointOnLineSegment(line, *mPoint2)) return true;

		return false;
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
		return line.coefficient();
	}

	/// <summary> Distance betweeen point and line segment. </summary>
	/// <param name="line"> Line segment. </param>
	/// <param name="point"> Point. </param> 
	/// <returns> Distance betweeen point and line segment. </returns>
	template<typename T>
	double distancePointToLineSegment(LineSegment<T>& line, Point<T>& point)
	{
		return line.distancetoPoint(point);
	}
#pragma endregion

#pragma region CircleLine
	/// <summary> Struct representing CircleLine. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct CircleLine
		: GeomteryBase
	{
		/// <summary> Constructor. </summary>
		CircleLine();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "point1"> First point defining line. </param>
		/// /// <param name = "point2"> Second point defining line. </param>
		CircleLine(const Point<T>& point, const double radius);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		CircleLine(const CircleLine<T>& other);


		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		CircleLine(CircleLine<T>&& other);

		/// <summary>Destructor. </summary>
		~CircleLine();

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		GeomteryBase& assign(const GeomteryBase& other) override;

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		CircleLine<T>& operator=(CircleLine<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		CircleLine<T>& assign(const CircleLine<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const GeomteryBase& other) override;

		/// <summary> Center point. </summary>
		Point<T>* mCenter;

		/// <summary> Radius of circle line. </summary>
		double mRadius;

		/// <summary> Is point on line. </summary>
		/// <param name="point"> Point. </param>
		/// <returns>True if point lies on line. </returns>
		bool isPointOn(const Point<T>& point);

		/// <summary> Moves circle line by vector. </summary>
		/// <param name="vector"> Vector. </param>
		void moveByVector(const Vector<T>& vector);

		/// <summary> Distance to point. </summary>
		/// <returns> Distance to point. </returns>
		double distanceToPoint(const Point<T>& point);

		/// <summary> Intersection with line. </summary>
		/// <param name="line"> Line. </param>
		/// <returns>True if circle line intersects with line. </returns>
		bool intersectionWithLine(const Line<T>& line);

		/// <summary> Intersection with line. </summary>
		/// <param name="line"> Line. </param>
		/// <returns>True if circle line intersects with line. </returns>
		bool pointsOfIntersectionWithLine(const Line<T>& line, Point<T>* point1, Point<T>* point2);

		/// <summary> Intersection with line segment. </summary>
		/// <param name="line"> Line segment. </param>
		/// <returns>True if circle line intersects with line segment. </returns>
		bool intersectionWithLineSegment(const LineSegment<T>& line);
	};

	template<typename T>
	inline CircleLine<T>::CircleLine() :
	
		mCenter(Point<T>()),
		mRadius(0)
	{
	}

	template<typename T>
	inline CircleLine<T>::CircleLine(const Point<T>& point, const double radius) :
		mCenter(new Point<T>(point)),
		mRadius(radius)
	{
	}

	template<typename T>
	inline CircleLine<T>::CircleLine(const CircleLine<T>& other) :
		mCenter(new Point<T>(*(other.mCenter))),
		mRadius(other.mRadius)
	{
	}

	template<typename T>
	inline CircleLine<T>::CircleLine(CircleLine<T>&& other) :
		mCenter(*(other.mCenter)),
		mRadius(other.mRadius)
	{
		other.mCenter = nullptr;
	}

	template<typename T>
	inline CircleLine<T>::~CircleLine()
	{
		delete mCenter;
		mCenter = nullptr;
		mRadius = 0;
	}

	template<typename T>
	inline GeomteryBase& CircleLine<T>::assign(const GeomteryBase& other)
	{
		if (this != &other)
		{
			const CircleLine<T>& otherLine = static_cast<const CircleLine<T>&>(other);
			mCenter->assign(*(otherLine.mCenter));
			mRadius = otherLine.mRadius;
		}

		return *this;
	}

	template<typename T>
	inline CircleLine<T>& CircleLine<T>::operator=(CircleLine<T>&& other)
	{
		mCenter = other.mCenter;
		mRadius = other.mRadius;
		other.mCenter = nullptr;
		other.mRadius = 0;
		return *this;
	}

	template<typename T>
	inline CircleLine<T>& CircleLine<T>::assign(const CircleLine<T>& other)
	{
		if (this != &other)
		{
			mCenter->assign(*other.mCenter);
			mRadius = other.mRadius;
		}
		return *this;
	}

	template<typename T>
	inline bool CircleLine<T>::equals(const GeomteryBase& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			const CircleLine<T>* otherLine = dynamic_cast<const CircleLine<T>*>(&other);
			if (otherLine != nullptr && otherLine->mCenter->equals(*(mCenter)) && otherLine->mRadius == mRadius) {
				return true;
			}
		}
		return false;
	}
	template<typename T>
	inline bool CircleLine<T>::isPointOn(const Point<T>& point)
	{
		return distanceBetweenPoints(*mCenter, point) == mRadius;
	}

	template<typename T>
	inline void CircleLine<T>::moveByVector(const Vector<T>& vector)
	{
		mCenter->movePointByVector(vector);
	}

	template<typename T>
	inline double CircleLine<T>::distanceToPoint(const Point<T>& point)
	{
		return abs(distanceBetweenPoints(point, *mCenter) - mRadius);
	}

	template<typename T>
	inline bool CircleLine<T>::intersectionWithLine(const Line<T>& line)
	{
		return mRadius >= line.distancetoPoint(*mCenter);
	}

	template<typename T>
	inline bool CircleLine<T>::pointsOfIntersectionWithLine(const Line<T>& line, Point<T>* point1, Point<T>* point2)
	{
		double distToCenter = distancePointToLine(line, *(mCenter));
		Vector<T>* pVector = normalizedVectorOfLine(line);
		pVector->vectorMultiplication(distToCenter/pVector->sizeOfVector());
		double coefficient = coefficientOfLine(line);
		double x0 = -1 * ((pVector->mDeltaX * coefficient) / (pow(pVector->mDeltaX, 2) + pow(pVector->mDeltaY, 2)));
		double y0 = -1 * ((pVector->mDeltaY * coefficient) / (pow(pVector->mDeltaX, 2) + pow(pVector->mDeltaY, 2)));
		Point<T>* pPoint0 = new Point<T>(x0, y0);
		distToCenter = distanceBetweenPoints(*(pPoint0), *(mCenter));
		if (distToCenter > mRadius) {
			point1 = nullptr;
			point2 = nullptr;
			return false;
		}
		else if (distToCenter == mRadius) {
			point1->assign(*(pPoint0));
			point2 = nullptr;
			return true;
		}
		else {
			distToCenter = sqrt(pow(mRadius, 2) - (pow(coefficient, 2) / (pow(pVector->mDeltaX, 2) + pow(pVector->mDeltaY, 2))));
			double scalary = sqrt(distToCenter / (pow(pVector->mDeltaX, 2) + pow(pVector->mDeltaY, 2)));
			point1->mPositionX = pPoint0->mPositionX + pVector->mDeltaY * scalary;
			point2->mPositionX = pPoint0->mPositionX - pVector->mDeltaY * scalary;
			point1->mPositionY = pPoint0->mPositionY - pVector->mDeltaY * scalary;
			point1->mPositionY = pPoint0->mPositionY + pVector->mDeltaY * scalary;
			return true;
		}
	}

	//https://www.baeldung.com/cs/circle-line-segment-collision-detection
	template<typename T>
	inline bool CircleLine<T>::intersectionWithLineSegment(const LineSegment<T>& line)
	{
		double minDist = DBL_MAX;
		double maxDist = max(distanceBetweenPoints(*mCenter, *line.mPoint1), distanceBetweenPoints(*mCenter, *line.mPoint2));
		Vector<T>* pVector1 = new Vector<T>(*mCenter, *line.mPoint1);
		Vector<T>* pVector2 = new Vector<T>(*line.mPoint2, *line.mPoint1);
		Vector<T>* pVector3 = new Vector<T>(*mCenter, *line.mPoint2);
		Vector<T>* pVector4 = new Vector<T>(*line.mPoint1, *line.mPoint2);
		if (dotProduct(*pVector1, *pVector2) > 0 && dotProduct(*pVector3, *pVector4) > 0) {
			Line<T>* pLine = new Line<T>(*line.mPoint1, *line.mPoint2);
			minDist = pLine->distancetoPoint(*mCenter);
			delete pLine;
		}
		else {
			minDist = min(distanceBetweenPoints(*mCenter, *line.mPoint1), distanceBetweenPoints(*mCenter, *line.mPoint2));
		}

		delete pVector1;
		delete pVector2;
		delete pVector3;
		delete pVector4;

		if (minDist <= mRadius && maxDist >= mRadius) 
			return true;
		return false;
	}

	/// <summary> Is point on line. </summary>
	/// <param name="point"> Point. </param>
	/// <returns>True if point lies on line. </returns>
	template<typename T>
	bool isPointOnCircleLine(CircleLine<T>& line, const Point<T>& point) {
		return line.isPointOn(point);
	}

	/// <summary> Moves circle line by vector. </summary>
	///<param name="line"> Circle line. </param>
	///<param name="vector"> Vector. </param>
	/// <returns> New circular line. </returns>
	template<typename T>
	CircleLine<T>* moveCircleLineByVector(const CircleLine<T>& line, const Vector<T>& vector) {
		CircleLine<T>* pResult = new CircleLine<T>(line);
		pResult->moveByVector(vector);
		return pResult;
	}
	
	/// <summary> Distance to point. </summary>
	///<param name="line"> Circle line. </param>
	///<param name="point"> Point. </param>
	/// <returns> Distance to point. </returns>
	template<typename T>
	double distanceFromCircleLineToPoint(CircleLine<T>& line, const Point<T>& point) {
		return line.distanceToPoint(point);
	}

	/// <summary> Intersection with line. </summary>
	/// <param name="circleLine"> Circle line. </param>
	/// <param name="line"> Line. </param>
	/// <returns>True if circle line intersects with line. </returns>
	template<typename T>
	bool intersectionCircleLineLine(CircleLine<T>& circleLine, const Line<T>& line) {
		return circleLine.intersectionWithLine(line);
	}

	/// <summary> Intersection with line segment. </summary>
	/// <param name="circleLine"> Circle line. </param>
	/// <param name="line"> Line segment. </param>
	/// <returns>True if circle line intersects with line segment. </returns>
	template<typename T>
	bool intersectionCircleLineLineSegment(CircleLine<T>& circleLine, const LineSegment<T>& line) {
		return circleLine.intersectionWithLineSegment(line);
	}
#pragma endregion

#pragma region Circle
	/// <summary> Struct representing Circle. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct Circle
		: GeomteryBase
	{
		/// <summary> Constructor. </summary>
		Circle();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "point1"> First point defining line. </param>
		/// /// <param name = "point2"> Second point defining line. </param>
		Circle(const Point<T>& point, const double radius);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Circle(const Circle<T>& other);


		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Circle(Circle<T>&& other);

		/// <summary>Destructor. </summary>
		~Circle();

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		GeomteryBase& assign(const GeomteryBase& other) override;

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Circle<T>& operator=(Circle<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Circle<T>& assign(const Circle<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const GeomteryBase& other) override;

		/// <summary> Center point. </summary>
		Point<T>* mCenter;

		/// <summary> Radius of circle. </summary>
		double mRadius;

		/// <summary> Is point on line. </summary>
		/// <param name="point"> Point. </param>
		/// <returns>True if point lies on line. </returns>
		bool isPointOn(const Point<T>& point);

		/// <summary> Moves circle line by vector. </summary>
		/// <param name="vector"> Vector. </param>
		void moveByVector(const Vector<T>& vector);

		/// <summary> Distance to point. </summary>
		/// <returns> Distance to point. </returns>
		double distanceToPoint(const Point<T>& point);

		/// <summary> Intersection with line. </summary>
		/// <param name="line"> Line. </param>
		/// <returns>True if circle line intersects with line. </returns>
		bool intersectionWithLine(const Line<T>& line);

		/// <summary> Intersection with line segment. </summary>
		/// <param name="line"> Line segment. </param>
		/// <returns>True if circle intersects with line segment. </returns>
		bool intersectionWithLineSegment(const LineSegment<T>& line);
	};

	template<typename T>
	inline Circle<T>::Circle() :

		mCenter(Point<T>()),
		mRadius(0)
	{
	}

	template<typename T>
	inline Circle<T>::Circle(const Point<T>& point, const double radius) :
		mCenter(new Point<T>(point)),
		mRadius(radius)
	{
	}

	template<typename T>
	inline Circle<T>::Circle(const Circle<T>& other) :
		mCenter(new Point<T>(*(other.mCenter))),
		mRadius(other.mRadius)
	{
	}

	template<typename T>
	inline Circle<T>::Circle(Circle<T>&& other) :
		mCenter(*(other.mCenter)),
		mRadius(other.mRadius)
	{
		other.mCenter = nullptr;
	}

	template<typename T>
	inline Circle<T>::~Circle()
	{
		delete mCenter;
		mCenter = nullptr;
		mRadius = 0;
	}

	template<typename T>
	inline GeomteryBase& Circle<T>::assign(const GeomteryBase& other)
	{
		if (this != &other)
		{
			const Circle<T>& otherCircle = static_cast<const Circle<T>&>(other);
			mCenter->assign(*(otherCircle.mCenter));
			mRadius = otherCircle.mRadius;
		}

		return *this;
	}

	template<typename T>
	inline Circle<T>& Circle<T>::operator=(Circle<T>&& other)
	{
		mCenter = other.mCenter;
		mRadius = other.mRadius;
		other.mCenter = nullptr;
		other.mRadius = 0;
		return *this;
	}

	template<typename T>
	inline Circle<T>& Circle<T>::assign(const Circle<T>& other)
	{
		if (this != &other)
		{
			mCenter->assign(*other.mCenter);
			mRadius = other.mRadius;
		}
		return *this;
	}

	template<typename T>
	inline bool Circle<T>::equals(const GeomteryBase& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			const Circle<T>* otherCircle = dynamic_cast<const Circle<T>*>(&other);
			if (otherCircle != nullptr && otherCircle->mCenter->equals(*(mCenter)) && otherCircle->mRadius == mRadius) {
				return true;
			}
		}
		return false;
	}
	template<typename T>
	inline bool Circle<T>::isPointOn(const Point<T>& point)
	{
		return distanceBetweenPoints(*mCenter, point) <= mRadius;
	}

	template<typename T>
	inline void Circle<T>::moveByVector(const Vector<T>& vector)
	{
		mCenter->movePointByVector(vector);
	}

	template<typename T>
	inline double Circle<T>::distanceToPoint(const Point<T>& point)
	{
		double result = abs(distanceBetweenPoints(point, mCenter) - mRadius);
		return result <= 0 ? 0 : result;
	}

	template<typename T>
	inline bool Circle<T>::intersectionWithLine(const Line<T>& line)
	{
		return mRadius >= line.distancetoPoint(*mCenter);
	}

	//https://www.baeldung.com/cs/circle-line-segment-collision-detection
	template<typename T>
	inline bool Circle<T>::intersectionWithLineSegment(const LineSegment<T>& line)
	{
		if (this->isPointOn(*line.mPoint1) || this->isPointOn(*line.mPoint2))
			return true;
		double minDist = DBL_MAX;
		double maxDist = max(distanceBetweenPoints(*mCenter, *line.mPoint1), distanceBetweenPoints(*mCenter, *line.mPoint2));
		Vector<T>* pVector1 = new Vector<T>(*mCenter, *line.mPoint1);
		Vector<T>* pVector2 = new Vector<T>(*line.mPoint2, *line.mPoint1);
		Vector<T>* pVector3 = new Vector<T>(*mCenter, *line.mPoint2);
		Vector<T>* pVector4 = new Vector<T>(*line.mPoint1, *line.mPoint2);
		if (dotProduct(*pVector1, *pVector2) > 0 && dotProduct(*pVector3, *pVector4) > 0) {
			Line<T>* pLine = new Line<T>(*line.mPoint1, *line.mPoint2);
			minDist = pLine->distancetoPoint(*mCenter);
			delete pLine;
		}
		else {
			minDist = min(distanceBetweenPoints(*mCenter, *line.mPoint1), distanceBetweenPoints(*mCenter, *line.mPoint2));
		}

		delete pVector1;
		delete pVector2;
		delete pVector3;
		delete pVector4;

		if (minDist <= mRadius && maxDist >= mRadius)
			return true;
		return false;
	}

	/// <summary> Is point on line. </summary>
	///<param name="circle"> Circle. </param>
	/// <param name="point"> Point. </param>
	/// <returns>True if point lies on line. </returns>
	template<typename T>
	bool isPointOnCircle(Circle<T>& circle, const Point<T>& point) {
		return circle.isPointOn(point);
	}

	/// <summary> Moves circle line by vector. </summary>
	///<param name="circle"> Circle. </param>
	///<param name="vector"> Vector. </param>
	/// <returns> New circular line. </returns>
	template<typename T>
	Circle<T>* moveCircleByVector(const Circle<T>& circle, const Vector<T>& vector) {
		Circle<T>* pResult = new Circle<T>(circle);
		pResult->moveByVector(vector);
		return pResult;
	}

	/// <summary> Distance to point. </summary>
	///<param name="circle"> Circle. </param>
	///<param name="point"> Point. </param>
	/// <returns> Distance to point. </returns>
	template<typename T>
	double distanceFromCircleToPoint(Circle<T>& circle, const Point<T>& point) {
		return circle.distanceToPoint(point);
	}

	/// <summary> Intersection with line. </summary>
	/// <param name="circle"> Circle. </param>
	/// <param name="line"> Line. </param>
	/// <returns>True if circle line intersects with line. </returns>
	template<typename T>
	bool intersectionCircleLine(Circle<T>& circle, const Line<T>& line) {
		return circle.intersectionWithLine(line);
	}

	/// <summary> Intersection with line segment. </summary>
	/// <param name="circle"> Circle. </param>
	/// <param name="line"> Line segment. </param>
	/// <returns>True if circle line intersects with line segment. </returns>
	template<typename T>
	bool intersectionCircleLineSegment(Circle<T>& circle, const LineSegment<T>& line) {
		return circle.intersectionWithLineSegment(line);
	}

#pragma endregion

#pragma region Arc
	/// <summary> Struct representing Circle. </summary>
	/// <typeparam name = "T"> Data type to compute with. </typepram>
	template<typename T>
	struct Arc
		: GeomteryBase, PolySegment<T>
	{
		/// <summary> Constructor. </summary>
		Arc();

		/// <summary>Parameterized constructor. </summary>
		/// <param name = "point1"> First point defining line. </param>
		/// <param name = "point2"> Second point defining line. </param>
		/// /// <param name = "altitude"> Altitude of center point. </param>
		Arc(const Point<T>& point1, const Point<T>& point2, const double altitude);

		/// <summary>Copy constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Arc(const Arc<T>& other);


		/// <summary>Move constructor. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		Arc(Arc<T>&& other);

		/// <summary>Destructor. </summary>
		~Arc() override;

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		GeomteryBase& assign(const GeomteryBase& other) override;

		/// <summary> Move assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Arc<T>& operator=(Arc<T>&& other);

		/// <summary> Assign of object. </summary>
		/// <param name = "other"> Source objcet of taken properties. </param>
		/// <returns> Adress of the object. </returns>
		Arc<T>& assign(const Arc<T>& other);

		/// <summary> Objcet equality. </summary>
		/// <param name="other">Object to compare with. </param>
		/// <returns>True if objects are equal both in types and in values. </returns>
		bool equals(const GeomteryBase& other) override;

		/// <summary> Center point. </summary>
		Point<T>* mCenter;

		/// <summary> First point. </summary>
		Point<T>* mPoint1;

		/// <summary> Second point. </summary>
		Point<T>* mPoint2;

		/// <summary> Radius of arc. </summary>
		double mRadius;

		/// <summary> Altitude of center point. </summary>
		double mAltitude;

		/// <summary> Is point in cone defined by 3 main points. </summary>
		/// <param name="point"> Point. </param>
		/// <returns>True if point lies in cone defined by 3 main points. </returns>
		bool isPointInCone(const Point<T>& point);

		/// <summary> Is point on line. </summary>
		/// <param name="point"> Point. </param>
		/// <returns>True if point lies on line. </returns>
		bool isPointOn(const Point<T>& point) override;

		/// <summary> Moves circle line by vector. </summary>
		/// <param name="vector"> Vector. </param>
		void moveByVector(const Vector<T>& vector) override;

		/// <summary> Distance to point. </summary>
		/// <returns> Distance to point. </returns>
		double distanceToPoint(const Point<T>& point) override;

		/// <summary> Intersection with line. </summary>
		/// <param name="line"> Line. </param>
		/// <returns>True if circle line intersects with line. </returns>
		bool intersectionWithLine(const Line<T>& line);

		/// <summary> Intersection with line segment. </summary>
		/// <param name="line"> Line segment. </param>
		/// <returns>True if circle intersects with line segment. </returns>
		bool intersectionWithLineSegment(const LineSegment<T>& line);
	};

	template<typename T>
	inline Arc<T>::Arc() :
		mPoint1(Point<T>(-1, 0)),
		mPoint2(Point<T>(1, 0)),
		mCenter(Point<T>(0, 0)),
		mRadius(1),
		mAltitude(0)
	{
	}

	template<typename T>
	inline Arc<T>::Arc(const Point<T>& point1, const Point<T>& point2, const double altitude) :
		mPoint1(new Point<T>(point1)),
		mPoint2(new Point<T>(point2)),
		mAltitude(altitude)
	{
		Vector<T>* pLineVector = new Vector<T>(point1, point2);
		Line<T>* pLine = new Line<T>(point1, point2);
		Vector<T>* pNormVector = pLine->normalizedVector();
		pLineVector->vectorMultiplication(0.5);
		pNormVector->vectorMultiplication(1/pNormVector->sizeOfVector());
		pNormVector->vectorMultiplication(altitude);
		mCenter = movePointByVector(*pLineVector, point1);
		mCenter->movePointByVector(*pNormVector);
		mRadius = distanceBetweenPoints(*mPoint1, *mCenter);
		delete pLineVector;
		delete pLine;
		delete pNormVector;
	}

	template<typename T>
	inline Arc<T>::Arc(const Arc<T>& other) :
		mPoint1(new Point<T>(*(other.mPoint1))),
		mPoint2(new Point<T>(*(other.mPoint2))),
		mCenter(new Point<T>(*(other.mCenter))),
		mRadius(other.mRadius),
		mAltitude(other.mAltitude)
	{
	}

	template<typename T>
	inline Arc<T>::Arc(Arc<T>&& other) :
		mPoint1(new Point<T>(*(other.mPoint1))),
		mPoint2(new Point<T>(*(other.mPoint2))),
		mCenter(new Point<T>(*(other.mCenter))),
		mRadius(other.mRadius),
		mAltitude(other.mAltitude)
	{
		other.mPoint1 = nullptr;
		other.mPoint2 = nullptr;
		other.mCenter = nullptr;
	}

	template<typename T>
	inline Arc<T>::~Arc()
	{
		delete mPoint1;
		delete mPoint2;
		delete mCenter;
		mRadius = 0;
		mAltitude = 0;

		mPoint1 = nullptr;
		mPoint2 = nullptr;
		mCenter = nullptr;
	}

	template<typename T>
	inline GeomteryBase& Arc<T>::assign(const GeomteryBase& other)
	{
		if (this != &other)
		{
			const Arc<T>& otherArc = static_cast<const Arc<T>&>(other);
			mPoint1->assign(*(otherArc.mPoint1));
			mPoint2->assign(*(otherArc.mPoint2));
			mCenter->assign(*(otherArc.mCenter));
			mRadius = otherArc.mRadius;
			mAltitude = otherArc.mAltitude;
		}

		return *this;
	}

	template<typename T>
	inline Arc<T>& Arc<T>::operator=(Arc<T>&& other)
	{
		mPoint1 = other.mPoint1;
		mPoint2 = other.mPoint2;
		mCenter = other.mCenter;
		mRadius = other.mRadius;
		mAltitude = other.mAltitude;
		other.mPoint1 = nullptr;
		other.mPoint2 = nullptr;
		other.mCenter = nullptr;
		other.mRadius = 0;
		other.mAltitude = 0;
		return *this;
	}

	template<typename T>
	inline Arc<T>& Arc<T>::assign(const Arc<T>& other)
	{
		if (this != &other)
		{
			mPoint1->assign(*(other.mPoint1));
			mPoint2->assign(*(other.mPoint2));
			mCenter->assign(*(other.mCenter));
			mRadius = other.mRadius;
			mAltitude = other.mAltitude;
		}
		return *this;
	}
	template<typename T>
	inline bool Arc<T>::equals(const GeomteryBase& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			const Arc<T>* otherArc = dynamic_cast<const Arc<T>*>(&other);
			if (otherArc != nullptr && otherArc->mPoint1->equals(*(mPoint1)) && otherArc->mPoint2->equals(*(mPoint2)) 
				&& otherArc->mCenter->equals(*(mCenter)) && otherArc->mRadius == mRadius && otherArc->mAltitude == mAltitude) {
				return true;
			}
		}
		return false;
	}

	template<typename T>
	inline bool Arc<T>::isPointInCone(const Point<T>& point)
	{
		Vector<T>* pAxisXVector = new Vector<T>(1, 0);
		Vector<T>* pFirstPoint = new Vector<T>(*(mCenter), *(mPoint1));
		Vector<T>* pSecondPoint = new Vector<T>(*(mCenter), *(mPoint2));
		Vector<T>* pCheckingPoint = new Vector<T>(*(mCenter), point);

		double angleFirstVector = angleBetweenVectors(*(pAxisXVector), *(pFirstPoint));
		double angleSecondVector = angleBetweenVectors(*(pAxisXVector), *(pSecondPoint));
		double angleCheckingVector = angleBetweenVectors(*(pAxisXVector), *(pCheckingPoint));

		delete pAxisXVector;
		delete pFirstPoint;
		delete pSecondPoint;
		delete pCheckingPoint;

		if (angleFirstVector < angleSecondVector) {
			return angleFirstVector >= angleCheckingVector && angleSecondVector >= angleCheckingVector;
		}
		else {
			return angleFirstVector >= angleCheckingVector && angleSecondVector <= angleCheckingVector;
		}
	}

	template<typename T>
	inline bool Arc<T>::isPointOn(const Point<T>& point)
	{
		if (distanceBetweenPoints(*(mCenter, point)) = mRadius) {
			return this->isPointInCone(point);
		}
		return false;
	}

	template<typename T>
	inline void Arc<T>::moveByVector(const Vector<T>& vector)
	{
		mPoint1->movePointByVector(vector);
		mPoint2->movePointByVector(vector);
		mCenter->movePointByVector(vector);
	}

	template<typename T>
	inline double Arc<T>::distanceToPoint(const Point<T>& point)
	{
		if (this->isPointInCone(point)) {
			return abs(distanceBetweenPoints(point, *mCenter) - mRadius);
		}

		double distToPoint1 = distanceBetweenPoints(*(mPoint1), point);
		double distToPoint2 = distanceBetweenPoints(*(mPoint2), point);
		return distToPoint1 < distToPoint2 ? distToPoint1 : distToPoint2;
	}

	template<typename T>
	inline bool Arc<T>::intersectionWithLine(const Line<T>& line)
	{
		Point<T>* pPoint1 = new Point<T>();
		Point<T>* pPoint2 = new Point<T>();
		CircleLine<T>* circle = new CircleLine<T>(*mCenter, mRadius);
		if (circle->pointsOfIntersectionWithLine(line, pPoint1, pPoint2)) {
			if (pPoint1 != nullptr) {
				if (isPointOn(*pPoint1)) {
					delete pPoint1;
					delete pPoint2;
					delete circle;
					return true;
				}
				if (pPoint2 != nullptr) {
					if (isPointOn(*pPoint2)) {
						delete pPoint1;
						delete pPoint2;
						delete circle;
						return true;
					}
				}
			}
		}
		delete pPoint1;
		delete pPoint2;
		delete circle;
		return false;
	}

	template<typename T>
	inline bool Arc<T>::intersectionWithLineSegment(const LineSegment<T>& line)
	{
		Point<T>* pPoint1 = new Point<T>();
		Point<T>* pPoint2 = new Point<T>();
		CircleLine<T>* circle = new CircleLine<T>(*mCenter, mRadius);
		Line<T>* helpLine = new Line<T>(line.mPoint1, line.mPoint2);
		if (circle->pointsOfIntersectionWithLine(*helpLine, pPoint1, pPoint2)) {
			if (pPoint1 != nullptr) {
				if (isPointOn(*pPoint1) && line.isPointOn(*pPoint1)) {
					delete pPoint1;
					delete pPoint2;
					delete circle;
					delete helpLine;
					return true;
				}
				if (pPoint2 != nullptr) {
					if (isPointOn(*pPoint2) && line.isPointOn(*pPoint2)) {
						delete pPoint1;
						delete pPoint2;
						delete circle;
						delete helpLine;
						return true;
					}
				}
			}
		}
		delete pPoint1;
		delete pPoint2;
		delete circle;
		return false;
	}

#pragma endregion

	/// <summary> Abstract parent class of segments of Polyline and Polygon. </summary>
	template<typename T>
	class PolySegment
	{
	public:

		virtual bool isPointOn(const Point<T>& point) = 0;

		virtual double distancetoPoint(const Point<T>& point) = 0;

		virtual void moveByVector(const Vector<T>& vector) = 0;

		virtual bool intersectionWithLineSegment(const LineSegment<T>& line) = 0;
	};
}