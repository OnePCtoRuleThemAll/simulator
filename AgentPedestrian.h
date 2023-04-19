#pragma once
#include "Agent.h"

class AgentPedestrian :
	public Agent
{
public:
	AgentPedestrian(World* world, Geometry2D::MyPoint* target, Geometry2D::MyPoint* spawn, float speed, float visibility);
	~AgentPedestrian();

	Agent& assign(const Agent& other) override;

	bool equals(const Agent& other) override;

	Geometry2D::MyPoint* getTargetPlace();
	float getSpeed();
	float getVisibilityRadius();

private:
	Geometry2D::MyPoint* mTargetPlace;
	float mSpeed = 1.0f;
	float mVisibilityRadius = 1.0f;

};
