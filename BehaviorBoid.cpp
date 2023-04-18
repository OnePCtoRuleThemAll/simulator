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
	Geometry2D::MyVector* sepV = sep->behave(pAgent);
	Geometry2D::MyVector* aliV = ali->behave(pAgent);
	Geometry2D::MyVector* cohV = coh->behave(pAgent);

	cohV->vectorMultiplication(20);
	aliV->vectorMultiplication(0);
	
	sepV->vectorAddition(*aliV);
	sepV->vectorAddition(*cohV);

	delete aliV;
	delete cohV;

	sepV->normalize();
	sepV->vectorMultiplication(0.4);
	return sepV;
}
