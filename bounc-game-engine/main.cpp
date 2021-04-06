#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#include "src/graphics/window.h"

int main() {
	using namespace bounc;
	using namespace graphics; 

	Window window("bounc!", 800, 600);

	while (!window.closed()) {
		window.update();
	}

	system("PAUSE");
	return 0;




}