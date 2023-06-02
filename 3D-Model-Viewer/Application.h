#pragma once

#include "Shader.h"
#include "GLFW/glfw3.h"

class Application {

	public:
		Application();
		void Run();
		void Input();
		void Shutdown();


		// Window Pointer
		GLFWwindow* window;

		// Time
		float deltaTime;
		float lastFrame;
};
