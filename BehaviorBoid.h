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

