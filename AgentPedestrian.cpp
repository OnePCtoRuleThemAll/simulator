#include "AgentPedestrian.h"
#include "ConstantVelocity.h"
#include "SocialForces.h"
#include "BehaviorBoid.h"

AgentPedestrian::AgentPedestrian(World* world, Geometry2D::MyPoint* target, Geometry2D::MyPoint* spawn, int behaviorType, int id) :
	mTargetPlace(target),
	mId(id)
{
	this->mWorld = world;
	this->mPosition = spawn;
	this->mOldPosition = new Geometry2D::MyPoint(*this->mPosition);
	this->mDirection = new Geometry2D::MyVector(1, 0);
	this->mOldDirection = new Geometry2D::MyVector(1, 0);
	this->mShape = new Shapes::TriangleDrawerDynamic<Geometry2D::GeomteryBase::MyFloat>(*this->mOldPosition, *this->mOldDirection,
		*this->mWorld->mPointTop, *this->mWorld->mPointBottom, this->mWorld->mAgentDrawer);
	this->mBehavoir = new std::vector<Behavior*>();
	switch (behaviorType)
	{
	case 0:
		this->mBehavoir->push_back(new ConstantVelocity());
		break;
	case 1:
		this->mBehavoir->push_back(new SocialForces());
		break;
	case 2:
		this->mBehavoir->push_back(new BehaviorBoid());
		break;
	default:
		break;
	}
	
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
	if (this == &other) {
		return true;
	}
	else {
		const AgentPedestrian* otherAgent = dynamic_cast<const AgentPedestrian*>(&other);
		if (otherAgent->mDirection->equals(*this->mDirection) && otherAgent->mPosition->equals(*this->mPosition) &&
			otherAgent->mOldPosition->equals(*this->mOldPosition) && otherAgent->mWorld == this->mWorld) {
			return true;
		}
	}
	return false;
}

Geometry2D::MyPoint* AgentPedestrian::getTargetPlace()
{
	return this->mTargetPlace;
}

float AgentPedestrian::getVisibilityRadius()
{
	return this->mVisibilityRadius;
}

float AgentPedestrian::getMaxVelocity()
{
	return this->mMaxVelocity;
}

float AgentPedestrian::getTick()
{
	return this->mTick;
}
