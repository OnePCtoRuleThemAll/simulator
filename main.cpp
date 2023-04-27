#include "Geometry2D/Geometry2D.h"
#include "tests/testGeometry/testGeometry.h"
#include "ui/ui_keeper.h"
#include "ui/console.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Rendering/Window.h"
#include "TestSimulation.h"
#include "BoidSimulation.h"
#include "ScenarioA.h"
#include "ScenarioB.h"
#include "ScenarioC.h"
#include "ScenarioD.h"
#include "ScenarioE.h"
#include "ScenarioF.h"

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

    //ScenarioA* scenarioA = new ScenarioA(1);
    //scenarioA->runReplication(10, 1000);

    //ScenarioB* scenarioB = new ScenarioB(1);
    //scenarioB->runReplication(10, 100);

    //ScenarioC* scenarioC = new ScenarioC(1);
    //scenarioC->runReplication(10, 500);

    //ScenarioD* scenarioD = new ScenarioD(1);
    //scenarioD->runReplication(10, 100);

    //ScenarioE* scenarioE = new ScenarioE(1);
    //scenarioE->runReplication(10, 100);

    //ScenarioF* scenarioF = new ScenarioF(1);
    //scenarioF->runReplication(10, 100);

    glfwDestroyWindow(windowPtr);
    glfwTerminate();


	return 0;
}