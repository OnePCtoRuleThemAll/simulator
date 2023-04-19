#include "ConstantVelocity.h"


Geometry2D::MyVector* ConstantVelocity::behave(Agent* pAgent)
{
	Geometry2D::MyVector* direction;
	Geometry2D::MyVector* step;
	Geometry2D::MyVector* result;

	float distanceToDest, distanceToGo, traveledDistance;
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);

	if (!newAgent->getTargetPlace()->equals(*pAgent->getPosition())) {

		// calc normalize vector
		direction = new Geometry2D::MyVector(newAgent->getTargetPlace()->mPositionX - pAgent->getPosition()->mPositionX,
			newAgent->getTargetPlace()->mPositionY - pAgent->getPosition()->mPositionY);
		direction->normalize();

		// calc the distance the agent should travel, depending on the previous shortened/extended step
		distanceToGo = newAgent->getSpeed() + mNotTraveledDistance;
		mNotTraveledDistance = 0;

		// calc next step depending on simulation tick
		step = new Geometry2D::MyVector(*direction);
		step->vectorMultiplication(distanceToGo /** pAgent->mWorld->getDeltaTime()*/);

		// correct the skipping the destination and set a new pedestrian position in the model
		Geometry2D::MyPoint* nextPosition = new Geometry2D::MyPoint(*pAgent->getPosition());
		Geometry2D::moveThisPointByVector(*nextPosition, *step);
		Geometry2D::MyPoint* correctedPosition = this->correctPossition(*nextPosition, *direction, pAgent);

		// calc the distance the pedestrian will travel
		traveledDistance = abs(pAgent->getPosition()->mPositionX - correctedPosition->mPositionX) +
			abs(pAgent->getPosition()->mPositionY - correctedPosition->mPositionY);

		// set a not traveled distance buffer for next iteration of movement - for to maintain a constant speed
		this->mNotTraveledDistance = distanceToGo - traveledDistance;

		//  from corrected position calculate vector to move by
		result = new Geometry2D::MyVector(*pAgent->mPosition, *correctedPosition);

		delete nextPosition;
		nextPosition = nullptr;
		delete correctedPosition;
		correctedPosition = nullptr;
		delete direction;
		direction = nullptr;
		delete step;
		step = nullptr;

	}
	else {
		this->mNotTraveledDistance = 0;
		result = new Geometry2D::MyVector(0, 0);
		pAgent->mDirection->assign(*result);
	}

	return result;
}

Geometry2D::MyPoint* ConstantVelocity::correctPossition(const Geometry2D::MyPoint nextPosition,
	const Geometry2D::MyVector direction, Agent* pAgent)
{
	Geometry2D::MyPoint* result = new Geometry2D::MyPoint(0, 0);

	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);

	if (direction.mDeltaX < 0 && nextPosition.mPositionX < newAgent->getTargetPlace()->mPositionX) {
		result->mPositionX = newAgent->getTargetPlace()->mPositionX;
	}
	else if (direction.mDeltaX > 0 && nextPosition.mPositionX > newAgent->getTargetPlace()->mPositionX) {
		result->mPositionX = newAgent->getTargetPlace()->mPositionX;
	}
	else {
		result->mPositionX = nextPosition.mPositionX;
	}

	if (direction.mDeltaY < 0 && nextPosition.mPositionY < newAgent->getTargetPlace()->mPositionY) {
		result->mPositionY = newAgent->getTargetPlace()->mPositionY;
	}
	else if (direction.mDeltaY > 0 && nextPosition.mPositionY > newAgent->getTargetPlace()->mPositionY) {
		result->mPositionY = newAgent->getTargetPlace()->mPositionY;
	}
	else {
		result->mPositionY = nextPosition.mPositionY;
	}

	return result;
}

