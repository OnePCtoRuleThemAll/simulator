#include "ScenarioE.h"

ScenarioE::ScenarioE(int behavior) :
	mBehaviorType(behavior)
{
}

void ScenarioE::createWorld()
{
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(20, 20);
	World* newWorld = new World(*worldBegin, *worldEnd, 2);
	mWorld = newWorld;

	Geometry2D::MyPoint* topPoint1 = new Geometry2D::MyPoint(10, 7);
	Geometry2D::MyPoint* topPoint2 = new Geometry2D::MyPoint(10.1, 7);
	Geometry2D::MyPoint* botPoint1 = new Geometry2D::MyPoint(10, 14);
	Geometry2D::MyPoint* botPoint2 = new Geometry2D::MyPoint(10.1, 14);

	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* lineSegment = 
		new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*topPoint1, *botPoint1);

	Shapes::RectangleDrawer<Geometry2D::GeomteryBase::MyFloat>* lineSegmentDraw =
		new Shapes::RectangleDrawer<Geometry2D::GeomteryBase::MyFloat>(*topPoint1, *botPoint2, *worldBegin, *worldEnd);

	Obstacle* obstacle = new Obstacle(lineSegment, LINE_SEGMENT, lineSegmentDraw);

	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(1, 11);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(19, 10);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 1);

	mWorld->insert(agent);
	mWorld->insertObstacle(obstacle);

}

void ScenarioE::runReplication(int numberOfReplications, int numberOfTicks)
{
	std::ofstream ofs;
	ofs.open("ScenarioE_Behavior" + std::to_string(this->mBehaviorType) + ".csv", std::ofstream::out | std::ofstream::app);

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
