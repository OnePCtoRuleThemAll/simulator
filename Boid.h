#pragma once
#include "Agent.h"
#include "Shapes/TriangleDrawerDynamic.h"
#include "BehaviorBoid.h"

class Boid :
	public Agent
{
public:
	Boid(World* world);

	~Boid();

	Agent& assign(const Agent& other) override;

	bool equals(const Agent& other) override;
};
