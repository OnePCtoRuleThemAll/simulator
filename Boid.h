#pragma once
#include "Agent.h"
#include "Shapes/TriangleDrawerDynamic.h"
#include "BehaviorBoid.h"

class Boid :
	Agent
{
public:
	Boid(World* world);

	~Boid();
};
