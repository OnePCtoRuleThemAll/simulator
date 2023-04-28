#pragma once
#include "Simulation.h"
#include "AgentPedestrian.h"

class ScenarioA:
	public Simulation
{
public:
	ScenarioA(int behaviorType);

	void createWorld() override;

	void runReplication(int numberOfReplications, int numberOfTicks) override;

	int mBehaviorType;
};

