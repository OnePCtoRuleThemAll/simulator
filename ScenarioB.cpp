#include "ScenarioB.h"

ScenarioB::ScenarioB(int behavior) :
	mBehaviorType(behavior)
{
}

void ScenarioB::createWorld()
{
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(20, 20);
	World* newWorld = new World(*worldBegin, *worldEnd, 2);
	mWorld = newWorld;

	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(1, 10.01);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(19, 10);

	Geometry2D::MyPoint* spawnPoint2 = new Geometry2D::MyPoint(19, 10);
	Geometry2D::MyPoint* targetPoint2 = new Geometry2D::MyPoint(1, 10);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 1);
	AgentPedestrian* agent2 = new AgentPedestrian(mWorld, targetPoint2, spawnPoint2, this->mBehaviorType, 2);

	mWorld->insert(agent);

	mWorld->insert(agent2);
}

void ScenarioB::runReplication(int numberOfReplications, int numberOfTicks)
{

	std::ofstream ofs;
	ofs.open("ScenarioB_Behavior" + std::to_string(this->mBehaviorType) + ".csv", std::ofstream::out | std::ofstream::app);

	for (int i = 0; i < numberOfReplications; i++) {

		auto start = std::chrono::high_resolution_clock::now();

		createWorld();
		for (int j = 0; j < numberOfTicks; j++) {
			mWorld->runWorld();
		}

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

		ofs << duration.count() << "\n";
	}

	ofs.close();
}

