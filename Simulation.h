#pragma once
#include "World.h"

class Simulation
{
public:
	Simulation();

	~Simulation();

	virtual void createWorld() = 0;
	
	void runSimulation(int numberOfSimulations, int numberOfReplicataions);

	void runReplication(int numberOfReplicataions);

	World* world;
};
