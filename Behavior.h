#pragma once
#include "Geometry2D/Geometry2D.h"
#include "Agent.h"

/// <summary> Abstract parent class of all geometrical objects. </summary>
class Behavior
{
public:
	/// <summary> Destruktor. </summary>
	virtual ~Behavior();

	/// <summary> Mehod that defines behavior. </summary>
	/// <returns> Vector in what direction should agent move based on behaviour. </returns>
	virtual Geometry2D::MyVector* behave(Agent* pAgent) = 0;
};

