#include "Agent.h"

template<typename T>
inline Agent<T>::~Agent()
{
	delete this->mDirection;
	delete this->mPosition;

	mDirection = nullptr;
	mPosition = nullptr;
}

template<typename T>
Agent<T>& Agent<T>::operator=(const Agent<T>& other)
{
	return this->assign(other);
}

template<typename T>
bool Agent<T>::operator==(const Agent<T>& other)
{
	return this->equals(other);
}

template<typename T>
void Agent<T>::moveTo(Geometry2D::Point<T>& newPosition)
{
	this->mPosition = *newPosition;
}

template<typename T>
Geometry2D::Point<T>* Agent<T>::getPosition()
{
	return this->mPosition;
}

template<typename T>
Geometry2D::Vector<T>* Agent<T>::getDirection()
{
	return this->mDirection;
}

template<typename T>
void Agent<T>::setDirection(Geometry2D::Vector<T>& direction)
{
	this->mDirection = *direction;
}
