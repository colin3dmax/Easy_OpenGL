//
//  main.cpp
//  Test_ImmediateTriangles
//
//  Created by colin3dmax on 15/4/29.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

int width =250;
int height=250;
int draw_count = 1000;

void drawTriangle(){
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0 , 0);
    glVertex3f(-1, -1, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0, 1, 0);
    glColor3f(0, 0, 1);
    glVertex3f(1, -1, 0);
    glEnd();
}

void draw()
{
    static float counter = 0.0;
    counter +=.01;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, 1, -1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    for (int i=0; i<draw_count; ++i) {
        float t =(float)i/draw_count;
        
        glPushMatrix();
        glTranslatef(t*sin(counter), 0, 0);
        glRotatef(360*t*counter, 0, 0, 1);
        glScalef(1-t,1-t, 1-t);
        drawTriangle();
        glPopMatrix();
    }
    
}


int main(int argc,char * argv[]) {
	GLFWwindow* window;
    
    if (!glfwInit()) {
        return (EXIT_FAILURE);
    }
    window = glfwCreateWindow(width, height, "Test_ImmediateTriangles", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return (EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        
        glClearColor(0.0,0.0, 1.0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;

}

