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
#include "Shapes/TriangleDrawerStatic.h"
#include "Shapes/RectangleDrawer.h"
#include "Rendering/Window.h"

#include "TestSimulation.h"
#include "ScenarioA.h"
#include "BoidSimulation.h"
#include "ScenarioB.h"
using namespace std;

int main(int argc, char* argv[]) { 

#ifdef _DEBUG

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

#endif // DEBUG

    Window& window = Window::getInstance();

    /* Initialize the library */
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* windowPtr = glfwCreateWindow(900, 900, "Simulator", NULL, NULL);
    if (!windowPtr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    window.setWindow(windowPtr);

    /* Make the window's context current */
    glfwMakeContextCurrent(window.getWindow());

    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("Failed to initialize GLEW");
    }

    // get the dimensions of the window
    int width, height;
    glfwGetWindowSize(window.getWindow(), &width, &height);

    // set up the viewport to be centered and symmetric
    int viewportWidth = std::min(width, height);
    int viewportHeight = viewportWidth;
    int viewportX = (width - viewportWidth) / 2;
    int viewportY = (height - viewportHeight) / 2;
    glViewport(viewportX, viewportY, viewportWidth, viewportHeight);

    /*TestSimlation* sim = new TestSimlation();
    sim->runReplication(1, 10000);*/

    //BoidSimulation* sim = new BoidSimulation();
    //sim->runReplication(1, 10000);

    //ScenarioA* scenarioA = new ScenarioA();
    //scenarioA->runReplication(3, 100);

    ScenarioB* scenarioB = new ScenarioB();
    scenarioB->runReplication(3, 5000);


    glfwDestroyWindow(windowPtr);
    glfwTerminate();


	return 0;
}