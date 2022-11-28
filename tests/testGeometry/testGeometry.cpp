#include "testGeometry.h"
#include "../../Geometry2D/Geometry2D.h"

namespace tests {

	PointTests::PointTests() :
		SimpleTest("Point")
	{
	}

	void PointTests::test()
	{
		Geometry2D::Point<int>* point = new Geometry2D::Point<int>(1, 1);
		Geometry2D::Point<int>* cpyPoint = new Geometry2D::Point<int>(*point);

		SimpleTest::assertTrue(point->mPositionX == cpyPoint->mPositionX, "X coordinates are equal");
		SimpleTest::assertTrue(point->mPositionY == cpyPoint->mPositionY, "Y coordinates are equal");

		delete point;
		delete cpyPoint;
	}

	VectorTests::VectorTests() :
		SimpleTest("Vector")
	{
	}

	void VectorTests::test()
	{
		Geometry2D::Vector<int>* vector = new Geometry2D::Vector<int>(2, 5);

		delete vector;
	}

	LineTests::LineTests() :
		SimpleTest("Line")
	{
	}

	void LineTests::test()
	{
		Geometry2D::Point<int>* point = new Geometry2D::Point<int>(0, 0);
		Geometry2D::Point<int>* startPoint = new Geometry2D::Point<int>(5, 5);
		Geometry2D::Point<int>* endPoint = new Geometry2D::Point<int>(3, 5);
		Geometry2D::Line<int>* line = new Geometry2D::Line<int>(*startPoint, *endPoint);

		SimpleTest::assertTrue(Geometry2D::distancePointToLine(*line, *point) == 5, "Point is 5 from line");

		delete point;
		delete startPoint;
		delete endPoint;
		delete line;
	}

	GeometryTestOverall::GeometryTestOverall() :
		ComplexTest("Geometry")
	{
		addTest(new PointTests());
		addTest(new VectorTests());
		addTest(new LineTests());
	}
}