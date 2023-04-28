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

#pragma region UserDialog

	std::string scenario;
	int behavior = -1;

	while (true) {
		// Ask the user to input a letter
		std::cout << "Choose scenario to run" << std::endl;
		std::cout << "Please enter a letter (A, B, C, D, E, F): ";
		std::getline(std::cin, scenario);

		// Convert the input letter to uppercase
		std::transform(scenario.begin(), scenario.end(), scenario.begin(), ::toupper);

		// Check if the input letter is valid
		if (scenario.size() == 1 && scenario[0] >= 'A' && scenario[0] <= 'F') {
			break;
		}
		else {
			std::cout << "Invalid input. Please enter a letter from A to F." << std::endl;
		}
	}

	while (true) {
		// Ask the user to input a number
		std::cout << "Choose behavior type to use" << std::endl;
		std::cout << "0 - constant velocity" << std::endl;
		std::cout << "1 - social forces" << std::endl;
		std::cout << "Please enter a number (0 or 1): ";
		std::cin >> behavior;

		// Check if the input number is valid
		if (behavior == 0 || behavior == 1) {
			break;
		}
		else {
			std::cout << "Invalid input. Please enter 0 or 1." << std::endl;
		}

		// Clear the input buffer to prevent invalid input from being read in the next iteration
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
#pragma endregion

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


#pragma region Scenarios

	int secnarioNumber = scenario[0] - 'A' + 1;

	ScenarioA* scenarioA = new ScenarioA(behavior);
	ScenarioB* scenarioB = new ScenarioB(behavior);
	ScenarioC* scenarioC = new ScenarioC(behavior);
	ScenarioD* scenarioD = new ScenarioD(behavior);
	ScenarioE* scenarioE = new ScenarioE(behavior);
	ScenarioF* scenarioF = new ScenarioF(behavior);

	switch (secnarioNumber)
	{
	case 1:

		scenarioA->runReplication(10, 300);

		break;
	case 2:

		scenarioB->runReplication(10, 100);

		break;
	case 3:

		scenarioC->runReplication(10, 500);

		break;
	case 4:

		scenarioD->runReplication(10, 100);

		break;
	case 5:

		scenarioE->runReplication(10, 100);

		break;
	case 6:

		scenarioF->runReplication(10, 100);

		break;
	default:
		break;
	}

#pragma endregion

	glfwDestroyWindow(windowPtr);
	glfwTerminate();


	return 0;
}