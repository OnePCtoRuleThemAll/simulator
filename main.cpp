#include "Geometry2D/Geometry2D.h"
#include "tests/testGeometry/testGeometry.h"
#include "ui/ui_keeper.h"
#include "ui/console.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Rendering/Shader.h"
#include "Shapes/CircleDrawer.h"
#include "Rendering/DrawTriangles.h"
#include <iostream>
#include "Shapes/TriangleDrawerDynamic.h"

using namespace std;

int main(int argc, char* argv[]) { 

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

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1500, 900, "Simulator", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        cout << "Error!";
    }

    Geometry2D::Point<float>* point = new Geometry2D::Point<float>(0.4f, 0.5f);
    Geometry2D::Point<float>* point2 = new Geometry2D::Point<float>(0.2f, -0.2f);
    Geometry2D::Point<float>* point3 = new Geometry2D::Point<float>(-0.4f, -0.5f);
    Geometry2D::Vector<float>* vector = new Geometry2D::Vector<float>(0.5f, 0.5f);

    Geometry2D::Point<int>* point4 = new Geometry2D::Point<int>(0, 0);
    Geometry2D::Point<int>* point5 = new Geometry2D::Point<int>(30, 30);
    Geometry2D::Point<int>* point6 = new Geometry2D::Point<int>(100, 100);
    Geometry2D::Point<int>* point7 = new Geometry2D::Point<int>(80, 80);
    Geometry2D::Vector<int>* vector2 = new Geometry2D::Vector<int>(0, 20);

    Geometry2D::Circle<float>* circle1 = new Geometry2D::Circle<float>(*point, 0.1);
    Geometry2D::Circle<float>* circle2 = new Geometry2D::Circle<float>(*point2, 0.2);
    Geometry2D::Circle<float>* circle3 = new Geometry2D::Circle<float>(*point3, 0.15);

    DrawTriangles* drawer = new DrawTriangles();
    
    Shapes::TriangleDrawerDynamic<int>* triangle = new Shapes::TriangleDrawerDynamic<int>(*point5, *vector2, *point4, *point6, drawer);

    float positions[] = {
        -0.015f, -0.005f,
        -0.005f, 0.045f,
        0.005f, -0.005f,

        0.055f, 0.05f,
        0.045f, 0.1f,
        0.035f, 0.05f,

        0.095f, 0.095f,
        0.085f, 0.045f,
        0.075f, 0.095f
    };

    for(auto vertex: positions) {
        drawer->addVertex(vertex);
    }

    drawer->addActiveObject();
    drawer->addActiveObject();
    drawer->addActiveObject();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        Shapes::CircleDrawer<float>* circleDraw = new Shapes::CircleDrawer<float>(*circle1, *point2, *point3);
        Shapes::CircleDrawer<float>* circleDraw2 = new Shapes::CircleDrawer<float>(*circle2, *point2, *point3);
        Shapes::CircleDrawer<float>* circleDraw3 = new Shapes::CircleDrawer<float>(*circle3, *point2, *point3);

        drawer->drawElements();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    //glDeleteProgram(shader);

    glfwTerminate();


	return 0;
}