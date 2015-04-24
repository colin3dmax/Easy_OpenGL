//
//  OpenGL_Helper.cpp
//  Chap1_1.2
//
//  Created by colin3dmax on 15/4/24.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include "OpenGL_Helper.h"

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0f, 0.0f, 1.0, -1.0, 1.0);
    
}


void runOpenGL(int argc, char ** argv){
    //初始化GLUT
    glutInit(&argc, argv);
    //设置色彩模式——RGBA模式或者颜色索引模式
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello");
    init();
    //显示回调函数
    glutDisplayFunc(display);
    
    glutMainLoop();
    
}