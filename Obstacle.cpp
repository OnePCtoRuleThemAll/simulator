#include "Obstacle.h"

Obstacle::~Obstacle()
{
	delete mForm;
	mForm = nullptr;
}
