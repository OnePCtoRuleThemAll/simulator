#pragma once
#include "Shape.h"

namespace Shapes {
	template <typename T>
	class MovableShape :
		Shape<T>
	{
	public:
		MovableShape(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector,
			Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd);
		void rotate(Geometry2D::Vector<T>& vector);
		void translate(Geometry2D::Point<T>& point);

	protected:
		Geometry2D::Point<T>* mCurrentPosition;
		Geometry2D::Vector<T>* mCurrentDirection;
		std::vector<float> mPositions;
	};
	template<typename T>
	inline MovableShape<T>::MovableShape(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector,
		Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd):
		Shape<T>::Shape(worldStart, worldEnd)
	{
	}
	template<typename T>
	inline void MovableShape<T>::rotate(Geometry2D::Vector<T>& vector)
	{
		if (this->mCurrentDirection == nullptr) {
			Geometry2D::Vector<T>* initialVector = new Geometry2D::Vector<T>((T)1,(T)0);
			double angle = Geometry2D::angleBetweenVectors(vector, initialVector);
			delete initialVector;
		}
		else {
			double angle = Geometry2D::angleBetweenVectors(vector, *this->mCurrentDirection);
		}
		float mappedCenterX = this->mapBetweenSystems(this->mCurrentPosition->mPositionX, false);
		float mappedCenterY = this->mapBetweenSystems(this->mCurrentPosition->mPositionY, true);
		for (int i = 0; i < this->mPositions.size(); i += 2) {
			mPositions[i] = mappedCenterX + (mPositions[i] - mappedCenterX) * cos(angle) - (mPositions[i + 1] - mappedCenterY) * sin(angle);
			mPositions[i + 1] += mappedCenterY + (mPositions[i] - mappedCenterX) * sin(angle) + (mPositions[i + 1] - mappedCenterY) * cos(angle);

		}

		this->mCurrentDirection = &vector;
	}
	template<typename T>
	inline void MovableShape<T>::translate(Geometry2D::Point<T>& point)
	{
		float deltaX = this->mapBetweenSystems(point.mPositionX, false);
		float deltaY = this->mapBetweenSystems(point.mPositionY, true);
		if (this->mCurrentPosition != nullptr) {
			float deltaX = this->mapBetweenSystems(point.mPositionX, false) - this->mapBetweenSystems(this->mCurrentPosition->mPositionX, false);
			float deltaY = this->mapBetweenSystems(point.mPositionY, true) - this->mapBetweenSystems(this->mCurrentPosition->mPositionY, true);
		}
		for (int i = 0; i < this->mPositions.size(); i++) {
			if (i % 2 == 0) {
				mPositions[i] += deltaX;
			}
			else {
				mPositions[i] += deltaY;
			}
		}

		this->mCurrentPosition = &point;
	}
}

