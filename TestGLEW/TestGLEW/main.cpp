//
//  main.cpp
//  TestGLEW
//
//  Created by colin3dmax on 15/4/29.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma clang  diagnostic ignored "-Wdeprecated-declarations"
void init()
{
    glClearColor(0.0,0.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}
void display(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc,char * argv[]) {
	GLFWwindow* window;
    
    if (!glfwInit()) {
        return (EXIT_FAILURE);
    }
    window = glfwCreateWindow(250, 250, "TestGLEW", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return (EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        display();
        
        glfwSwapBuffers(window);
        
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;

}

