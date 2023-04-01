#pragma once
#include "Behavior.h"

class BehaviorBoid :
	Behavior
{
public:
	BehaviorBoid();

	~BehaviorBoid();

	/// <summary> Mehod that defines behavior. </summary>
	/// <returns> Vector in what direction should agent move based on behaviour. </returns>
	Geometry2D::MyVector* behave(Agent* pAgent) override;
};

