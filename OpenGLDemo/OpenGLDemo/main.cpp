//
//  main.cpp
//  OpenGLDemo
//
//  Created by colin on 15/4/24.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include "OpenGL_Helper.h"


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
    runOpenGL(argc, argv);
    return 0;
}
