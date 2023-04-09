#include "Simulation.h"

Simulation::Simulation()
{
}

Simulation::~Simulation()
{
	delete mWorld;
	mWorld = nullptr;
}

void Simulation::runSimulation(int numberOfSimulations , int numberOfReplications)
{
	for (int i = 0; i < numberOfSimulations; i++) {
		runReplication(numberOfReplications);
	}
}

void Simulation::runReplication(int numberOfReplications)
{
	for (int i = 0; i < numberOfReplications; i++) {
		mWorld->runWorld();
	}
}
