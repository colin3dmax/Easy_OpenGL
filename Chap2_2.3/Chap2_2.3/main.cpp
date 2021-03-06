//
//  main.cpp
//  Chap2_2.3
//
//  Created by colin on 15/4/25.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2");
    init();
    
    glutDisplayFunc([](){
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(1.0);
        
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 3.0f);
        glVertex2f(4.0f, 3.0f);
        glVertex2f(6.0f, 1.5f);
        glVertex2f(4.0f, 0.0f);
        
        glEnd();
        
        glFlush();
    
    init();
    
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-8.0,8.0, -5.0, 5.0, -1.0, 1.0);
    });
    
    glutDisplayFunc([](){
        glColor3f(0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        
        glColor3f(1.0, 0, 1.0);
        glBegin(GL_POLYGON);
        glEdgeFlag(GL_TRUE);
        glVertex3f(0, 0, 0);
        glEdgeFlag(GL_FALSE);
        glVertex3f(5, -6, 0);
        glEdgeFlag(GL_TRUE);
        glVertex3f(5,5, 0);
        glEnd();
        
        glFlush();
    
    });
    
    glutMainLoop();
    return 0;
}
