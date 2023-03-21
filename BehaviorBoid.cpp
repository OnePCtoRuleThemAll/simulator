#include "BehaviorBoid.h"

Geometry2D::MyVector* Separation::behave(Agent* pAgent)
{
	Geometry2D::MyVector* steer = new Geometry2D::MyVector(0, 0);
	float separation = 20;
	int count;
	Geometry2D::Circle<Geometry2D::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::MyFloat>(*pAgent->getPosition(), separation);
	std::list<Agent*>* list = pAgent->getWorld()->search(pAgent, checkingSpace);

	for (auto agent : *list) {
		count++;
		Geometry2D::MyVector* diff = new Geometry2D::MyVector(*pAgent->getPosition(), *agent->getPosition());
		diff->normalize();
		Geometry2D::MyFloat weight = 1/Geometry2D::distanceBetweenPoints(*pAgent->getPosition(), *agent->getPosition());
		diff->vectorMultiplication(weight);
		steer->vectorAddition(*diff);
	}
	if (count > 0) {
		steer->vectorMultiplication(1/(float)count);
	}
	if (steer->sizeOfVector() > 0) {
		steer->normalize();
	}
	return steer;
}

Geometry2D::MyVector* Alignment::behave(Agent* pAgent)
{
	Geometry2D::MyVector* steer = new Geometry2D::MyVector(0, 0);
	float vision = 50;
	int count;
	Geometry2D::Circle<Geometry2D::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::MyFloat>(*pAgent->getPosition(), vision);
	std::list<Agent*>* list = pAgent->getWorld()->search(pAgent, checkingSpace);

	for (auto agent : *list) {
		count++;
		Geometry2D::MyVector* diff = new Geometry2D::MyVector(*pAgent->getPosition(), *agent->getPosition());
		diff->normalize();
		Geometry2D::MyFloat weight = 1 / Geometry2D::distanceBetweenPoints(*pAgent->getPosition(), *agent->getPosition());
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
