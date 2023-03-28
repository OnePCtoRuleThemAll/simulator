#pragma once
#include "World.h"

class Simulation
{
public:
	Simulation();

	~Simulation();

	void createWorld();
	
	void runSimulation();

	void runReplication();

private:

	World* world;
};
