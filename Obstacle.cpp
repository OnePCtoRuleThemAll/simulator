#include "Obstacle.h"

Obstacle::Obstacle(Geometry2D::GeomteryBase* form, ObstacleShape obstacleShape, Shapes::StaticShape<Geometry2D::GeomteryBase::MyFloat>* shape):
	mForm(form),
	mObstacleShape(obstacleShape),
	mShape(shape)
{
}

Obstacle::~Obstacle()
{
	delete mForm;
	mForm = nullptr;
	delete mShape;
	mShape = nullptr;
}
