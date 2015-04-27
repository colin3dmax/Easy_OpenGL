//
//  main.cpp
//  Chap2_2.13
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
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc,char * argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2_2.13");
    init();
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-300, 300, -300, 300, 1.0, -1.0);
    });
    glutDisplayFunc([](){
        glColor4f(0, 0, 0, 0);
        
        static GLubyte oneIndices[]={
            0,1,2,3,4,5,6
        };
        static GLubyte twoIndices[]={
            7,1,8,9,10,11
        };
        
        glDrawElements(GL_LINE_STRIP, 7, GL_UNSIGNED_BYTE, oneIndices);
        glDrawElements(GL_LINE_STRIP, 6, GL_UNSIGNED_BYTE, twoIndices);
        
        
        glFlush();

    });
    glutMainLoop();
    return 0;
}

