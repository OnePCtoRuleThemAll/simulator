#include "Simulation.h"

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
	delete mWorld;
	mWorld = nullptr;
}

void Simulation::runSimulation(int numberOfSimulations , int numberOfReplications, int numberOfTicks)
{
	for (int i = 0; i < numberOfSimulations; i++) {
		runReplication(numberOfReplications, numberOfTicks);
	}
}

void Simulation::runReplication(int numberOfReplications, int numberOfTicks)
{
	for (int i = 0; i < numberOfReplications; i++) {
		createWorld();
		for (int j = 0; j < numberOfTicks; j++) {
			mWorld->runWorld();
		}
	}
}
