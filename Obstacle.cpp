#include "Obstacle.h"

Obstacle::Obstacle(Geometry2D::GeomteryBase* form, OBstacleShape obstacleShape):
	mForm(form)
{
}

Obstacle::~Obstacle()
{
	delete mForm;
	mForm = nullptr;
}
