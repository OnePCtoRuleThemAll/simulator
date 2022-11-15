#include "Geometry2D.h"

int main(int argc, char* argv[]) { 
	Geometry2D::Point<int>* point = new Geometry2D::Point<int>(1, 1);
	Geometry2D::Vector<int>* vector = new Geometry2D::Vector<int>(2, 5);

	delete point;
	delete vector;

	return 0;
}