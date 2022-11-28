#include "../simulator/Geometry2D/Geometry2D.h"
#include "tests/testGeometry/testGeometry.h"
#include "ui/ui_keeper.h"
#include "ui/console.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) { 
	//Geometry2D::Point<int>* point = new Geometry2D::Point<int>(1, 1);
	//Geometry2D::Point<int>* cpyPoint = new Geometry2D::Point<int>(*point);
	//Geometry2D::Vector<int>* vector = new Geometry2D::Vector<int>(2, 5);
	//Geometry2D::Point<int>* startPoint = new Geometry2D::Point<int>(4, 5);
	//Geometry2D::Point<int>* endPoint = new Geometry2D::Point<int>(3, 1);

	//cout << cpyPoint->mPositionX << endl;
	//point->mPositionX = 0;
	//cout << point->mPositionX << endl;
	//cout << cpyPoint->mPositionX << endl;
	//
	//Geometry2D::Line<int>* line = new Geometry2D::Line<int>(*startPoint, *endPoint);
	//cout << Geometry2D::distancePointToLine(*line, *point) << endl;
	//
	//delete point;
	//delete vector;
	//delete line;

	ui::UiKeeper keeper;
	structures::Logger::getInstance().registerConsumer(&keeper);

	keeper.registerTest(new tests::GeometryTestOverall());

	bool run = true;
	do
	{
		keeper.printTestMenu();
		std::vector<int> choice = keeper.readTestChoice();
		keeper.markTests(choice);
		keeper.resetTests();
		keeper.runTests();
		keeper.showTestResults();
		keeper.showLog();
		keeper.clearLog();
		run = keeper.readShouldContinue();
	} while (run);

	return 0;
}