//
//  main.cpp
//  Chap1_1.2
//
//  Created by colin3dmax on 15/4/24.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include "OpenGL_Helper.h"


void display()
{
    //清除所有的像素
    glClear(GL_COLOR_BUFFER_BIT);
    //设置OpenGL颜色
    glColor3f(1.0, 1.0f, 1.0f);
    //设置多边形模型
//    glBegin(GL_POLYGON);
//    glVertex3f(0.25, 0.25, 0.0);
//    glVertex3f(0.75, 0.25, 0.0);
//    glVertex3f(0.75, 0.75, 0.0);
//    glVertex3f(0.25, 0.75, 0.0);
//    glEnd();
//    
    
    glutWireCube(3.0f);
    //强制OpenGL刷新
    glFlush();
}

int main(int argc, char ** argv) {
    runOpenGL(argc, argv);
    return 0;
}
