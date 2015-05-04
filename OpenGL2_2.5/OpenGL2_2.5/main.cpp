//
//  main.cpp
//  OpenGL2_2.5
//
//  Created by colin on 15/5/2.
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
    glutCreateWindow("OpenGL2_2.5");
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

