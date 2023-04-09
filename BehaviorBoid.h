#pragma once
#include "Behavior.h"
#include "Separation.h"
#include "Cohesion.h"
#include "Alignment.h"

class BehaviorBoid :
	public Behavior
{
public:
	BehaviorBoid();

	~BehaviorBoid();

	/// <summary> Mehod that defines behavior. </summary>
	/// <returns> Vector in what direction should agent move based on behaviour. </returns>
	Geometry2D::MyVector* behave(Agent* pAgent) override;

	Separation* sep;

	Cohesion* coh;

	Alignment* ali;
};

