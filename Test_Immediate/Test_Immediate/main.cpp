//
//  main.cpp
//  Test_Immediate
//
//  Created by colin3dmax on 15/4/29.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void display(){
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0 , 0);
    glVertex3f(-1, -1, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0, 1, 0);
    glColor3f(0, 0, 1);
    glVertex3f(1, -1, 0);
    glEnd();

}


int main(int argc,char * argv[]) {
	GLFWwindow* window;
    
    if (!glfwInit()) {
        return (EXIT_FAILURE);
    }
    int width = 250;
    int height = 250;
    window = glfwCreateWindow(width, height, "Test_Immediate", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return (EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
//        glfwGetFramebufferSize(window, &width, &height);
//        glViewport(0, 0, width, height);
        glOrtho(-1, 1, -1, 1, 1, -1);
        
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;

}

