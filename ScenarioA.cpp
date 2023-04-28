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

	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(20, 50);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(80, 50);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 1);

	mWorld->insert(agent);

}

void ScenarioA::runReplication(int numberOfReplications, int numberOfTicks)
{

	std::ofstream ofs;
	ofs.open("ScenarioA_Behavior" + std::to_string(this->mBehaviorType) + ".csv", std::ofstream::out | std::ofstream::app);

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


