#pragma once
#include "Geometry2D/Geometry2D.h"
#include "ObstacleShapeEnum.h"

class Obstacle
{
public:
	Obstacle(Geometry2D::GeomteryBase* form, OBstacleShape obstacleShape);

	~Obstacle();

	Geometry2D::GeomteryBase* mForm;

	OBstacleShape mObstacleShape;
};
