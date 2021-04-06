#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

#define PRINT(x) std::cout << x << std::endl


int main() {
	if (!glfwInit())
		PRINT("Failed to init");
	else 
		PRINT("Success!");

	system("PAUSE");

	return 0;

}