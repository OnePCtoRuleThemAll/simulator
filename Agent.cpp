#include "Agent.h"
#include "World.h"

Agent::~Agent()
{
	delete this->mPosition;
	delete this->mDirection;
	delete this->mOldPosition;

	this->mPosition = nullptr;
	this->mDirection = nullptr;
	this->mOldPosition = nullptr;
}

Agent& Agent::operator=(const Agent& other)
{
	return this->assign(other);
}

bool Agent::operator==(const Agent& other)
{
	return this->equals(other);
}

void Agent::execute()
{
	this->mDirection = this->mBehavoir->behave(this);
	this->moveTo(*this->mDirection);
}

void Agent::act()
{
	this->execute();
	this->mShape->translate(*this->mPosition);
	this->mShape->rotate(*this->mDirection);
}

void Agent::moveTo(Geometry2D::MyVector& velocity)
{
	this->mOldPosition->assign(*mPosition);
	Geometry2D::moveThisPointByVector(*this->mPosition, velocity);
	
}

Geometry2D::MyPoint* Agent::getPosition()
{
	return this->mPosition;
}

Geometry2D::MyPoint* Agent::getOldPosition()
{
	return mOldPosition;
}

Geometry2D::MyVector* Agent::getDirection()
{
	return this->mDirection;
}

void Agent::setDirection(Geometry2D::MyVector& direction)
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
