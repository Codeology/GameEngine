#include "window.h"

#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#define PRINT(x) std::cout << x << std::endl

namespace bounc { namespace graphics {

	Window::Window(const char *name, int width, int height) {
		m_Name = name;
		m_Width = width;
		m_Height = height; 

		if (!init())
			glfwTerminate();
	}

	Window::~Window(){
		glfwTerminate();
	}

	bool Window::init() {
		if (!glfwInit())
			PRINT("Failed to initialize GLFW");
			return false;

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (!m_Window) {
			glfwTerminate();
			PRINT("Failed to create GLFW window. F.");
			return false;
		}
		glfwMakeContextCurrent(m_Window);

		return true; 
	}

	void Window::update() const {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_Window);
	}



}}