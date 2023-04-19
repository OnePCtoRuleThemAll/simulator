#include "BehaviorBoid.h"


BehaviorBoid::BehaviorBoid():
	sep(new Separation()),
	coh(new Cohesion()),
	ali(new Alignment())
{
}

BehaviorBoid::~BehaviorBoid()
{
	delete sep;
	delete coh;
	delete ali;
}

Geometry2D::MyVector* BehaviorBoid::behave(Agent* pAgent)
{
	pAgent->mDirection->normalize();
	Geometry2D::MyVector* sepV = sep->behave(pAgent);
	Geometry2D::MyVector* aliV = ali->behave(pAgent);
	Geometry2D::MyVector* cohV = coh->behave(pAgent);

	sepV->vectorMultiplication(10);
	cohV->vectorMultiplication(0.5);
	aliV->vectorMultiplication(0.2);
	
	sepV->vectorAddition(*aliV);
	sepV->vectorAddition(*cohV);
	delete aliV;
	delete cohV;

	sepV->normalize();
	sepV->vectorMultiplication(70);
	sepV->vectorAddition(*pAgent->mDirection);
	return sepV;
}
