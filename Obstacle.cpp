#include "Obstacle.h"

Obstacle::Obstacle(Geometry2D::GeomteryBase* form):
	mForm(form)
{
}

Obstacle::~Obstacle()
{
	delete mForm;
	mForm = nullptr;
}
