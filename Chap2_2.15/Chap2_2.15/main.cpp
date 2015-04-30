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

#define BUFFER_OFFSET(offset) ((GLvoid *)(NULL+offset))

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
    
    vertices = (GLfloat *)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    
    if (vertices == NULL) {
        fprintf(stderr, "Unable to map vertex buffer\n");
        exit(EXIT_FAILURE);
    }
    else{
        int i,j;
        GLfloat dx =  (XEnd - XStart) /(NumPoints -1);
        GLfloat dy = (YEnd - YStart)/(NumPoints -1);
        GLfloat *tmp = vertices;
        int n = 0;
        for (j=0; j<NumYPoints; ++j) {
            GLfloat y = YStart + j*dy;
            
            for (i=0; i<NumXPoints; ++i) {
                GLfloat x = XStart + i*dx;
                *tmp++=x;
                *tmp++=y;
            }
        }
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glVertexPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(0) );
        glEnableClientState(GL_VERTEX_ARRAY);
    }
    
    
    //建立数据索引
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    //分配一个额外的重启索引
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, NumSrips*(NumPointsPerStrip+1)*sizeof(GLushort), NULL, GL_STATIC_DRAW);
    indices = (GLushort *)glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY);
    if (indices==NULL) {
        fprintf(stderr, "Unable to map index buffer\n");
        exit(EXIT_FAILURE);
    }else{
        int i,j;
        GLushort *index = indices;
        for (j=0; j<NumSrips; ++j) {
            GLushort bottomRow = j*NumYPoints;
            GLushort topRow = bottomRow + NumYPoints;
            
            for (i=0; i<NumXPoints; ++i) {
                *index++ = topRow + i;
                *index++ = bottomRow + i;
            }
            *index++ = RestartIndex;
        }
        
        glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
        
    }
    
//    glPrimitiveRestartIndex(RestartIndex);
//    glEnable(GL_PRIMITIVE_RESTART);
    
}


int main(int argc,char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2_2.15");
    init();
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-300, 300, -300, 300, 1.0, -1.0);
    });
    glutDisplayFunc([](){
        int i,start;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glColor3f(1, 1, 1);
        glDrawElements(GL_TRIANGLE_STRIP, NumSrips*(NumPointsPerStrip+1), GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));
        
        glutSwapBuffers();
        

    });
    glutMainLoop();
    return 0;
}

