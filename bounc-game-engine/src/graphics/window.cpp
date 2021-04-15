#include "window.h"

#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#define PRINT(x) std::cout << x << std::endl

namespace bounc { namespace graphics {

	GLFWwindow* m_Window;

	Window::Window(const char *name, int width, int height) {
		m_Name = name;
		m_Width = width;
		m_Height = height; 

		if (!init()) {
			exit(EXIT_FAILURE);// glfwTerminate();
		}

	}

	Window::~Window(){
		glfwTerminate();
	}

	bool Window::init() {
		if (!glfwInit()) {
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, nullptr, nullptr);
		if (m_Window == nullptr) {
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glewExperimental = GL_TRUE;

		return true; 
	}

	void Window::update() const {
		glfwPollEvents();
		glClearColor( 0.23f, 0.38f, 0.47f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );
		glfwSwapBuffers(m_Window);

	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_Window);
	}



}}