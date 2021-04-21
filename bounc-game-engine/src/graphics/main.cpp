#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#include "window.h"

#define PRINT(x) std::cout << x << std::endl

int main() {

	using namespace bounc;
	using namespace graphics; 

	Window window("bounc!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	if ( glewInit() != GLEW_OK ){
        std::cout << "Failed to init GLEW "<<std::endl;
    }

    int timer = 1; 

	while (!window.closed()) {
		timer += 1;

		window.clear();
		

		if (window.isKeyPressed(GLFW_KEY_A)) {
			PRINT("Pressed A!");

			// glBegin(GL_QUADS);
			// 	glColor3f(1.0f, 0.0f, 0.0f);
			// 	glVertex2f(-1.0, -0.5);
			// 	glVertex2f(1.0, -0.5);
			// 	glVertex2f(1.0, 0.5);
			// 	glVertex2f(-1.0, 0.5);
			// glEnd();

			// glFlush();

			glBegin(GL_QUADS);
				glVertex2f(-0.3,-0.1);
				glVertex2f(-0.1,-0.1);
				glVertex2f(-0.1,0.1);
				glVertex2f(-0.3,0.1);
			glEnd();

			glFlush();

			
		}
		else if (window.isKeyPressed(GLFW_KEY_S)) {
			PRINT("Pressed S!");
			glBegin(GL_QUADS);
				glVertex2f(-0.7, -0.5);
				glVertex2f(0.3, -0.5);
				glVertex2f(0.3, 0.5);
				glVertex2f(-0.7, 0.5);
			glEnd();

			glFlush();

			glBegin(GL_QUADS);
				glColor3f(1.0f, 0.0f, 0.0f);
				glVertex2f(-1.0, -0.5);
				glVertex2f(1.0, -0.5);
				glVertex2f(1.0, 0.5);
				glVertex2f(-1.0, 0.5);
			glEnd();

			glFlush();
		}
		else if (window.isKeyPressed(GLFW_KEY_W)) {
			PRINT("Pressed W!");
		}
		else if (window.isKeyPressed(GLFW_KEY_D)) {
			PRINT("Pressed D!");
		}
		else { 
		glBegin(GL_QUADS);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(-1.0, -0.5);
			glVertex2f(1.0, -0.5);
			glVertex2f(1.0, 0.5);
			glVertex2f(-1.0, 0.5);
		glEnd();

		glFlush();

		}

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			PRINT("pressed left!");
		}
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
			PRINT("pressed right!");
		}

		double x, y;

		window.getMousePosition(x,y);
		PRINT(x << ", " << y);


		window.update();
	}

	glfwTerminate();

	return 0;
}
