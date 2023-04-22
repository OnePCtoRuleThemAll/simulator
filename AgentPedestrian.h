#pragma once
#include "Agent.h"

class AgentPedestrian :
	public Agent
{
public:
	AgentPedestrian(World* world, Geometry2D::MyPoint* target, Geometry2D::MyPoint* spawn, float speed, float visibilityRange, 
		float velocity, float maxVelocity);
	~AgentPedestrian();

	Agent& assign(const Agent& other) override;

	bool equals(const Agent& other) override;

	Geometry2D::MyPoint* getTargetPlace();
	float getSpeed();
	float getVisibilityRadius();
	float getVelocity();
	float getMaxVelocity();
	float getTick();


private:
	Geometry2D::MyPoint* mTargetPlace;
	float mSpeed;
	float mVisibilityRadius;
	float mVelocity;
	float mMaxVelocity;
	float mTick = 0.5;
};
