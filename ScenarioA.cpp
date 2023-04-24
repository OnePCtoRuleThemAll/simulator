#include "ScenarioA.h"

ScenarioA::ScenarioA(int behaviorType):
	mBehaviorType(behaviorType)
{
}

void ScenarioA::createWorld()
{
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(100, 100);
	World* newWorld = new World(*worldBegin, *worldEnd, 10);
	mWorld = newWorld;

	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(20, 50.01);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(80, 50);

	Geometry2D::MyPoint* spawnPoint2 = new Geometry2D::MyPoint(80, 50);
	Geometry2D::MyPoint* targetPoint2 = new Geometry2D::MyPoint(20, 50);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 3, 1, 0.1, 1);
	AgentPedestrian* agent2 = new AgentPedestrian(mWorld, targetPoint2, spawnPoint2, this->mBehaviorType, 3, 1, 0.1, 2);

	mWorld->insert(agent);

	mWorld->insert(agent2);
}
