#pragma once
#include "MovableShape.h"
#include "../Rendering/DrawTriangles.h"

namespace Shapes
{
	template <typename T>
	class TriangleDrawerDynamic :
		MovableShape<T>
	{
	public:
		TriangleDrawerDynamic(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector, 
			Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd, DrawTriangles* pointer);
		~TriangleDrawerDynamic();

		void rotate(Geometry2D::Vector<T>& vector);
		void translate(Geometry2D::Point<T>& point);

	protected:
		int startIndex;
		DrawTriangles* pointerToDrawerObject;

	private:
		void addToDrawObject();
		void updateData();

	};

	template<typename T>
	inline TriangleDrawerDynamic<T>::TriangleDrawerDynamic(Geometry2D::Point<T>& point, Geometry2D::Vector<T>& vector,
		Geometry2D::Point<T>& worldStart, Geometry2D::Point<T>& worldEnd, DrawTriangles* pointer):
		Shape<T>::Shape(point, vector, worldStart, worldEnd)
	{
		this->pointerToDrawerObject = pointer;

		this->mPositions.push_back(-0.01f);
		this->mPositions.push_back(-0.005f);
		this->mPositions.push_back(0.0f);
		this->mPositions.push_back(0.045f);
		this->mPositions.push_back(0.01f);
		this->mPositions.push_back(-0.005f);

		this->addToDrawObject();

		this->translate(point);
		this->rotate(vector);
	}

	template<typename T>
	inline TriangleDrawerDynamic<T>::~TriangleDrawerDynamic()
	{
		this->currentDirection = nullptr;
		this->currentPosition = nullptr;
		this->pointerToDrawerObject = nullptr;
		delete this->mPositions;
	}

	template<typename T>
	inline void TriangleDrawerDynamic<T>::rotate(Geometry2D::Vector<T>& vector)
	{
		Shape<T>::rotate(vector);
		this->updateData();
	}

	template<typename T>
	inline void TriangleDrawerDynamic<T>::translate(Geometry2D::Point<T>& point)
	{
		Shape<T>::translate(point);
		this->updateData();
	}

	template<typename T>
	inline void TriangleDrawerDynamic<T>::addToDrawObject()
	{
		this->startIndex = this->pointerToDrawerObject->getIndexOfCurrentLastVertex();
		for (int i = 0; i < 6; i++) {
			this->pointerToDrawerObject->addVertex(this->mPositions[i]);
		}
		this->pointerToDrawerObject->addActiveObject();
	}

	template<typename T>
	inline void TriangleDrawerDynamic<T>::updateData()
	{
		for (int i = 0; i < 6; i++) {
			this->pointerToDrawerObject->updateVertex(this->startIndex + i, this->mPositions[i]);
		}
	}

}