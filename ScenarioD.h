#pragma once
#include "Simulation.h"
#include "AgentPedestrian.h"
#include "Shapes/TriangleDrawerStatic.h"

class ScenarioD :
	public Simulation
{
public:
	ScenarioD(int behavior);

	void createWorld() override;

	void runReplication(int numberOfReplications, int numberOfTicks) override;

	int mBehaviorType;
};