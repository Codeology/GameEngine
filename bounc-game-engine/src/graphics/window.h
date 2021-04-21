#pragma once 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace bounc { namespace graphics {
	
	class Window {
		private: 

			const char *m_Name;
			int m_Width, m_Height; 
			bool m_Closed; 
			GLFWwindow* m_Window;

			static bool mKeys[MAX_KEYS]; //array of all key buttons on keyboard (each key has true/false variable according to whether they are being pressed)
			static bool mMouseButtons[MAX_BUTTONS]; //array of all mouse buttons (true/false according to whether mouse is being set)
			static double mx, my; 

		private: 
			bool init();
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); //callback for keyboard keys
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods); //callback for mouse buttons
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos); //callback for cursor position

		public: 
			Window(const char *name, int width, int height);
			~Window();

			void clear() const;
			void update() const; 
			bool closed() const;

			bool isKeyPressed(unsigned int keycode) const; //method used in main.cpp
			bool isMouseButtonPressed(unsigned int button) const; //method used in main.cpp
			void getMousePosition(double& x, double& y) const;

		};

}}