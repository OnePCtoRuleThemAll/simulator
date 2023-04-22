#include "SocialForces.h"

Geometry2D::MyVector* SocialForces::behave(Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	Geometry2D::MyVector* socialForce = new Geometry2D::MyVector(0, 0);
	Geometry2D::MyVector* velocityChange;
	Geometry2D::MyVector* newVelocity;

	Geometry2D::MyVector* Fvelocity;
	Geometry2D::MyVector* Fpeds;
	Geometry2D::MyVector* Fobstacles;

	std::list<Agent*>* agents = this->getVisibleAgents(pAgent);
	std::list<Obstacle*>* obstacles = this->getVisibleObjects(pAgent);

	Fpeds = new Geometry2D::MyVector(0, 0);
	Fobstacles = new Geometry2D::MyVector(0, 0);

	Fvelocity = adaptVelocity(pAgent);

	while (!agents->empty()) {

		auto agent = agents->front();
		agents->pop_front();

		auto vec = this->repulsiveToAgentCircular(agent, pAgent);
		Fpeds->vectorAddition(*vec);
		delete vec;
	}

	while (!obstacles->empty()) {

		auto obstacle = obstacles->front();
		obstacles->pop_front();

		auto vec = this->repulsiveToObstacleEliptical(obstacle, pAgent);
		Fobstacles->vectorAddition(*vec);
		delete vec;
	}

	socialForce->vectorAddition(*Fvelocity);
	socialForce->vectorAddition(*Fpeds);
	socialForce->vectorAddition(*Fobstacles);
	socialForce->vectorMultiplication(newAgent->getTick());

	velocityChange = new Geometry2D::MyVector(*socialForce);

	newVelocity = new Geometry2D::MyVector(*pAgent->mDirection);
	newVelocity->vectorMultiplication(1 / newAgent->getTick());
	newVelocity->vectorAddition(*velocityChange);

	if (newVelocity->sizeOfVector() > newAgent->getMaxVelocity()) {
		float coeficient = newAgent->getMaxVelocity() / newVelocity->sizeOfVector();
		newVelocity->vectorMultiplication(coeficient);
	}

	newVelocity->vectorMultiplication(newAgent->getTick());

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
	delete agents;
	delete obstacles;


	return result;
}

Geometry2D::MyVector* SocialForces::adaptVelocity(Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	Geometry2D::MyVector* normalisedDesiredVelocity =
		new Geometry2D::MyVector(newAgent->getTargetPlace()->mPositionX - newAgent->mPosition->mPositionX,
			newAgent->getTargetPlace()->mPositionY - newAgent->mPosition->mPositionY);
	normalisedDesiredVelocity->normalize();
	//Geometry2D::MyVector* vector;

	normalisedDesiredVelocity->vectorMultiplication(adatpVel_DesiredVel);
	//vector = new Geometry2D::MyVector(*newAgent->mDirection);
	//vector->vectorMultiplication(-1 / newAgent->getTick());
	//mGradientVelocity = Geometry2D::vectorAddition(*normalisedDesiredVelocity, *vector);
	//mGradientVelocity->vectorMultiplication(1 / adaptVel_Ti);

	//Geometry2D::MyVector* result = mGradientVelocity;
	Geometry2D::MyVector* result = normalisedDesiredVelocity;

	//delete normalisedDesiredVelocity;
	//delete vector;
	normalisedDesiredVelocity = nullptr;
	//vector = nullptr;

	return result;
}

Geometry2D::MyVector* SocialForces::repulsiveToAgentCircular(Agent* otherAgent, Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	AgentPedestrian* newOtherAgent = dynamic_cast<AgentPedestrian*>(otherAgent);
	/*Geometry2D::MyVector* d_alfabeta;
	Geometry2D::MyVector* d_alfabeta_Norm;
	Geometry2D::MyVector* e_alfa;
	Geometry2D::MyVector* g_dalfabeta;*/
	Geometry2D::MyVector* result = new Geometry2D::MyVector(0, 0);
	//double w_Fi;

	//d_alfabeta = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - otherAgent->mPosition->mPositionX,
	//	pAgent->mPosition->mPositionY - otherAgent->mPosition->mPositionY);
	//d_alfabeta_Norm = new Geometry2D::MyVector(*d_alfabeta);
	//d_alfabeta_Norm->normalize();

	//Geometry2D::MyVector* vector = new Geometry2D::MyVector(*pAgent->mDirection);
	//vector->vectorMultiplication(1 / newAgent->getTick());
	//e_alfa = new Geometry2D::MyVector(*vector);

	//if (e_alfa->sizeOfVector() > 0) {
	//	e_alfa->normalize();
	//}

	//d_alfabeta_Norm->vectorMultiplication(-1);
	//w_Fi = (circularLambda + ((1 - circularLambda) * ((1 + Geometry2D::dotProduct(*e_alfa, *d_alfabeta_Norm)) / 2)));
	//d_alfabeta_Norm->vectorMultiplication(-1);

	//g_dalfabeta = new Geometry2D::MyVector(*d_alfabeta_Norm);
	//double coeficient = circularForce_A * exp((newAgent->getVisibilityRadius() + newOtherAgent->getVisibilityRadius() - d_alfabeta->sizeOfVector()) / circularRange_B);
	//g_dalfabeta->vectorMultiplication(coeficient);

	//result = g_dalfabeta;
	//result->vectorMultiplication(w_Fi);

	//delete vector;
	//vector = nullptr;
	//delete d_alfabeta;
	//d_alfabeta = nullptr;
	//delete d_alfabeta_Norm;
	//d_alfabeta_Norm = nullptr;
	//delete e_alfa;
	//e_alfa = nullptr;
	//g_dalfabeta = nullptr;

	double dx = pAgent->mPosition->mPositionX - otherAgent->mPosition->mPositionX;
	double dy = pAgent->mPosition->mPositionY - otherAgent->mPosition->mPositionY;
	double dist = sqrt(dx * dx + dy * dy);
	double overlap = PERSON_RADIUS * 2 - dist;
	if (overlap > 0) {
		double fx = REPULSION_FACTOR * dx / dist * overlap;
		double fy = REPULSION_FACTOR * dy / dist * overlap;
		delete result;
		result = new Geometry2D::MyVector(fx, fy);
	}

	return result;
}

