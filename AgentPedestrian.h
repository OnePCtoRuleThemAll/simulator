#pragma once
#include "Agent.h"

class AgentPedestrian :
	public Agent
{
public:
	AgentPedestrian(World* world, Geometry2D::MyPoint* target, Geometry2D::MyPoint* spawn, int behaviorType, float visibilityRange,
		float velocity, float maxVelocity, int id);
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
	float mVisibilityRadius;
	float mVelocity;
	float mMaxVelocity;
	float mTick = 0.5;
};
