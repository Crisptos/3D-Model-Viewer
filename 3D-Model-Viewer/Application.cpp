#include "Application.h"

Application::Application() {
	//	Initialize the GLFW library
	if (!glfwInit()) {
		std::cout << "GLFW Failed to Initialize..." << std::endl;
		Shutdown();
	}

	//	OpenGL version context
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//	Window Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1280, 720, "3D Model Viewer", NULL, NULL);

	//	Check if window was created succesfully
	if (!window) {
		std::cout << "Window Failed to Initialize..." << std::endl;
		Shutdown();
	}

	//	Grab size of the main window buffer size and append it to the ints below
	int widthBuffer, heightBuffer;
	glfwGetFramebufferSize(window, &widthBuffer, &heightBuffer);

	//	Set current context for GLEW to use
	glfwMakeContextCurrent(window);

	//	This allows modern extension features
	glewExperimental = GL_TRUE;

	//	Check to see if GLEW initialized
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW Failed to Initialize..." << std::endl;
		Shutdown();
	}

	glEnable(GL_DEPTH_TEST);

	//	Set size of viewport
	glViewport(0, 0, widthBuffer, heightBuffer);
}

void Application::Input() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Application::Run() {
	while (!glfwWindowShouldClose(window)) {
		Input();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

void Application::Shutdown() {
	glfwDestroyWindow(window);
	glfwTerminate();
}