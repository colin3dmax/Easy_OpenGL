//
//  main.cpp
//  Chap2_2_11
//
//  Created by colin on 15/4/26.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#pragma clang  diagnostic ignored "-Wdeprecated-declarations"
void init()
{
    glColor3f(1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc,char * argv[]) {
	glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2_2_11");
    init();
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-300, 300, -300, 300, 300.0, -300.0);
    });
    glutDisplayFunc([](){
        
        glColor3f(1, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //八个顶点
        GLfloat pfVer[] = {
            -100,100,100,
            100,-100,100,
            100,100,-100,
            -100,-100,100,
            100,-100,-100,
            -100,100,-100,
            -100,-100,-100,
            100,100,100
        };
        glVertexPointer( 3,GL_FLOAT, 0, pfVer );
        
        
        GLfloat colorVer[] = {
            0.0,0.0,1.0,
            0.0,1.0,0.0,
            1.0,0.0,0.0,
            0.0,0.0,1.0,
            0.0,1.0,0.0,
            1.0,0.0,0.0,
        };

        glColorPointer( 3,GL_FLOAT, 0, colorVer );
        
    	//to do ...
        static GLubyte frontIndices[]={4,5,6,7};
        static GLubyte rightIndices[]={1,2,6,5};
        static GLubyte bottomIndices[]={0,1,5,4};
        static GLubyte backIndices[]={0,3,2,1};
        static GLubyte leftIndices[]={0,4,7,3};
        static GLubyte topIndices[]={2,3,7,6};
        
//        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, frontIndices);
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, rightIndices);
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, bottomIndices);
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, backIndices);
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, leftIndices);
        glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, topIndices);
        
        
        
        
        
        glFlush();

    });
    glutMainLoop();
    return 0;
}

