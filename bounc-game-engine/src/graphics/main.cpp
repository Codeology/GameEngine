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


	if ( glewInit() != GLEW_OK ){
        std::cout << "Failed to init GLEW "<<std::endl;
    }

	while (!window.closed()) {
		if (window.isKeyPressed(GLFW_KEY_A)) {
			PRINT("Pressed A!");
		}
		if (window.isKeyPressed(GLFW_KEY_S)) {
			PRINT("Pressed S!");
		}
		if (window.isKeyPressed(GLFW_KEY_W)) {
			PRINT("Pressed W!");
		}
		if (window.isKeyPressed(GLFW_KEY_D)) {
			PRINT("Pressed D!");
		}


		window.update();
	}

	glfwTerminate();

	return 0;
}
