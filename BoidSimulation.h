#pragma once
#include "Simulation.h"
#include "Boid.h"

class BoidSimulation :
	public Simulation
{
public:

	void createWorld() override;

};