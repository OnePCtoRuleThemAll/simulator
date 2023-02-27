#pragma once
#include <list>
#include <vector>
#include "Agent.h"

template<typename T>
class World
{
public:
	/// <summary>Parameterized constructor. </summary>
	/// <param name = "matrixWidth"> Number of matrix rows. </param>
	/// <param name = "matrixWidth">Number of matrix columns. </param>
	World(unsigned int matrixLength, unsigned int matrixWidth);

	/// <summary>Destructor. </summary>
	~World();

	
private:
	std::vector<std::list<Agent<T>*>*>* matrix;

	unsigned int mMatrixLength;

	unsigned int mMatrixWidth;

	unsigned int mapping(unsigned int posX, unsigned int posY);
};

template<typename T>
inline World<T>::World(unsigned int matrixLength, unsigned int matrixWidth)
{
	this->mMatrixLength = matrixLength;
	this->mMatrixWidth = matrixWidth;

	this->matrix = new std::vector<std::list<Agent<T>*>*>();

	for (int i = 0; i < matrixLength * matrixWidth; i++) {
		std::list<Agent<T>*>* list = new std::list<Agent<T>*>();
		this->matrix->push_back(list);
	}
}

template<typename T>
inline World<T>::~World()
{
	for (int i = 0; i < this->matrix->size(); i++) {
		for (Agent<T>* agent : this->matrix->at(i)) {
			delete agent;
		}
	}

	this->matrix->clear();

	delete this->matrix;

	this->matrix = nullptr;
}

template<typename T>
inline unsigned int World<T>::mapping(unsigned int posX, unsigned int posY)
{
	return this->mMatrixWidth * posY + posX;
}
