#pragma once
#include "Behavior.h"
#include "Obstacle.h"
#include "AgentPedestrian.h"
#include <vector>
#include <list>
#include <cmath>

const double adaptVel_Ti = 0.5;
const double adatpVel_DesiredVel = 1.3;

const double circularForce_A = 2.5;
const double circularRange_B = 0.5;
const double circularLambda = 0.1;

const double ellipticalForce_A_obs = 4;
const double ellipticalRange_B_obs = 0.3;

class SocialForces:
	public Behavior
{
public:
	Geometry2D::MyVector* behave(Agent* pAgent) override;

private:
	Geometry2D::MyVector* mAdaptVelocity;
	Geometry2D::MyVector* mGradientVelocity;

	Geometry2D::MyVector* adaptVelocity(Agent* pAgent);
	
	Geometry2D::MyVector* repulsiveToAgentCircular(Agent* otherAgent, Agent* pAgent);

	Geometry2D::MyVector* repulsiveToObstacleEliptical(Obstacle* obstacle, Agent* pAgent);

	Geometry2D::MyVector* vectorToObstacle(Obstacle* obstacle, Agent* pAgent);

protected:
	std::list<Agent*>* getVisibleAgents(Agent* pAgent);
	std::list<Obstacle*>* getVisibleObjects(Agent* pAgent);
	bool checkAndNullIfInvalid(Geometry2D::MyVector* vector);
};

