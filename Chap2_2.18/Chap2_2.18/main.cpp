//
//  main.cpp
//  Chap2_2.18
//
//  Created by colin on 15/5/3.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include <GL/freeglut.h>
#include <math.h>
#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

#define BUFFER_OFFSET(offset) ((GLvoid*)(NULL+offset))
#define NumberOf(array) (sizeof(array)/sizeof(array[0]))

typedef struct{
    GLfloat x,y,z;
} vec3;

typedef struct{
    vec3 xlate;
    GLfloat angle;
    vec3 axis;
} XForm;

enum {Cube,Cone,NumVAOs};

GLuint VAO[NumVAOs];
GLenum PrimType[NumVAOs];
GLsizei NumElements[NumVAOs];
XForm xform[NumVAOs] ={
    {{-2.0,0.0,0.0},0.0,{0.0,1.0,0.0}},
    {{0.0,0.0,2.0},0.0,{1.0,0.0,0.0}}
};

GLfloat Angle = 0.0;



void init()
{
    enum { Vertices,Colors,Elements,NumVBOs };
    GLuint buffers[NumVBOs];
    glGenVertexArrays(NumVAOs, VAO);
    {
        GLfloat cubeVerts[][3]={
                        {-1.0 ,-1.0,-1.0},
                        {-1.0 ,-1.0,1.0},
                        {-1.0 ,1.0,-1.0},
                        {-1.0 ,1.0,1.0},
                        {1.0 ,-1.0,-1.0},
                        {1.0 ,-1.0,1.0},
                        {1.0 ,1.0,-1.0},
                        {1.0 ,1.0,1.0}
        };
        GLfloat cubeColors [][3] ={
            {0.0,0.0,0.0},
            {0.0,0.0,1.0},
            {0.0,1.0,0.0},
            {0.0,1.0,1.0},
            {1.0,0.0,0.0},
            {1.0,0.0,1.0},
            {1.0,1.0,0.0},
            {1.0,1.0,1.0}
        };
        GLubyte cubeIndices[]={
            0,1,3,2,
            4,6,7,5,
            2,3,7,6,
            0,4,5,1,
            0,2,6,4,
            1,5,7,3
        };
        
        glBindVertexArray(VAO[Cube]);
        glGenBuffers(NumVBOs, buffers);
        glBindBuffer(GL_ARRAY_BUFFER, buffers[Vertices]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVerts), cubeVerts, GL_STATIC_DRAW);
        glVertexPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glBindBuffer(GL_ARRAY_BUFFER, buffers[Colors]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeColors), cubeColors, GL_STATIC_DRAW);
        glColorPointer(3, GL_FLOAT, 0, BUFFER_OFFSET(0));
        glEnableClientState(GL_COLOR_ARRAY);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[Elements]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndices), cubeIndices, GL_STATIC_DRAW);
        
        PrimType[Cube] = GL_QUADS;
        NumElements[Cube] = NumberOf(cubeIndices);
        
    }
    
    {
        int i,idx;
        float dTheta;
#define  NumConePoints 36
        GLfloat coneVerts[NumConePoints+1][3] ={
            {0.0,0.0,1.0}
        };
        
        GLfloat coneColors[NumConePoints+1][3]={
            {1.0,1.0,1.0}
        };
        GLubyte coneIndices[NumConePoints+1];
        dTheta = 2*M_PI/(NumConePoints -1 );
        idx = 1;
        for (i=0; i<NumConePoints; ++i,++idx) {
            float theta = i*dTheta;
            coneVerts[idx][0] = cos(theda);
            coneVerts[idx][1] = sin(theda);
            
        }
    }
    
    
}


int main(int argc,char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutInitContextVersion(3,1);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2_2.18");
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

