#include "../simulator/Geometry2D/Geometry2D.h"
#include "tests/testGeometry/testGeometry.h"
#include "ui/ui_keeper.h"
#include "ui/console.h"
#include <GLFW/glfw3.h>

#include <iostream>

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
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();


	return 0;
}