//
//  main.cpp
//  Chap2_2.12
//
//  Created by colin on 15/4/26.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include <GL/freeglut.h>
//#pragma clang  diagnostic ignored "-Wdeprecated-declarations"
using namespace std;
void init()
{
    glClearColor(0.0,0.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
}


void glDrawLine(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2){
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

int main(int argc,char * argv[]) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutInitWindowSize(250, 250);
    
//    glutInitContextVersion(3,1);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    
    glutCreateWindow("Chap2_2.12");
    init();
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-300, 300, -300, 300, 100.0, -100.0);
    });
    glutDisplayFunc([](){
        glColor3f(1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        cout << glGetError() << endl;
        
        glPointSize(5.0);
        glColor3f(1.0, 0, 0);
        
//        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        
//        cout << glGetError() << endl;
//        
        //四个顶点
        GLfloat pfVer[] = {
            0.0f,		0.0f,	0.0f,
            100.0f,	0.0f,	0.0f,
            100.0f,	100.0f,	0.0f,
            0.0f,	100.0f,	0.0f };
        //两个面
        GLushort piInd[] = {
            0,1,2,
            2,3,0 };
        
        glVertexPointer( 3,GL_FLOAT, 0, pfVer );
        
        cout << glGetError() << endl;
        glDrawElements( GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,(GLvoid*)piInd );
        
//        cout << glGetError() << endl;
//        
        
        static GLint vertices[]={
            0,0,
            0,100,
            0,200,
            175,25,
            175,325,
            250,25,
            280,280
        };
        
        static GLfloat colors[]={
            1,0,0,
            0,1,0,
            0,1,1,
            0.75,0.75,0.75,
            0.35,0.35,0.35,
            0.5,0.5,0.5,
            0.5,0.5,1
        };
        
        
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        
        glColorPointer(3, GL_FLOAT, 0, colors);
        glVertexPointer(2, GL_INT, 0, vertices);
        
        
                glBegin(GL_POLYGON);
                int count =sizeof(vertices)/2/sizeof(GLint);
                for (int i=0; i<count; ++i) {
                    glArrayElement(i);
                }
                glEnd();
        
        
//        glDrawElements(GL_POINTS, 6, GL_INT, vertices);
        

        
        
        
//        glLineWidth(1);
//        
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//        glDrawLine(10, 10, 100, 200);
//        
//        
//        glRectd(10, 10, 100, 80);
        
        glFlush();
        
        glFinish();
        

    });
    
    glutMainLoop();
    return 0;
}

