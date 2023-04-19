#include "SocialForces.h"

Geometry2D::MyVector* SocialForces::behave(Agent* pAgent)
{
	mAgentRepulsion->clear();
	mObstacleRepulsion->clear();


	return nullptr;
}

Geometry2D::MyVector* SocialForces::adaptVelocity(Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	Geometry2D::MyVector* normalisedDesiredVelocity = new Geometry2D::MyVector(newAgent->getTargetPlace()->mPositionX,
		newAgent->getTargetPlace()->mPositionY);
	normalisedDesiredVelocity->normalize();
	Geometry2D::MyVector* vector = new Geometry2D::MyVector(0, 0);

	normalisedDesiredVelocity->vectorMultiplication(adatpVel_DesiredVel);
	vector->assign(*newAgent->mDirection);
	vector->vectorMultiplication(1/* / Tick */);
	mGradientVelocity = Geometry2D::vectorAddition(*normalisedDesiredVelocity, *vector);
	mGradientVelocity->vectorMultiplication(1 / adaptVel_Ti);

	Geometry2D::MyVector* result = mGradientVelocity;

	delete normalisedDesiredVelocity;
	delete vector;
	normalisedDesiredVelocity = nullptr;
	vector = nullptr;

	return result;
}

Geometry2D::MyVector* SocialForces::repulsiveToAgentCircular(Agent* otherAgent, Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	AgentPedestrian* newOtherAgent = dynamic_cast<AgentPedestrian*>(otherAgent);
	Geometry2D::MyVector* d_alfabeta;
	Geometry2D::MyVector* d_alfabeta_Norm;
	Geometry2D::MyVector* e_alfa;
	Geometry2D::MyVector* g_dalfabeta;
	Geometry2D::MyVector* result;
	double w_Fi;

	d_alfabeta = new Geometry2D::MyVector(otherAgent->mPosition->mPositionX - pAgent->mPosition->mPositionX,
		otherAgent->mPosition->mPositionX - pAgent->mPosition->mPositionX);
	d_alfabeta_Norm = new Geometry2D::MyVector(*d_alfabeta);
	d_alfabeta_Norm->normalize();

	Geometry2D::MyVector* vector = new Geometry2D::MyVector(*pAgent->mDirection);
	vector->vectorMultiplication(1 /* / Tick*/);
	e_alfa = new Geometry2D::MyVector(*vector);

	if (e_alfa->sizeOfVector() > 0) {
		e_alfa->normalize();
	}

	d_alfabeta_Norm->vectorMultiplication(-1);
	w_Fi = (circularLambda + ((1 - circularLambda) * ((1 + Geometry2D::dotProduct(*e_alfa, *d_alfabeta_Norm)) / 2)));
	d_alfabeta_Norm->vectorMultiplication(-1);

	g_dalfabeta = new Geometry2D::MyVector(*d_alfabeta_Norm);
	g_dalfabeta->vectorMultiplication((circularForce_A * 
		exp((newAgent->getVisibilityRadius() + newOtherAgent->getVisibilityRadius() - d_alfabeta->sizeOfVector()) / circularRange_B)));

	result = g_dalfabeta;
	result->vectorMultiplication(w_Fi);

	if (this->checkAndNullIfInvalid(result)) {
		mAgentRepulsion->push_back(result);
	}

	delete d_alfabeta;
	delete d_alfabeta_Norm;
	delete e_alfa;

	return result;
}

Geometry2D::MyVector* SocialForces::repulsiveToAgentEliptical(Agent* otherAgent, Agent* pAgent)
{
	return nullptr;
}

Geometry2D::MyVector* SocialForces::repulsiveToObstacleEliptical(Obstacle* obstacle, Agent* pAgent)
{
	return nullptr;
}

std::list<Agent*>* SocialForces::getVisibleAgents(Agent* pAgent)
{
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* visibilityRange =
		new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->mPosition, 1);
	return pAgent->mWorld->searchAgents(pAgent, visibilityRange);
}

std::list<Obstacle*>* SocialForces::getVisibleObjects(Agent* pAgent)
{
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* visibilityRange =
		new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->mPosition, 1);
	return pAgent->mWorld->searchObstacles(visibilityRange);
}

bool SocialForces::checkAndNullIfInvalid(Geometry2D::MyVector* vector)
{
	bool result = isdigit(vector->mDeltaX) && isdigit(vector->mDeltaY);

	if (result) {
		vector = new Geometry2D::MyVector(0, 0);
	}

	return result;
}
