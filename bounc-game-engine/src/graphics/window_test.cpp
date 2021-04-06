#include <iostream> 

#define GLEW_STATIC 
#include <GL/glew.h> 
#include <GLFW/glfw3.h> 

int main(void)
{
    
    if ( !glfwInit() ) {   
        std::cerr<<"GLFW init failed!"<<std::endl;
        return -1;
    }
 
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 ); 
    glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 3 ); 
    glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 
 
    GLFWwindow* window = glfwCreateWindow( 512, 512, "Hello OpenGL", nullptr, nullptr);
 
    if( window  == nullptr){
        std::cerr << "Failed to create GLFW window"<<std::endl;
        glfwTerminate();
 
        return -1;
    }
 
    glfwMakeContextCurrent( window );
 
    glewExperimental = GL_TRUE;
 
    if ( glewInit() != GLEW_OK ){
        std::cerr << "Failed to init GLEW "<<std::endl;
    }
 
    while ( !glfwWindowShouldClose( window ) ){
        glfwPollEvents();
 
        glClearColor( 0.23f, 0.38f, 0.47f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );
 
         
 
        glfwSwapBuffers( window );
    }
 
    glfwTerminate();
 
 
    return 0;
}