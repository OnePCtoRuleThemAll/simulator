#include "Alignment.h"
#include "Agent.h"

Alignment::Alignment()
{
}

Alignment::~Alignment()
{
}

Geometry2D::MyVector* Alignment::behave(Agent* pAgent)
{
	Geometry2D::MyVector* steer = new Geometry2D::MyVector(*pAgent->mDirection);
	float vision = 70;
	int count = 0;
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->getPosition(), vision);
	std::list<Agent*>* list = pAgent->mWorld->searchAgents(pAgent, checkingSpace);

	for (auto agent : *list) {
		count++;
		Geometry2D::MyVector* diff = agent->getDirection();
		steer->vectorAddition(*diff);
	}
	if (count > 0) {
		steer->vectorMultiplication(1 / (float)count);
		steer->normalize();
	}
	return steer;
}