#include "ScenarioF.h"

ScenarioF::ScenarioF(int behavior) :
	mBehaviorType(behavior)
{
}

void ScenarioF::createWorld()
{
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(20, 20);
	World* newWorld = new World(*worldBegin, *worldEnd, 2);
	mWorld = newWorld;

	Geometry2D::MyPoint* A = new Geometry2D::MyPoint(8, 3);
	Geometry2D::MyPoint* B = new Geometry2D::MyPoint(3, 8);
	Geometry2D::MyPoint* C = new Geometry2D::MyPoint(12, 8);

	Geometry2D::MyPoint* K = new Geometry2D::MyPoint(15, 5);
	Geometry2D::MyPoint* L = new Geometry2D::MyPoint(11, 0);
	Geometry2D::MyPoint* M = new Geometry2D::MyPoint(18, 0);


	Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>* triangle1 = new Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>();
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* c = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*A, *B);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* a = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*B, *C);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* b = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*C, *A);

	triangle1->add(a);
	triangle1->add(b);
	triangle1->add(c);

	Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>* triangleGl =
		new Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>(*A, *B, *C, *worldBegin, *worldEnd);
	triangle1->boundingRectangle();
	c->boundingRectangle();
	//Obstacle* obstacle = new Obstacle(triangle1, POLYGON, triangleGl);
	Obstacle* obstacle = new Obstacle(c, LINE_SEGMENT, triangleGl);
	mWorld->insertObstacle(obstacle);


	Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>* triangle2 = new Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>();
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* k = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*K, *L);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* l = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*L, *M);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* m = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*M, *K);

	triangle2->add(k);
	triangle2->add(l);
	triangle2->add(m);

	Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>* triangle2Gl =
		new Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>(*K, *L, *M, *worldBegin, *worldEnd);
	triangle2->boundingRectangle();
	k->boundingRectangle();
	//Obstacle* obstacle2 = new Obstacle(triangle2, POLYGON, triangle2Gl);
	Obstacle* obstacle2 = new Obstacle(k, LINE_SEGMENT, triangle2Gl);
	mWorld->insertObstacle(obstacle2);


	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(1, 7);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(19, 5);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 1);
	mWorld->insert(agent);
}
