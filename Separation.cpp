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
	Geometry2D::MyVector* steer = new Geometry2D::MyVector(*pAgent->mDirection);
	float separation = 3000;
	int count = 0;
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->getPosition(), separation);
	std::list<Agent*>* list = pAgent->mWorld->searchAgents(pAgent, checkingSpace);
	if(list->size() > 0) { std::cout << list->size() << std::endl; }


	for (auto agent : *list) {
		count++;
		Geometry2D::MyVector* diff = new Geometry2D::MyVector(*agent->getPosition(), *pAgent->getPosition());
		diff->normalize();
		Geometry2D::GeomteryBase::MyFloat weight = 1 / Geometry2D::distanceBetweenPoints(*agent->getPosition(), *pAgent->getPosition());
		diff->vectorMultiplication(weight);
		steer->vectorAddition(*diff);
		delete diff;
	}
	if (count > 0) {
		steer->vectorMultiplication(1 / (float)count);
	}
	if (steer->sizeOfVector() > 0) {
		steer->normalize();
	}
	delete checkingSpace;
	delete list;
	return steer;
}
