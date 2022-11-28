#pragma once

#include "../test.h"

namespace tests
{

	class PointTests
		: public SimpleTest
	{
	public:
		PointTests();
		void test() override;
	};

	class VectorTests
		: public SimpleTest
	{
	public:
		VectorTests();
		void test() override;
	};

	class LineTests
		: public SimpleTest
	{
	public:
		LineTests();
		void test() override;
	};


	class GeometryTestOverall 
		: public ComplexTest {

	public:
		GeometryTestOverall();
	};
}