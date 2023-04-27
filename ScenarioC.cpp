#include "ScenarioC.h"

ScenarioC::ScenarioC(int behavior):
	mBehaviorType(behavior)
{
}

void ScenarioC::createWorld()
{
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(100, 100);
	World* newWorld = new World(*worldBegin, *worldEnd, 10);
	mWorld = newWorld;
}

void ScenarioC::runReplication(int numberOfReplicataions, int numberOfTicks)
{
	srand(time(NULL));
	for (int i = 0; i < numberOfReplicataions; i++) {
		createWorld();
		for (int j = 0; j < numberOfTicks; j++) {
			mWorld->runWorld();
			if (j % 5 == 0) {
				int x = rand() % 10 + 2;
				int y = x == 2 ? rand() % 15 + 5 : 5;
				Geometry2D::MyPoint* target1 = new Geometry2D::MyPoint(98, rand() % 10 + 30);
				Geometry2D::MyPoint* spawn1 = new Geometry2D::MyPoint(x, y);
				AgentPedestrian* agentL = new AgentPedestrian(mWorld, target1, spawn1, this->mBehaviorType, j);
				mWorld->insert(agentL);

				x = rand() % 10 + 88;
				y = x == 98 ? rand() % 15 + 5 : 5;
				Geometry2D::MyPoint* target2 = new Geometry2D::MyPoint(2, rand() % 10 + 30);
				Geometry2D::MyPoint* spawn2 = new Geometry2D::MyPoint(x, y);
				AgentPedestrian* agentR = new AgentPedestrian(mWorld, target2, spawn2, this->mBehaviorType, j);
				mWorld->insert(agentR);
			}
		}
	}
}
