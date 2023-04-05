#include "Separation.h"
#include "Agent.h"

Separation::Separation()
{
}

Separation::~Separation()
{
}

Geometry2D::MyVector* Separation::behave(Agent* pAgent)
{
	Geometry2D::MyVector* steer = new Geometry2D::MyVector(0, 0);
	float separation = 20;
	int count = 0;
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->getPosition(), separation);
	std::list<Agent*>* list = pAgent->mWorld->searchAgents(pAgent, checkingSpace);

	for (auto agent : *list) {
		count++;
		Geometry2D::MyVector* diff = new Geometry2D::MyVector(*pAgent->getPosition(), *agent->getPosition());
		diff->normalize();
		Geometry2D::GeomteryBase::MyFloat weight = 1 / Geometry2D::distanceBetweenPoints(*pAgent->getPosition(), *agent->getPosition());
		diff->vectorMultiplication(weight);
		steer->vectorAddition(*diff);
	}
	if (count > 0) {
		steer->vectorMultiplication(1 / (float)count);
	}
	if (steer->sizeOfVector() > 0) {
		steer->normalize();
	}
	return steer;
}
