#include "ScenarioA.h"

void ScenarioA::createWorld()
{
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(100, 100);
	World* newWorld = new World(*worldBegin, *worldEnd, 10);
	mWorld = newWorld;

	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(20, 50);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(80, 80);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, 1, 1);
	mWorld->insert(agent);
}
