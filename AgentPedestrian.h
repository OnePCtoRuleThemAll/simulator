#pragma once
#include "Agent.h"

class AgentPedestrian :
	public Agent
{
public:
	AgentPedestrian(World* world, Geometry2D::MyPoint* target, Geometry2D::MyPoint* spawn, int behaviorType, int id);
	~AgentPedestrian();

	Agent& assign(const Agent& other) override;

	bool equals(const Agent& other) override;

	Geometry2D::MyPoint* getTargetPlace();
	float getVisibilityRadius();
	float getVelocity();
	float getMaxVelocity();
	float getTick();

	int mId;


private:
	Geometry2D::MyPoint* mTargetPlace;
	const float mVisibilityRadius = 3;
	const float mVelocity = 0.2;
	const float mMaxVelocity = 0.25;
	const float mTick = 1;

};
