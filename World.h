#pragma once
#include <list>
#include <vector>
#include "Agent.h"

template<typename T>
class World
{
public:
	/// <summary>Parameterized constructor. </summary>
	/// <param name = "point1"> Top left corner of the world. </param>
	/// <param name = "point1"> Bottom right corner of the world. </param>
	/// <param name = "devider"> Number used to determin to how many blocks we want devide world. </param>
	World(const Geometry2D::MyPoint& point1, const Geometry2D::MyPoint& point2, float granulate);

	/// <summary>Destructor. </summary>
	~World();

	
private:
	std::vector<std::list<Agent*>*>* matrix;

	Geometry2D::MyPoint* mPointTop;

	Geometry2D::MyPoint* mPointBottom;

	unsigned int mMatrixColumns;
	
	unsigned int mMatrixRows;

	unsigned int mapping(Geometry2D::MyFloat posX, Geometry2D::MyFloat posY);
};

template<typename T>
inline World<T>::World(const Geometry2D::MyPoint& point1,const Geometry2D::MyPoint& point2, float granulate) :
	mPointTop(new Geometry2D::MyPoint(point1)),
	mPointBottom(new Geometry2D::MyPoint(point2))
{
	mMatrixColumns = ceil((mPointBottom->mPositionX - mPointTop->mPositionX) / granulate);
	mMatrixRows = ceil((mPointBottom->mPositionY - mPointTop->mPositionY) / granulate);

	matrix = new std::vector<std::list<Agent*>*>();

	for (int i = 0; i < mMatrixColumns * mMatrixRows; i++) {
		std::list<Agent*>* list = new std::list<Agent*>();
		matrix->push_back(list);
	}
}

template<typename T>
inline World<T>::~World()
{
	for (int i = 0; i < matrix->size(); i++) {
		for (Agent* agent : matrix->at(i)) {
			delete agent;
		}
	}

	matrix->clear();

	delete matrix;

	matrix = nullptr;
}

template<typename T>
inline unsigned int World<T>::mapping(Geometry2D::MyFloat posX, Geometry2D::MyFloat posY)
{
	if (mPointTop->mPositionX < 0) {
		unsigned int columns = ceil((posX - mPointTop->mPositionX) / mMatrixColumns);
	}
	else {
		unsigned int columns = ceil((posX) / mMatrixColumns);
	}

	if (mPointBottom->mPositionY < 0) {
		unsigned int rows = ceil((posY - mPointBottom->mPositionY) / mMatrixRows);
	}
	else {
		unsigned int rows = ceil((posY) / mMatrixRows);
	}

	return rows * mMatrixColumns + columns;
}
