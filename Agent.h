#pragma once

#include "Geometry2D/Geometry2D.h"

/// <summary> Abstract parent class of all agents. </summary>
template<typename T>
class Agent
{
public:
	/// <summary> Destruktor. </summary>
	virtual ~Agent();

	/// <summary> Assign operator. </summary>
	/// <param name = "other"> Source objcet of taken properties.</param>
	/// <returns> Adress of the object. </returns>
	Agent<T>& operator=(const Agent<T>& other);

	/// <summary>  Assigning object. </summary>
	/// <param name = "other"> Source objcet of taken properties. </param>
	/// <returns> Adress of the object. </returns>
	virtual Agent<T>& assign(const Agent<T>& other) = 0;

	/// <summary> Equals operator. </summary>
	/// <param name="other">Object to compare with. </param>
	/// <returns>True if objects are equal. </returns>
	bool operator==(const Agent<T>& other);

	/// <summary> Objcet equality. </summary>
	/// <param name="other">Object to compare with. </param>
	/// <returns>True if objects are equal. </returns>
	virtual bool equals(const Agent<T>& other) = 0;

	virtual void execute() = 0;

	virtual void act() = 0;

	void moveTo(Geometry2D::Point<T>& newPosition);

	Geometry2D::Point<T>* getPosition();

	Geometry2D::Vector<T>* getDirection();

	void setDirection(Geometry2D::Vector<T>& direction);

private:
	Geometry2D::Point<T>* mPosition;

	Geometry2D::Vector<T>* mDirection;
};

template<typename T>
inline Agent<T>::~Agent()
{
	delete this->mPosition;
	delete this->mDirection;

	this->mPosition = nullptr;
	this->mDirection = nullptr;
}

template<typename T>
inline Agent<T>& Agent<T>::operator=(const Agent<T>& other)
{
	return this->assign(other);
}

template<typename T>
inline bool Agent<T>::operator==(const Agent<T>& other)
{
	return this->equals(other);;
}

template<typename T>
inline void Agent<T>::moveTo(Geometry2D::Point<T>& newPosition)
{
	delete this->mPosition;
	this->mPosition = *newPosition;
}

template<typename T>
inline Geometry2D::Point<T>* Agent<T>::getPosition()
{
	return this->mPosition;
}

template<typename T>
inline Geometry2D::Vector<T>* Agent<T>::getDirection()
{
	return this->mDirection;
}

template<typename T>
inline void Agent<T>::setDirection(Geometry2D::Vector<T>& direction)
{
	delete this->mDirection;
	this->mDirection = *direction;
}