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

	Geometry2D::MyPoint* A = new Geometry2D::MyPoint(50, 55);
	Geometry2D::MyPoint* B = new Geometry2D::MyPoint(30, 30);
	Geometry2D::MyPoint* C = new Geometry2D::MyPoint(70, 30);

	Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>* triangle = new Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>();

	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* c = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*A, *B);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* a = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*B, *C);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* b = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*C, *A);

	triangle->add(a);
	triangle->add(b);
	triangle->add(c);

	Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>* triangleGl =
		new Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>(*A, *B, *C, *worldBegin, *worldEnd);
	triangle->boundingRectangle();

	Obstacle* obstacle = new Obstacle(triangle, POLYGON, triangleGl);

	mWorld->insertObstacle(obstacle);

	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(20, 50);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(80, 50);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 10, 0.5, 0.5, 1);
	mWorld->insert(agent);
}

//void ScenarioC::runReplication(int numberOfReplicataions, int numberOfTicks)
//{
//}
