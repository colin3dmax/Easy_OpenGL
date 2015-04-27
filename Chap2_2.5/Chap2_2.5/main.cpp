//
//  main.cpp
//  Chap2_2.5
//
//  Created by colin3dmax on 15/4/25.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"
/**
 * 绘制直线，矩形API封装
 */

using namespace std;
void init(){
    glColor3f(0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawLine(float x1,float y1,float x2,float y2){
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawRect(float x1,float y1,float x2,float y2){
    drawLine(x1, y1, x1, y2);
    drawLine(x1, y2, x2, y2);
    drawLine(x2, y2, x2, y1);
    drawLine(x2, y1, x1, y1);
    
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutCreateWindow(argv[1]);
    init();
    glutReshapeFunc([](int w,int h){
        
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, -1.0f);
    });
    
    glutDisplayFunc([](){
        glColor3f(0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //设置点划线
        glLineStipple(1, 0x3F07);
        glEnable(GL_LINE_STIPPLE);
        //绘制图形
        glColor3f(1.0f, 1.0f, 0);
        drawLine(0,0,5,5);
        drawLine(0,5,5,0);
        drawRect(0,0,-5,-5);
        
        glColor3f(0.0f, 0.0f, 1.0f);
        //绘制多边形
        glBegin(GL_POLYGON);
        glEnable(GL_POLYGON_MODE);
        glFrontFace(GL_CW);
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_LINE);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 5.0f);
        glVertex2f(-5.0f, 5.0f);
        glVertex2f(-5.0f, 0.0f);
        
        glEnd();
        
        
        
        glFlush();
    });
    
    glutMainLoop();
    
    return 0;
}
