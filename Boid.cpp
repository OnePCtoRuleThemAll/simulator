#include "Boid.h"
#include <stdlib.h>
#include <time.h>

Boid::Boid(World* world)
{
	this->mWorld = world;
	Geometry2D::GeomteryBase::MyFloat posX = ((float)rand() / ((float)RAND_MAX / 
		(this->mWorld->mPointBottom->mPositionX - this->mWorld->mPointTop->mPositionX))) + this->mWorld->mPointTop->mPositionX;
	Geometry2D::GeomteryBase::MyFloat posY = ((float)rand() / ((float)RAND_MAX / 
		(this->mWorld->mPointBottom->mPositionY - this->mWorld->mPointTop->mPositionY))) + this->mWorld->mPointTop->mPositionY;
	this->mPosition = new Geometry2D::MyPoint(posX, posY);
	this->mOldPosition = new Geometry2D::MyPoint(*this->mPosition);
	posX = ((float)rand() / RAND_MAX) * 2 - 1;
	posY = ((float)rand() / RAND_MAX) * 2 - 1;
	this->mDirection = new Geometry2D::MyVector(posX, posY);
	this->mOldDirection = new Geometry2D::MyVector(*this->mDirection);
	this->mShape = new Shapes::TriangleDrawerDynamic<Geometry2D::GeomteryBase::MyFloat>(*this->mOldPosition, *this->mOldDirection,
		*this->mWorld->mPointTop, *this->mWorld->mPointBottom, this->mWorld->mAgentDrawer);
	this->mBehavoir = new std::vector<Behavior*>();
	this->mBehavoir->push_back(new BehaviorBoid());
}

Boid::~Boid()
{
	delete this->mDirection;
	delete this->mPosition;
	delete this->mOldPosition;
	delete this->mShape;
	delete this->mBehavoir;

	this->mDirection = nullptr;
	this->mPosition = nullptr;
	this->mOldPosition = nullptr;
	this->mShape = nullptr;
	this->mBehavoir = nullptr;
}

Agent& Boid::assign(const Agent& other)
{
	return *this;
}

bool Boid::equals(const Agent& other)
{
	if (this == &other) {
		return true;
	}
	else {
		const Boid* otherAgent = dynamic_cast<const Boid*>(&other);
		if (otherAgent->mDirection->equals(*this->mDirection) && otherAgent->mPosition->equals(*this->mPosition) &&
			otherAgent->mOldPosition->equals(*this->mOldPosition) && otherAgent->mWorld == this->mWorld) {
			return true;
		}
	}
	return false;
}