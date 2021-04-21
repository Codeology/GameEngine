#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#include "window.h"


#define PRINT(x) std::cout << x << std::endl

double cpu_move_right(double x) {
	return x += 0.01;
}

double cpu_move_left(double x) {
	return x -= 0.01;
}

double cpu_move_up(double y) {
	return y += 0.2;
}

double cpu_move_down(double y) {
	return y -= 0.2;
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    double num = fMin + f * (fMax - fMin);
    return num;
}

int score = 0;

bool cpu_moving_right = true;
bool cpu_moving_left = false;


int main() {

	using namespace bounc;
	using namespace graphics; 

	Window window("bounc!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	if ( glewInit() != GLEW_OK ){
        std::cout << "Failed to init GLEW "<<std::endl;
    }

    double x_point = 0.0;
    double y_point = 0.0;

    double cpu_x_point = -0.9;
    double cpu_y_point = 0.9;

    double random_x = fRand(-1.0, 1.0);
	double random_y = fRand(-1.0, 1.0);

	while (!window.closed()) {

		//cpu object movements 
		if (cpu_moving_right) {
			cpu_x_point = cpu_move_right(cpu_x_point);
		} else if (cpu_moving_left) {
			cpu_x_point = cpu_move_left(cpu_x_point);
		}

		if (cpu_x_point >= 0.9 && cpu_moving_right) { //move down
			cpu_y_point = cpu_move_down(cpu_y_point);
			cpu_moving_right = false;
			cpu_moving_left = true; 

		} else if (cpu_x_point <= -0.9 && cpu_moving_left) {
			cpu_y_point = cpu_move_down(cpu_y_point);
			cpu_moving_right = true;
			cpu_moving_left = false;
		}

		if (cpu_y_point <= -0.9) {
			cpu_y_point = 0.9;
		}


		if ((cpu_x_point - 0.1 <= x_point && x_point <= cpu_x_point + 0.1)
			&& (cpu_y_point -0.1 <= y_point && y_point <= cpu_y_point +0.1)) { // collision detector

			break;
		}

		// generating location for food 
		

		if ((random_x - 0.1 <= x_point && x_point <= random_x + 0.1)
			&& (random_y -0.1 <= y_point && y_point <= random_y +0.1)) { // collision detector

			score += 1;
			PRINT("Current score: " << score);
			
			random_x = fRand(-1.0, 1.0);
			random_y = fRand(-1.0, 1.0);
		}

		window.clear();

		//user movements

		if (window.isKeyPressed(GLFW_KEY_A)) {
			// PRINT("A KEY has been pressed");

			if (-x_point <= 0.9) {
				x_point -= 0.03;
			}

			
		}
		else if (window.isKeyPressed(GLFW_KEY_S)) {
			// PRINT("S KEY has been pressed");
			if (-y_point <= 0.9) {
				y_point -= 0.03;
			}
			
		}
		else if (window.isKeyPressed(GLFW_KEY_W)) {
			// PRINT("W KEY has been pressed");
			if (y_point <= 0.9) {
				y_point += 0.03;
			}
			
		}
		else if (window.isKeyPressed(GLFW_KEY_D)) {
			// PRINT("D KEY has been pressed");
			if (x_point <= 0.9) {
				x_point += 0.03;
			}
		}

		glBegin(GL_QUADS);
			glColor3f(1.0f, 0.0f, 0.0f);

			glVertex2f(x_point - 0.08, y_point -0.08);
			glVertex2f(x_point + 0.08, y_point -0.08);
			glVertex2f(x_point + 0.08, y_point +0.08);
			glVertex2f(x_point - 0.08, y_point +0.08);

		glEnd();

		glBegin(GL_QUADS);
			glColor3f(1.0, 1.0, 1.0);

			glVertex2f(cpu_x_point - 0.1, cpu_y_point -0.1);
			glVertex2f(cpu_x_point + 0.1, cpu_y_point -0.1);
			glVertex2f(cpu_x_point + 0.1, cpu_y_point +0.1);
			glVertex2f(cpu_x_point - 0.1, cpu_y_point +0.1);

		glEnd();

		glBegin(GL_QUADS);
			glColor3f(0.7f, 0.5f, 0.2f);

			glVertex2f(random_x - 0.1, random_y -0.1);
			glVertex2f(random_x + 0.1, random_y -0.1);
			glVertex2f(random_x + 0.1, random_y +0.1);
			glVertex2f(random_x - 0.1, random_y +0.1);

		glEnd();

		

		glFlush();

		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			PRINT("pressed left!");
		}
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
			PRINT("pressed right!");
		}


		window.update();
	}

	glfwTerminate();

	return 0;
}
