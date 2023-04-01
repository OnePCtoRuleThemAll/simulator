#include "BehaviorBoid.h"
#include "Separation.h"
#include "Cohesion.h"
#include "Alignment.h"

BehaviorBoid::BehaviorBoid()
{
}

BehaviorBoid::~BehaviorBoid()
{
}

Geometry2D::MyVector* BehaviorBoid::behave(Agent* pAgent)
{
	Separation* sep = new Separation();
	Alignment* ali = new Alignment();
	Cohesion* coh = new Cohesion();

	Geometry2D::MyVector* sepV = sep->behave(pAgent);
	Geometry2D::MyVector* aliV = ali->behave(pAgent);
	Geometry2D::MyVector* cohV = coh->behave(pAgent);

	
	sepV->vectorAddition(*aliV);
	sepV->vectorAddition(*cohV);

	
	return sepV;
}
