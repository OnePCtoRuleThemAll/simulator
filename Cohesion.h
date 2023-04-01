#pragma once
#include "Behavior.h"

class Cohesion :
	Behavior
{
public:
	Cohesion();

	~Cohesion();

	/// <summary> Mehod that defines behavior. </summary>
	/// <returns> Vector in what direction should agent move based on behaviour. </returns>
	Geometry2D::MyVector* behave(Agent* pAgent) override;
};