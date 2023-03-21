#pragma once
#include "Shape.h"
#include "../Rendering/DrawTriangles.h"

namespace Shapes
{
	template <typename T>
	class TriangleDrawer :
		Shape<T>
	{
	public:
		TriangleDrawer(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector, DrawTriangles* pointer);
		~TriangleDrawer();

		void rotate(const Geometry2D::Vector<T>& vector) override;
		void translate(const Geometry2D::Point<T>& point) override;

	protected:
		float positions[6];
		int startIndex;
		DrawTriangles* pointerToDrawerObject;
		Geometry2D::Point<T>* currentPosition;
		Geometry2D::Vector<T>* currentDirection;

	private:
		void addToDrawObject();
		void updateData();
		float scale(T value, bool vertical);
	};

	template<typename T>
	inline TriangleDrawer<T>::TriangleDrawer(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector, DrawTriangles* pointer)
	{
		this->pointerToDrawerObject = pointer;

		positions[0] = -0.015f;
		positions[1] = -0.005f;
		positions[2] = -0.005f;
		positions[3] = 0.045f;
		positions[4] = 0.005f;
		positions[5] = -0.005f;

		this->addToDrawObject();
	}

	template<typename T>
	inline TriangleDrawer<T>::~TriangleDrawer()
	{
		this->currentDirection = nullptr;
		this->currentPosition = nullptr;
		this->pointerToDrawerObject = nullptr;
		delete this->positions;
	}

	template<typename T>
	inline void TriangleDrawer<T>::rotate(const Geometry2D::Vector<T>& vector)
	{
		double angle = Geometry2D::angleBetweenVectors(vector, this->currentDirection);
		float scaledCenterX = this->scale(this->currentPosition->mPositionX, false);
		float scaledCenterY = this->scale(this->currentPosition->mPositionY, true);
		for (int i = 0; i < 6; i + 2) {
			positions[i] = scaledCenterX + (positions[i] - scaledCenterX) * cos(angle) - (positions[i + 1] - scaledCenterY) * sin(angle);
			positions[i + 1] += scaledCenterY + (positions[i] - scaledCenterX) * sin(angle) + (positions[i + 1] - scaledCenterY) * cos(angle);
		}

		this->currentDirection = vector;
		this->updateData();
	}

	template<typename T>
	inline void TriangleDrawer<T>::translate(const Geometry2D::Point<T>& point)
	{
		float deltaX = this->scale(point.mPositionX, false) - this->scale(this->currentPosition->mPositionX, false);
		float deltaY = this->scale(point.mPositionY, true) - this->scale(this->currentPosition->mPositionY, true);
		for (int i = 0; i < 6; i+2) {
			positions[i] += deltaX;
			positions[i + 1] += deltaY;
		}

		this->currentPosition = point;
		this->updateData();
	}

	template<typename T>
	inline void TriangleDrawer<T>::addToDrawObject()
	{
		this->startIndex = this->pointerToDrawerObject->getIndexOfCurrentLastVertex();
		for (auto position: this->positions) {
			this->pointerToDrawerObject->addVertex(this->position);
		}
		this->pointerToDrawerObject->addActiveObject();
	}

	template<typename T>
	inline void TriangleDrawer<T>::updateData()
	{
		for (int i = 0; i < 6; i++) {
			this->pointerToDrawerObject->updateVertex(this->startIndex + i, this->positions[i]);
		}
	}

	template<typename T>
	inline float TriangleDrawer<T>::scale(T value, bool vertical)
	{
		//if (vertical) {
		//	return (-1 + ((1 + 1) / (world.getBot().y - world.getTop().y)) * ((float)value - world.getTop().y));
		//}
		//else {
		//	return (-1 + ((1 + 1) / (world.getBot().x - world.getTop().x)) * ((float)value - world.getTop().x));
		//}

		return 0.0f;
	}
}