#include "SocialForces.h"

Geometry2D::MyVector* SocialForces::behave(Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	Geometry2D::MyVector* socialForce;
	Geometry2D::MyVector* velocityChange;
	Geometry2D::MyVector* newVelocity;

	Geometry2D::MyVector* Fvelocity;
	Geometry2D::MyVector* Fpeds;
	Geometry2D::MyVector* Fobstacles;

	std::list<Agent*>* agents = this->getVisibleAgents(pAgent);
	std::list<Obstacle*>* obstacles = this->getVisibleObjects(pAgent);

	mAgentRepulsion->clear();
	mObstacleRepulsion->clear();

	Fvelocity = new Geometry2D::MyVector(0, 0);
	Fpeds = new Geometry2D::MyVector(0, 0);
	Fobstacles = new Geometry2D::MyVector(0, 0);

	Fvelocity = adaptVelocity(pAgent);

	auto agent = agents->begin();
	while (*agent != nullptr) {
		auto vec = this->repulsiveToAgentCircular(*agent, pAgent);
		Fpeds->vectorAddition(*vec);
		delete vec;
		std::next(agent);
	}

	auto obstacle = obstacles->begin();
	while (*obstacle != nullptr) {
		auto vec = this->repulsiveToObstacleEliptical(*obstacle, pAgent);
		Fobstacles->vectorAddition(*vec);
		delete vec;
		std::next(obstacle);
	}

	socialForce->vectorAddition(*Fvelocity);
	socialForce->vectorAddition(*Fpeds);
	socialForce->vectorAddition(*Fobstacles);
	socialForce->vectorMultiplication(1/*Tick*/);

	velocityChange = new Geometry2D::MyVector(*socialForce);

	newVelocity = new Geometry2D::MyVector(*pAgent->mDirection);
	newVelocity->vectorMultiplication(1 /* / Tick*/);
	newVelocity->vectorAddition(*velocityChange);

	if (newVelocity->sizeOfVector() > newAgent->getMaxVelocity()) {
		float coeficient = newAgent->getMaxVelocity() / newVelocity->sizeOfVector();
		newVelocity->vectorMultiplication(coeficient);
	}

	newVelocity->vectorMultiplication(1 /* Tick*/);

	Geometry2D::MyPoint* nextPosition = new Geometry2D::MyPoint(*pAgent->getPosition());
	Geometry2D::moveThisPointByVector(*nextPosition, *newVelocity);

	Geometry2D::MyVector* result = new Geometry2D::MyVector(*pAgent->mPosition, *nextPosition);

	delete nextPosition;
	nextPosition = nullptr;
	delete socialForce;
	socialForce = nullptr;
	delete velocityChange;
	velocityChange = nullptr;
	delete newVelocity;
	newVelocity = nullptr;
	delete Fvelocity;
	Fvelocity = nullptr;
	delete Fpeds;
	Fpeds = nullptr;
	delete Fobstacles;
	Fobstacles = nullptr;


	return result;
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
	Geometry2D::MyVector* nearest;

	Geometry2D::MyVector* d_alfabeta;
	Geometry2D::MyVector* d_alfabeta_Norm;
	double d_alfabeta_Leng;

	double bx2;
	double yab;

	Geometry2D::MyVector* dabyab;
	double dabyab_Leng;

	Geometry2D::MyVector* g_dalfabeta;

	return nullptr;
}

Geometry2D::MyVector* SocialForces::vectorToObstacle(Obstacle* obstacle, Agent* pAgent)
{
	Geometry2D::MyVector* result;
	Geometry2D::MyVector* nearest;

	switch (obstacle->mObstacleShape)
	{
	case CIRCLE:
		Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* circle =
			dynamic_cast<Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);
		nearest = new Geometry2D::MyVector(*pAgent->mPosition, *circle->mCenter);
		nearest->normalize();
		nearest->vectorMultiplication(circle->distanceToPoint(*pAgent->getPosition()));
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	case POLYGON:
		Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>* polygon =
			dynamic_cast<Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);
		
		double shortestDistance = 0;
		Geometry2D::PolySegment<Geometry2D::GeomteryBase::MyFloat>* actual = polygon->mFirst;
		while (actual != nullptr) {
			if (shortestDistance > actual->distancetoPoint(*pAgent->mPosition)) {
				shortestDistance = actual->distancetoPoint(*pAgent->mPosition);
				nearest = new Geometry2D::MyVector(actual->Vector<T>*shortestVectorToSegment(Point<T>&point, LineSegment<T>&line));
			}
			
		}
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	case POINT:
		Geometry2D::Point<Geometry2D::GeomteryBase::MyFloat>* point =
			dynamic_cast<Geometry2D::Point<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);
		nearest = new Geometry2D::MyVector(*pAgent->mPosition, *point);
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	case LINE_SEGMENT:
		Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* line =
			dynamic_cast<Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);	
		nearest = Geometry2D::shortestVectorToSegment(*pAgent->mPosition, *line);
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	default:
		break;
	}
	return result;
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
