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

	Geometry2D::MyPoint* topPoint1 = new Geometry2D::MyPoint(10, 5);
	Geometry2D::MyPoint* topPoint2 = new Geometry2D::MyPoint(10.1, 5);
	Geometry2D::MyPoint* botPoint1 = new Geometry2D::MyPoint(10, 15);
	Geometry2D::MyPoint* botPoint2 = new Geometry2D::MyPoint(10.1, 15);

	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* lineSegment = 
		new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*topPoint1, *botPoint1);

	Shapes::RectangleDrawer<Geometry2D::GeomteryBase::MyFloat>* lineSegmentDraw =
		new Shapes::RectangleDrawer<Geometry2D::GeomteryBase::MyFloat>(*topPoint1, *botPoint2, *worldBegin, *worldEnd);

	Obstacle* obstacle = new Obstacle(lineSegment, LINE_SEGMENT, lineSegmentDraw);

	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(1, 10);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(19, 10);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 1);

	mWorld->insert(agent);
	mWorld->insertObstacle(obstacle);

}
