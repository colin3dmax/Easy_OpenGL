//
//  main.cpp
//  Chap2_2.0
//
//  Created by colin3dmax on 15/4/24.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_FLAT);
}

int main(int argc,char * argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(250, 250);
    glutCreateWindow("Test");
    init();
    
    //显示函数C++11 Lambda表达式
    glutDisplayFunc([](){
        //清除所有像素
        glClear(GL_COLOR_BUFFER_BIT);
        //保存当前矩阵信息
        glPushMatrix();
        glRotatef(0.0, 0.0, 0.0, 1.0);
        
        glColor3f(1.0, 1.0, 1.0);
        glRectf(-25.0, -25.0, 25.0, 25.0);
        //恢复之前矩阵信息
        glPopMatrix();
        //强制刷新
        glFlush();
    });

    glutReshapeFunc([](int w,int h){
        //设置显示视口
        glViewport(0, 0, w, h);
        //设置矩阵模式为 多边形模式
        glMatrixMode(GL_PROJECTION);
        //重置单位矩阵
        glLoadIdentity();
        //设置正投影空间
        glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    });
    

    glutMainLoop();
    return 0;
}



