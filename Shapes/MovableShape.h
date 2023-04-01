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
		double angle;
		Geometry2D::Vector<float>* newVector = new Geometry2D::Vector<float>((float)vector.mDeltaX, (float)vector.mDeltaY);

		if (this->mCurrentDirection == nullptr) {
			Geometry2D::Vector<float>* initialVector = new Geometry2D::Vector<float>(0.0f, -0.1f);
			angle = Geometry2D::angleBetweenVectors(*initialVector, *newVector);
			delete initialVector;
		}

		else {
			Geometry2D::Vector<float>* newCurrentVector =
				new Geometry2D::Vector<float>((float)this->mCurrentDirection->mDeltaX,(float)this->mCurrentDirection->mDeltaY);

			angle = Geometry2D::angleBetweenVectors(*newCurrentVector, *newVector);
			delete newCurrentVector;
		}

		float mappedCenterX = this->mapBetweenSystems(this->mCurrentPosition->mPositionX, false);
		float mappedCenterY = this->mapBetweenSystems(this->mCurrentPosition->mPositionY, true);
		for (int i = 0; i < this->mPositions.size(); i += 2) {
			double s = sin(angle);
			double c = cos(angle);

			mPositions[i] -= mappedCenterX;
			mPositions[i + 1] = mappedCenterY - mPositions[i + 1];

			double xnew = mPositions[i] * c - mPositions[i + 1] * s;
			double ynew = mPositions[i] * s + mPositions[i + 1] * c;

			mPositions[i] = xnew + mappedCenterX;
			mPositions[i + 1] = mappedCenterY - ynew;
		}

		delete newVector;
		this->mCurrentDirection = &vector;
	}

	template<typename T>
	inline void MovableShape<T>::translate(Geometry2D::Point<T>& point)
	{
		float deltaX = this->mapBetweenSystems(point.mPositionX, false);
		float deltaY = this->mapBetweenSystems(point.mPositionY, true);

		if (this->mCurrentPosition != nullptr) {
			deltaX = this->mapBetweenSystems(point.mPositionX, false) - this->mapBetweenSystems(this->mCurrentPosition->mPositionX, false);
			deltaY = this->mapBetweenSystems(point.mPositionY, true) - this->mapBetweenSystems(this->mCurrentPosition->mPositionY, true);
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

