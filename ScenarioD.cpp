#include "ScenarioD.h"

ScenarioD::ScenarioD(int behavior) :
	mBehaviorType(behavior)
{
}

void ScenarioD::createWorld()
{
	if (mWorld != nullptr) {
		delete mWorld;
	}
	Geometry2D::MyPoint* worldBegin = new Geometry2D::MyPoint(0, 0);
	Geometry2D::MyPoint* worldEnd = new Geometry2D::MyPoint(20, 20);
	World* newWorld = new World(*worldBegin, *worldEnd, 2);
	mWorld = newWorld;

	Geometry2D::MyPoint* A = new Geometry2D::MyPoint(6, 4);
	Geometry2D::MyPoint* B = new Geometry2D::MyPoint(4, 8);
	Geometry2D::MyPoint* C = new Geometry2D::MyPoint(8, 8);

	Geometry2D::MyPoint* K = new Geometry2D::MyPoint(11, 5);
	Geometry2D::MyPoint* L = new Geometry2D::MyPoint(9, 0);
	Geometry2D::MyPoint* M = new Geometry2D::MyPoint(13, 0);

	Geometry2D::MyPoint* X = new Geometry2D::MyPoint(16, 4);
	Geometry2D::MyPoint* Y = new Geometry2D::MyPoint(14, 8);
	Geometry2D::MyPoint* Z = new Geometry2D::MyPoint(18, 8);


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


	Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>* triangle3 = new Geometry2D::Polygon<Geometry2D::GeomteryBase::MyFloat>();
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* x = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*X, *Y);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* y = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*Y, *Z);
	Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>* z = new Geometry2D::LineSegment<Geometry2D::GeomteryBase::MyFloat>(*Z, *X);

	triangle3->add(x);
	triangle3->add(y);
	triangle3->add(z);

	Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>* triangle3Gl =
		new Shapes::TriangleDrawerStatic<Geometry2D::GeomteryBase::MyFloat>(*X, *Y, *Z, *worldBegin, *worldEnd);
	triangle3->boundingRectangle();
	x->boundingRectangle();
	//Obstacle* obstacle3 = new Obstacle(triangle3, POLYGON, triangle3Gl);
	Obstacle* obstacle3 = new Obstacle(x, LINE_SEGMENT, triangle3Gl);
	mWorld->insertObstacle(obstacle3);


	Geometry2D::MyPoint* spawnPoint = new Geometry2D::MyPoint(1, 7);
	Geometry2D::MyPoint* targetPoint = new Geometry2D::MyPoint(19, 5);

	AgentPedestrian* agent = new AgentPedestrian(mWorld, targetPoint, spawnPoint, this->mBehaviorType, 1);
	mWorld->insert(agent);
}

void ScenarioD::runReplication(int numberOfReplications, int numberOfTicks)
{
	std::ofstream ofs;
	ofs.open("ScenarioD_Behavior" + std::to_string(this->mBehaviorType) + ".csv", std::ofstream::out | std::ofstream::app);

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
