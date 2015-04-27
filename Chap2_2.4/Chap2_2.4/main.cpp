//
//  main.cpp
//  Chap2_2.4
//
//  Created by colin3dmax on 15/4/25.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>
#include <string>
using namespace std;

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"

#define PI 3.14159265355898
GLint circle_points = 10;

void drawCircle(float r){
    double angle=0.0f;
    glBegin(GL_LINE_LOOP);
    for (int i=0; i<circle_points; i++) {
        angle = 2*PI*i/circle_points;
        glVertex2f(cos(angle)*r, sin(angle)*r );
    }
    glEnd();
}


int main(int argc,char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutCreateWindow(argv[0]);
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glOrtho(-10, 10, -10, 10, 1.0, -1.0);
    });
    
    glutDisplayFunc([](){
        glColor3f(0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glColor3f(1.0f, 1.0f, 0.0f);
        drawCircle(8);
        glColor3f(1.0f, 0.0f, 1.0f);
        drawCircle(6);
        glColor3f(0.0f, 1.0f, 1.0f);
        drawCircle(3);
        glFlush();
    });
    
    glutMouseFunc([](int button,int status,int x,int y){
        
        printf("button:%d,status:%d,(%d,%d)\n",button,status,x,y);
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (status==GLUT_DOWN) {
                    cout << "Left Mouse Down" << endl;
                    circle_points++;
                }
                break;
            case GLUT_RIGHT_BUTTON:
                if (status==GLUT_DOWN) {
                    circle_points--;
                }
                
            default:
                break;
        }
        if (circle_points>200 || circle_points<0) {
            circle_points=0;
        }
    
        string title="Edge:"+to_string(circle_points);
        glutSetWindowTitle(title.c_str());
        glutPostRedisplay();
        
    });
    
    glutMainLoop();
    
    
    return 0;
}
