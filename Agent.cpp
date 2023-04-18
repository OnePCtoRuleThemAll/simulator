#include "Agent.h"
#include "World.h"
#include <fstream>
#include <iostream>

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
	this->mOldDirection->assign(*mDirection);
	Geometry2D::MyVector* result = new Geometry2D::MyVector(0, 0);
	for (int i = 0; i < this->mBehavoir->size(); i++) {
		Geometry2D::MyVector* behaviorLocal = this->mBehavoir->at(i)->behave(this);
		result->vectorAddition(*behaviorLocal);
		delete behaviorLocal;
	}
	delete this->mDirection;
	this->mDirection = result;

	this->moveTo(*this->mDirection);
}

void Agent::act()
{
	this->execute();
	this->mShape->rotate(*this->mDirection);
	this->mShape->translate(*this->mPosition);

}

void Agent::moveTo(Geometry2D::MyVector& velocity)
{
	if (canAgentMove(velocity)) {
		//std::ofstream logfile;
		//logfile.open("mylog.txt", std::ios::app);  // open the file for appending

		this->mOldPosition->assign(*mPosition);
		Geometry2D::moveThisPointByVector(*this->mPosition, velocity);

		/*logfile << this->mPosition->mPositionX << "," << this->mPosition->mPositionY << std::endl;
		logfile.close();*/
	}
}

bool Agent::canAgentMove(Geometry2D::MyVector& velocity)
{
	Geometry2D::MyPoint* newPos = Geometry2D::movePointByVector(velocity ,*this->mPosition);
	if (newPos->mPositionX < this->mWorld->mPointTop->mPositionX || newPos->mPositionX > this->mWorld->mPointBottom->mPositionX) {
		delete newPos;
		return false;
	}
	else if (newPos->mPositionY < this->mWorld->mPointTop->mPositionY || newPos->mPositionY > this->mWorld->mPointBottom->mPositionY) {
		delete newPos;
		return false;
	}
	else {
		delete newPos;
		return true;
	}
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
