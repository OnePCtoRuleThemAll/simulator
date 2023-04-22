#include "AgentPedestrian.h"
#include "ConstantVelocity.h"
#include "SocialForces.h"

AgentPedestrian::AgentPedestrian(World* world, Geometry2D::MyPoint* target, Geometry2D::MyPoint* spawn, float speed, float visibilityRange,
	float velocity, float maxVelocity) :
	mTargetPlace(target),
	mSpeed(speed),
	mVisibilityRadius(visibilityRange),
	mVelocity(velocity),
	mMaxVelocity(maxVelocity)
{
	this->mWorld = world;
	this->mPosition = spawn;
	this->mOldPosition = new Geometry2D::MyPoint(*this->mPosition);
	this->mDirection = new Geometry2D::MyVector(1, 0);
	this->mOldDirection = new Geometry2D::MyVector(1, 0);
	this->mShape = new Shapes::TriangleDrawerDynamic<Geometry2D::GeomteryBase::MyFloat>(*this->mOldPosition, *this->mOldDirection,
		*this->mWorld->mPointTop, *this->mWorld->mPointBottom, this->mWorld->mAgentDrawer);
	this->mBehavoir = new std::vector<Behavior*>();
	this->mBehavoir->push_back(new SocialForces());
}

AgentPedestrian::~AgentPedestrian()
{
	delete this->mDirection;
	delete this->mPosition;
	delete this->mOldPosition;
	delete this->mShape;
	delete this->mBehavoir;
	delete this->mTargetPlace;

	this->mDirection = nullptr;
	this->mPosition = nullptr;
	this->mOldPosition = nullptr;
	this->mShape = nullptr;
	this->mBehavoir = nullptr;
	this->mTargetPlace = nullptr;
}

Agent& AgentPedestrian::assign(const Agent& other)
{
	return *this;
}

bool AgentPedestrian::equals(const Agent& other)
{
	return false;
}

Geometry2D::MyPoint* AgentPedestrian::getTargetPlace()
{
	return this->mTargetPlace;
}

float AgentPedestrian::getSpeed()
{
	return this->mSpeed;
}

float AgentPedestrian::getVisibilityRadius()
{
	return this->mVisibilityRadius;
}

float AgentPedestrian::getVelocity()
{
	return this->mVelocity;
}

float AgentPedestrian::getMaxVelocity()
{
	return this->mMaxVelocity;
}

float AgentPedestrian::getTick()
{
	return this->mTick;
}
