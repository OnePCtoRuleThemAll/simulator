#include "Geometry2D/Geometry2D.h"
#include "tests/testGeometry/testGeometry.h"
#include "ui/ui_keeper.h"
#include "ui/console.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Rendering/Shader.h"

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

    //const int maxAgents = 10000;
    //float verticies[maxAgents * 6];

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

    unsigned int vao;
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    unsigned int indicies[] = { 0, 1, 2 , 3, 4, 5, 6, 7, 8};

    unsigned int indexBuffer;
    glCreateBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

    Shader shaderO;
    ShaderProgramSource source = shaderO.ParseShader("Resources/Shaders/Shader.shader");

    unsigned int shader = shaderO.CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();


	return 0;
}