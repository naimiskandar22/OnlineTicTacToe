#include <iostream>
#include "MyPhoton.h"
#include <Windows.h>
#include <GL/GLU.h>
#include <GLFW/glfw3.h>
#include "Sprite.h"
#include "Transform2D.h"
#include "Application.h"

const int RESOLUTION_X = 800;
const int RESOLUTION_Y = 600;

double myTime = 0;
double elapsedTime = 0;

Vector2 mousePos;

MyPhoton* network = NULL;


Transform2D transform;

std::string sprtexturepath = "../media/CompCube.bmp";

void onWindowResized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//! Use ortho2D view
	gluOrtho2D(0, width, 0, height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void cursor_position_callback(GLFWwindow* window, double xPos, double yPos)
{
	if (network != NULL)
	{
		int myID = 23;
		//network->sendEvent(myID, xPos, (RESOLUTION_Y - yPos));

		mousePos = Vector2(xPos, (RESOLUTION_Y - yPos));
	}
}

void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		Application::getInstance().onMousePressed(button, mousePos);

	}
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create m_a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(RESOLUTION_X, RESOLUTION_Y, "", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback(window, onWindowResized);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	onWindowResized(window, RESOLUTION_X, RESOLUTION_Y);
	glfwSetCursorPosCallback(window, cursor_position_callback);

	glfwSetMouseButtonCallback(window, mouseButtonCallback);

	//Sprite m_sprite(sprtexturepath);

	network = new MyPhoton();
	//network->connect();

	//Application app;
	Application::getInstance().start();

	while (!glfwWindowShouldClose(window))
	{
		float temp = glfwGetTime();

		float deltaTime = temp - myTime;
		myTime = glfwGetTime();

		elapsedTime += deltaTime;

		Application::getInstance().update(elapsedTime);

		//network->run();

		//m_sprite.draw(1, 1, Vector2(network->outputdata[1], network->outputdata[2]), Vector2(80.0f, 80.0f), Vector2(1.0f, 50.0f), 0.0f, m_sprite.clr);

		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}