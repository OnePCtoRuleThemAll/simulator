#pragma once
#include "Geometry2D/Geometry2D.h"


class Obstacle
{
public:
	Obstacle(Geometry2D::GeomteryBase* form);

	~Obstacle();

	Geometry2D::GeomteryBase* mForm;
};
