#pragma once
#include "Simulation.h"
#include "AgentPedestrian.h"
#include "Shapes/TriangleDrawerStatic.h"

class ScenarioC:
	public Simulation
{
public:
	ScenarioC(int behavior);
	
	void createWorld() override;

	//void runReplication(int numberOfReplicataions, int numberOfTicks) override;

	int mBehaviorType;
};
