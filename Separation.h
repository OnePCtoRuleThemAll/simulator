#pragma once
#include "Behavior.h"

class Separation :
	Behavior
{
public:
	Separation();

	~Separation();

	/// <summary> Mehod that defines behavior. </summary>
	/// <returns> Vector in what direction should agent move based on behaviour. </returns>
	Geometry2D::MyVector* behave(Agent* pAgent) override;
};