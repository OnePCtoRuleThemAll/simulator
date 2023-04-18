#pragma once
#include "World.h"

class Simulation
{
public:
	Simulation();

	~Simulation();

	virtual void createWorld() = 0;
	
	void runSimulation(int numberOfSimulations, int numberOfReplicataions, int numberOfTicks);

	void runReplication(int numberOfReplicataions, int numberOfTicks);

	World* mWorld;
};
