//
//  main.cpp
//  Chap1_1.3
//
//  Created by colin3dmax on 15/4/24.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

//双缓冲OpenGL

static GLfloat spin = 0.0;

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    //清除所有像素
    glClear(GL_COLOR_BUFFER_BIT);
    //保存当前矩阵信息
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    //恢复之前矩阵信息
    glPopMatrix();
    //交换Buffer
    glutSwapBuffers();
}

void spinDisplay(void)
{
    spin +=2.0;
    if (spin>360.0) {
        spin -=360.0;
    }
    //发送重绘显示区域
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glutIdleFunc(spinDisplay);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state==GLUT_DOWN) {
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}

void reshape(int w,int h)
{
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
}


int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    
    return 0;
}
