#pragma once
#include "Behavior.h"

namespace MovementModels {
	class ConstantVelocity
	{
	public:
		ConstantVelocity();
		~ConstantVelocity();

	private:
		double mNotTraveledDistance;
		Geometry2D::MyPoint correctPossition(const Geometry2D::MyPoint nextPossition, const Geometry2D::MyVector direction);

	protected:
		Geometry2D::MyPoint computeNextPosition();
	};

	ConstantVelocity::ConstantVelocity()
	{
	}

	ConstantVelocity::~ConstantVelocity()
	{
	}
}