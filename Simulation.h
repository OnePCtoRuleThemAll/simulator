#pragma once
#include "World.h"
#include <chrono>
#include <fstream>  

class Simulation
{
public:
	Simulation();

	~Simulation();

	virtual void createWorld() = 0;
	
	virtual void runSimulation(int numberOfSimulations, int numberOfReplicataions, int numberOfTicks);

	virtual void runReplication(int numberOfReplicataions, int numberOfTicks);

	World* mWorld;
};
