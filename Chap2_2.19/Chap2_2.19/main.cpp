//
//  main.cpp
//  Chap2_2.19
//
//  Created by colin on 15/5/5.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

#define X .525731112119133606
#define z .85065080835

static GLfloat vdata[12][3] ={
    {-X,0.0,z},{X,0.0,z},{-X,0.0,-z},{X,0.0,-z},
    {0.0,z,X},{0.0,z,-X},{0.0,-z,X},{0.0,-z,-X},
    {z,X,0.0},{-z,X,0.0},{z,-X,0.0},{-z,-X,0.0}
};

static GLuint tindices [20][3]={
    {1,4,0},{4,9,0},{4,5,9},{8,5,4},{1,8,4},
    {1,10,8},{10,3,8},{8,3,5},
};

void init()
{
    glColor3f(1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc,char * argv[]) {
	glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2_2.19");
    init();
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-300, 300, -300, 300, 1.0, -1.0);
    });
    glutDisplayFunc([](){
    	//to do ...

    });
    glutMainLoop();
    return 0;
}

