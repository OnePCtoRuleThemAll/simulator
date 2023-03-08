#pragma once

#include "Geometry2D/Geometry2D.h"
#include "World.h"

/// <summary> Abstract parent class of all agents. </summary>
class Agent
{
public:
	/// <summary> Destruktor. </summary>
	virtual ~Agent();

	/// <summary> Assign operator. </summary>
	/// <param name = "other"> Source objcet of taken properties.</param>
	/// <returns> Adress of the object. </returns>
	Agent& operator=(const Agent& other);

	/// <summary>  Assigning object. </summary>
	/// <param name = "other"> Source objcet of taken properties. </param>
	/// <returns> Adress of the object. </returns>
	virtual Agent& assign(const Agent& other) = 0;

	/// <summary> Equals operator. </summary>
	/// <param name="other">Object to compare with. </param>
	/// <returns>True if objects are equal. </returns>
	bool operator==(const Agent& other);

	/// <summary> Objcet equality. </summary>
	/// <param name="other">Object to compare with. </param>
	/// <returns>True if objects are equal. </returns>
	virtual bool equals(const Agent& other) = 0;

	virtual void execute() = 0;

	virtual void act() = 0;

	void moveTo(Geometry2D::MyPoint& newPosition);

	Geometry2D::MyPoint* getPosition();

	Geometry2D::MyVector* getDirection();

	void setDirection(Geometry2D::MyVector& direction);

	World* getWorld();

	void setWorld(World* world);

private:
	Geometry2D::MyPoint* mPosition;

	Geometry2D::MyVector* mDirection;

	World* mWorld;
};

inline Agent::~Agent()
{
	delete this->mPosition;
	delete this->mDirection;

	this->mPosition = nullptr;
	this->mDirection = nullptr;
}

inline Agent& Agent::operator=(const Agent& other)
{
	return this->assign(other);
}

inline bool Agent::operator==(const Agent& other)
{
	return this->equals(other);;
}

inline void Agent::moveTo(Geometry2D::MyPoint& newPosition)
{
	this->mPosition->assign(newPosition);
}

inline Geometry2D::MyPoint* Agent::getPosition()
{
	return this->mPosition;
}

inline Geometry2D::MyVector* Agent::getDirection()
{
	return this->mDirection;
}

inline void Agent::setDirection(Geometry2D::MyVector& direction)
{
	this->mDirection->assign(direction);
}

inline World* Agent::getWorld()
{
	return mWorld;
}

inline void Agent::setWorld(World* world)
{
	mWorld = world;
}
