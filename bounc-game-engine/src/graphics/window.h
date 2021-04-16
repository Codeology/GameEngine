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

			static bool mKeys[MAX_KEYS];
			static bool mMouseButtons[MAX_BUTTONS];
			static double mx, my; 

		private: 
			bool init();
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		public: 
			Window(const char *name, int width, int height);
			~Window();

			void update() const; 
			bool closed() const;

			static bool isKeyPressed(unsigned int keycode); 

		};

}}