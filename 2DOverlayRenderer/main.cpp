#include <iostream>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "Swapchain.h"
#include "Renderer.h"
int main()
{
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(500, 500, "Test", nullptr, nullptr);
	if (!window)
		return -1;

	Renderer renderer;
	if (!renderer.init())
		return -1;

	Swapchain swapChain;
	if (!swapChain.init(renderer.getDevice(), glfwGetWin32Window(window), 500, 500, 8))
		return -1;

	while (!glfwWindowShouldClose(window))
	{
		swapChain.swapBuffers(true);
		glfwPollEvents();
	}

	renderer.destroy();
	swapChain.destroy();
}