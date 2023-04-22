#pragma once
#include "Simulation.h"
#include "AgentPedestrian.h"

class ScenarioB:
	public Simulation
{
public:
	void createWorld() override;

	void runReplication(int numberOfReplicataions, int numberOfTicks) override;
};
