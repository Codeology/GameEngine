 #include "window.h"

#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#define PRINT(x) std::cout << x << std::endl

namespace bounc { namespace graphics {

	//declaring some random shit that will be used below
	bool Window::mKeys[MAX_KEYS];
	bool Window::mMouseButtons[MAX_BUTTONS];
	double Window::mx;
	double Window::my; 
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(const char *name, int width, int height) {
		m_Name = name;
		m_Width = width;
		m_Height = height; 
		GLFWwindow* m_Window = nullptr;

		if (!init()) {
			exit(EXIT_FAILURE);// glfwTerminate();
		}

		for (int i=0; i<MAX_KEYS; i++) {
			mKeys[i] = false;
		}

		for (int i=0; i<MAX_BUTTONS; i++) {
			mMouseButtons[i] = false;
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
		glfwSetWindowUserPointer(m_Window, this);

		glfwSetKeyCallback(m_Window, key_callback); //CALL TO key_callback method using GLFW code
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback); //CALL TO mouse_button_callback using GLFW code
		glfwSetCursorPosCallback(m_Window, cursor_position_callback); 

		return true; 
	}

	void Window::update() const {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}

	void Window::clear() const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_Window);
	}

	bool Window::isKeyPressed(unsigned int keycode) const { 
		if (keycode >= MAX_KEYS) {
			return false; 
		}

		return mKeys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int keycode) const {
		if (keycode >= MAX_BUTTONS) {
			return false;
		}

		return mMouseButtons[keycode];
	}

	void Window::getMousePosition(double& x, double& y) const {
		x = mx; 
		y = my; 
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) { //METHOD FOR KEY CALLBACK

		Window* win = (Window*) glfwGetWindowUserPointer(window); //this line is basically getting the m_Window instance of the current window we have open
		if (action != GLFW_RELEASE) {
			win -> mKeys[key] = true;
		} else {
			win -> mKeys[key] = false;
		}
		
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) { //FINISH IMPLEMENTING THIS BIT

		Window* win = (Window*) glfwGetWindowUserPointer(window); //this line is basically getting the m_Window instance of the current window we have open
		if (action != GLFW_RELEASE) {
			win -> mMouseButtons[button] = true;
		} else {
			win -> mMouseButtons[button] = false;
		}

	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win -> mx = xpos;
		win -> my = ypos;
	}




}}