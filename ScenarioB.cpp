#include "ScenarioB.h"
#include "Shapes/TriangleDrawerStatic.h"

void ScenarioB::createWorld()
{
	srand(time(NULL));
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(100, 100);
	World* newWorld = new World(*worldBegin, *worldEnd, 10);
	mWorld = newWorld;

	/*Geometry2D::MyPoint* tringleA = new Geometry2D::MyPoint(60, 70);
	Geometry2D::MyPoint* tringleB = new Geometry2D::MyPoint(50, 30);
	Geometry2D::MyPoint* tringleC = new Geometry2D::MyPoint(70, 30);

	Geometry2D::LineSegment< Geometry2D::GeomteryBase::MyFloat>* segment1 =
		new Geometry2D::LineSegment< Geometry2D::GeomteryBase::MyFloat>(*tringleA, *tringleB);
	Geometry2D::LineSegment< Geometry2D::GeomteryBase::MyFloat>* segment2 =
		new Geometry2D::LineSegment< Geometry2D::GeomteryBase::MyFloat>(*tringleB, *tringleC);
	Geometry2D::LineSegment< Geometry2D::GeomteryBase::MyFloat>* segment3 =
		new Geometry2D::LineSegment< Geometry2D::GeomteryBase::MyFloat>(*tringleC, *tringleA);


	Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>* obstacleShape1 =
		new Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>();
	obstacleShape1->add(segment1);
	obstacleShape1->add(segment2);
	obstacleShape1->add(segment3);

	Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>* triagleDrawer1 =
		new Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>(*tringleA, *tringleB, *tringleC, *worldBegin, *worldEnd);

	Obstacle* obstacle1 = new Obstacle(obstacleShape1, POLYGON, triagleDrawer1);

	mWorld->obstacles->push_back(obstacle1);*/

	//std::vector<Geometry2D::MyPoint*>* spawnPoints1 = new std::vector<Geometry2D::MyPoint*>();
	//std::vector<Geometry2D::MyPoint*>* spawnPoints2 = new std::vector<Geometry2D::MyPoint*>();
	//std::vector<Geometry2D::MyPoint*>* targets1 = new std::vector<Geometry2D::MyPoint*>();
	//std::vector<Geometry2D::MyPoint*>* targets2 = new std::vector<Geometry2D::MyPoint*>();

	//for (int i = 0; i < 20; i++) {

	//	spawnPoints1->push_back(new Geometry2D::MyPoint(1 + (rand() % 30), 1 + (rand() % 30)));
	//	spawnPoints2->push_back(new Geometry2D::MyPoint(70 + (rand() % 99), 1 + (rand() % 30)));
	//	targets1->push_back(new Geometry2D::MyPoint(80, 80));
	//	targets2->push_back(new Geometry2D::MyPoint(20, 80));
	//}

	//for (int i = 0; i < 5; i++) {
	//	AgentPedestrian* agentL = new AgentPedestrian(mWorld, targets1->at(i), spawnPoints1->at(i), 1, 5, 0.1, 0.5);
	//	AgentPedestrian* agentR = new AgentPedestrian(mWorld, targets2->at(i), spawnPoints2->at(i), 1, 5, 0.1, 0.5);
	//	mWorld->insert(agentL);
	//	mWorld->insert(agentR);
	//}
}

void ScenarioB::runReplication(int numberOfReplicataions, int numberOfTicks)
{
	for (int i = 0; i < numberOfReplicataions; i++) {
		createWorld();
		for (int j = 0; j < numberOfTicks; j++) {
			mWorld->runWorld();
			if (j % 70 == 0) {
				Geometry2D::MyPoint* target1 = new Geometry2D::MyPoint(rand() % 5 + 80, rand() % 5 + 80);
				Geometry2D::MyPoint* spawn1 = new Geometry2D::MyPoint(rand() % 10 + 10, rand() % 10 + 10);
				AgentPedestrian* agentL = new AgentPedestrian(mWorld, target1, spawn1, 1, 10, 0.2, 0.1);
				mWorld->insert(agentL);
			}
			else if(j % 72 == 0){
				Geometry2D::MyPoint* target2 = new Geometry2D::MyPoint(rand() % 5 + 10, rand() % 5 + 80);
				Geometry2D::MyPoint* spawn2 = new Geometry2D::MyPoint(rand() % 10 + 80, rand() % 10 + 10);
				AgentPedestrian* agentR = new AgentPedestrian(mWorld, target2, spawn2, 1, 10, 0.2, 0.1);
				mWorld->insert(agentR);
			}
		}
	}
}
