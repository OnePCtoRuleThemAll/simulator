#include "BoidSimulation.h"

void BoidSimulation::createWorld()
{
    if (mWorld != nullptr) {
        delete mWorld;
    }
    Geometry2D::MyPoint* point1 = new Geometry2D::MyPoint(0, 0);
    Geometry2D::MyPoint* point2 = new Geometry2D::MyPoint(1000, 1000);
    World* newWorld = new World(*point1, *point2, 100);
    mWorld = newWorld;
    for (int i = 0; i < 1000; i++) {
        Boid* agent = new Boid(mWorld);
        mWorld->insert(agent);
    }
}
