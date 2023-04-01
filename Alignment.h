#pragma once
#include "Behavior.h"

class Alignment :
	Behavior
{
public:
	Alignment();

	~Alignment();

	/// <summary> Mehod that defines behavior. </summary>
	/// <returns> Vector in what direction should agent move based on behaviour. </returns>
	Geometry2D::MyVector* behave(Agent* pAgent) override;
};