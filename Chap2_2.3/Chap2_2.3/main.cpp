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
    glColor3f(0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2");
    
    init();
    
    
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-10, 10, -10, 10, 1, -1);
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