Geometry2D::MyVector* SocialForces::repulsiveToObstacleEliptical(Obstacle* obstacle, Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);

	Geometry2D::MyVector* d_alfabeta;
	Geometry2D::MyVector* d_alfabeta_Norm;
	double d_alfabeta_Leng;

	double bx2;
	Geometry2D::MyVector* yab;

	Geometry2D::MyVector* dabyab;
	double dabyab_Leng;

	Geometry2D::MyVector* result;

	d_alfabeta = this->vectorToObstacle(obstacle, pAgent);
	d_alfabeta_Norm = new Geometry2D::MyVector(*d_alfabeta);
	d_alfabeta_Norm->normalize();
	d_alfabeta_Leng = d_alfabeta->sizeOfVector();

	yab = new Geometry2D::MyVector(*pAgent->mDirection);
	yab->vectorMultiplication(newAgent->getTick());
	yab->vectorMultiplication(-1);
	dabyab = new Geometry2D::MyVector(d_alfabeta->mDeltaX - yab->mDeltaX, d_alfabeta->mDeltaY - yab->mDeltaY);
	dabyab_Leng = dabyab->sizeOfVector();
	yab->vectorMultiplication(-1);
	bx2 = sqrt(pow((d_alfabeta_Leng + dabyab_Leng), 2) - pow(yab->sizeOfVector(), 2));

	result = new Geometry2D::MyVector(*dabyab);
	result->vectorMultiplication(1 / dabyab_Leng);
	result->vectorAddition(*d_alfabeta_Norm);
	result->vectorMultiplication(ellipticalForce_A_obs * exp(((-1) * (bx2 / 2)) /
		ellipticalRange_B_obs) * ((d_alfabeta_Leng + dabyab_Leng) / bx2) * 0.5);

	delete d_alfabeta;
	delete d_alfabeta_Norm;
	delete yab;
	delete dabyab;

	return result;
}

Geometry2D::MyVector* SocialForces::vectorToObstacle(Obstacle* obstacle, Agent* pAgent)
{
	Geometry2D::MyVector* result = new Geometry2D::MyVector(0, 0);
	Geometry2D::MyVector* nearest = new Geometry2D::MyVector(0, 0);

	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* circle;
	Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>* polygon;
	Geometry2D::Point<Geometry2D::GeomteryBase::MyFloat>* point;
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* line;

	switch (obstacle->mObstacleShape)
	{
	case CIRCLE: {
		circle = dynamic_cast<Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);
		delete nearest;
		delete result;
		nearest = new Geometry2D::MyVector(*pAgent->mPosition, *circle->mCenter);
		nearest->normalize();
		nearest->vectorMultiplication(circle->distanceToPoint(*pAgent->getPosition()));
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	}
	case POLYGON: {
		polygon = dynamic_cast<Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);
		delete nearest;
		delete result;
		double shortestDistance = 0;
		Geometry2D::PolySegment<Geometry2D::GeomteryBase::MyFloat>* actual = polygon->mFirst;
		while (actual != nullptr) {
			if (shortestDistance > actual->distancetoPoint(*pAgent->mPosition)) {
				shortestDistance = actual->distancetoPoint(*pAgent->mPosition);
				nearest = new Geometry2D::MyVector(*actual->shortestVectorToSegment(*pAgent->mPosition));
			}

		}
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	}
	case POINT: {
		point = dynamic_cast<Geometry2D::Point<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);
		delete nearest;
		delete result;
		nearest = new Geometry2D::MyVector(*pAgent->mPosition, *point);
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	}
	case LINE_SEGMENT: {
		line = dynamic_cast<Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>*>(obstacle->mForm);
		delete nearest;
		delete result;
		nearest = line->shortestVectorToSegment(*pAgent->mPosition);
		result = new Geometry2D::MyVector(pAgent->mPosition->mPositionX - nearest->mDeltaX, pAgent->mPosition->mPositionY - nearest->mDeltaY);
		break;
	}
	default:
		break;
	}

	delete nearest;

	return result;
}

std::list<Agent*>* SocialForces::getVisibleAgents(Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* visibilityRange =
		new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->mPosition, newAgent->getVisibilityRadius());
	std::list<Agent*>* list = pAgent->mWorld->searchAgents(pAgent, visibilityRange);
	delete visibilityRange;
	return list;
}

std::list<Obstacle*>* SocialForces::getVisibleObjects(Agent* pAgent)
{
	AgentPedestrian* newAgent = dynamic_cast<AgentPedestrian*>(pAgent);
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* visibilityRange =
		new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->mPosition, newAgent->getVisibilityRadius());
	std::list<Obstacle*>* list = pAgent->mWorld->searchObstacles(visibilityRange);
	delete visibilityRange;
	return list;
}

bool SocialForces::checkAndNullIfInvalid(Geometry2D::MyVector* vector)
{
	bool result = !isnan(vector->mDeltaX) && !isnan(vector->mDeltaY);

	if (result) {
		vector = new Geometry2D::MyVector(0, 0);
	}

	return result;
}
