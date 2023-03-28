#include "BehaviorBoid.h"

Geometry2D::MyVector* Separation::behave(Agent* pAgent)
{
	Geometry2D::MyVector* steer = new Geometry2D::MyVector(0, 0);
	float separation = 20;
	int count = 0;
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->getPosition(), separation);
	std::list<Agent*>* list = pAgent->mWorld->search(pAgent, checkingSpace);

	for (auto agent : *list) {
		count++;
		Geometry2D::MyVector* diff = new Geometry2D::MyVector(*pAgent->getPosition(), *agent->getPosition());
		diff->normalize();
		Geometry2D::GeomteryBase::MyFloat weight = 1/Geometry2D::distanceBetweenPoints(*pAgent->getPosition(), *agent->getPosition());
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
	int count = 0;
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->getPosition(), vision);
	std::list<Agent*>* list = pAgent->mWorld->search(pAgent, checkingSpace);

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

Geometry2D::MyVector* Cohesion::behave(Agent* pAgent)
{
	Geometry2D::MyVector* steer = new Geometry2D::MyVector(0, 0);
	float vision = 50;
	int count = 0;
	Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>* checkingSpace = new Geometry2D::Circle<Geometry2D::GeomteryBase::MyFloat>(*pAgent->getPosition(), vision);
	std::list<Agent*>* list = pAgent->mWorld->search(pAgent, checkingSpace);

	for (auto agent : *list) {
		count++;
		Geometry2D::MyVector* diff = new Geometry2D::MyVector(*agent->getPosition(), *pAgent->getPosition());
		steer->vectorAddition(*diff);
	}
	if (count > 0) {
		steer->vectorMultiplication(1 / (float)count);
		steer->normalize();
	}
	return steer;
}

//Geometry2D::MyVector* BehaviorBoid::behave(Agent* pAgent)
//{
//	Separation* sep = new Separation();
//	Alignment* ali = new Alignment();
//	Cohesion* coh = new Cohesion();
//
//	Geometry2D::MyVector* sepV = sep->behave(pAgent);
//	Geometry2D::MyVector* aliV = ali->behave(pAgent);
//	Geometry2D::MyVector* cohV = coh->behave(pAgent);
//
//	
//	sepV->vectorAddition(*aliV);
//	sepV->vectorAddition(*cohV);
//
//	delete sep;
//	delete ali;
//	delete coh;
//	delete aliV;
//	delete cohV;
//	return nullptr;
//}
