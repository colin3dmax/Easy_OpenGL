//
//  main.cpp
//  Chap2_2.15
//
//  Created by colin on 15/4/27.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

#define BUFFER_OFFSET(offset)((GLvoid *)NULL+offset)

#define XStart -0.8
#define XEnd 0.8
#define YStart -0.8
#define YEnd 0.8
#define NumYPoints 11
#define NumXPoints 11
#define NumPoints (NumXPoints*NumYPoints)
#define NumPointsPerStrip   (2*NumXPoints)
#define NumSrips    (NumYPoints-1)
#define RestartIndex 0xffff

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    GLuint vbo,ebo;
    GLfloat *vertices;
    GLushort *indices;
    
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 2*NumPoints*sizeof(GLfloat), NULL, GL_STATIC_DRAW );
    
    
}


int main(int argc,char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2_2.15");
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

