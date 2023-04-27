#pragma once
#include "Behavior.h"
#include "AgentPedestrian.h"


class ConstantVelocity :
	public Behavior
{
public:
	Geometry2D::MyVector* behave(Agent* pAgent) override;

private:
	double mNotTraveledDistance = 0;
	Geometry2D::MyPoint* correctPosition(const Geometry2D::MyPoint nextPosition,
		const Geometry2D::MyVector direction, Agent* pAgent);
};
