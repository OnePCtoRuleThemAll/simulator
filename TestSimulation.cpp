#include "TestSimulation.h"

void TestSimlation::createWorld()
{
    if (mWorld != nullptr) {
        delete mWorld;
    }
    Geometry2D::MyPoint* point1 = new Geometry2D::MyPoint(0, 0);
    Geometry2D::MyPoint* point2 = new Geometry2D::MyPoint(100, 100);
    World* newWorld = new World(*point1, *point2, 10);
    mWorld = newWorld;

    for (int i = 0; i <= 20; i += 5) {
        TestAgent* agent = new TestAgent(mWorld, i, i);
        mWorld->insert(agent);
    }
}
