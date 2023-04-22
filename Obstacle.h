#pragma once
#include "Geometry2D/Geometry2D.h"
#include "ObstacleShapeEnum.h"
#include "Shapes/StaticShape.h"

class Obstacle
{
public:
	Obstacle(Geometry2D::GeomteryBase* form, ObstacleShape obstacleShape, Shapes::StaticShape<Geometry2D::GeomteryBase::MyFloat>* shape);

	~Obstacle();

	Geometry2D::GeomteryBase* mForm;

	ObstacleShape mObstacleShape;

	Shapes::StaticShape<Geometry2D::GeomteryBase::MyFloat>* mShape;
};
