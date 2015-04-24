//
//  main.cpp
//  OpenGLDemo
//
//  Created by colin on 15/4/24.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0f, 0.0f, 1.0, -1.0, 1.0);
    
}

void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    
    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
