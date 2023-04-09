#pragma once
#include "Agent.h"
#include "Shapes/TriangleDrawerDynamic.h"
#include "BehaviorBoid.h"

class TestAgent:
	public Agent
{
public:
	TestAgent(World* world);

	~TestAgent();

	Agent& assign(const Agent& other) override;

	bool equals(const Agent& other) override;
};

class TestBehaviour :
	public Behavior
{
public:

	Geometry2D::MyVector* behave(Agent* pAgent) override;

};