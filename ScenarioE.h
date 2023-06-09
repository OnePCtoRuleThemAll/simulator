#pragma once
#include "Simulation.h"
#include "AgentPedestrian.h"
#include "Shapes/RectangleDrawer.h"

class ScenarioE :
	public Simulation
{
public:
	ScenarioE(int behavior);

	void createWorld() override;

	void runReplication(int numberOfReplications, int numberOfTicks) override;

	int mBehaviorType;
};