#include "Simulation.h"

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
	delete world;
	world = nullptr;
}

void Simulation::runSimulation(int numberOfSimulations , int numberOfReplicataions)
{
	for (int i = 0; i < numberOfSimulations; i++) {
		runReplication(numberOfReplicataions);
	}
}

void Simulation::runReplication(int numberOfReplicataions)
{
	for (int i = 0; i < 10000; i++) {
		world->runWorld();
	}
}
