#include "BoidSimulation.h"

void BoidSimulation::createWorld()
{
    if (mWorld != nullptr) {
        delete mWorld;
    }
    Geometry2D::MyPoint* point1 = new Geometry2D::MyPoint(0, 0);
    Geometry2D::MyPoint* point2 = new Geometry2D::MyPoint(100000, 100000);
    World* newWorld = new World(*point1, *point2, 10000);
    mWorld = newWorld;
    for (int i = 0; i < 500; i++) {
        Boid* agent = new Boid(mWorld);
        mWorld->insert(agent);
    }
}
