//
//  main.cpp
//  Chap2_2.9
//
//  Created by colin on 15/4/25.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <string>
#pragma clang  diagnostic ignored "-Wdeprecated-declarations"
using namespace std;
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    
    glutCreateWindow("Chap2.2.9");
    
    init();
    
    
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glOrtho(-300, 300, -300, 300, 1.0, -1.0);
        
    });

    static GLushort vertices[]={
       100,100,
        0,0,
        100,28,
        100,50,
        100,100,
        15,4,
        30,0
    };
    

    
    glutDisplayFunc([](){
        glClear(GL_COLOR_BUFFER_BIT);
        
        glColor3f(1, 1, 0);
    
        
               static GLfloat colors[]={
            1.0,1.0,0.0,
            0.0,0.0,0.0,
            0.0,1.0,1.0,
            0.75,0.75,0.75,
            0.35,0.35,0.35,
            0.5,0.5,0.5,
            1.0,0.0,0.0
        };
        
        
       
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        
        glPointSize(4);
        
        //1.指定数组数据
        glVertexPointer(2, GL_SHORT, 0, vertices);
        glColorPointer(3, GL_FLOAT, 0, colors);
        
        //2.解引用单个数组元素
        int count =sizeof(vertices)/2/sizeof(GLushort);
//        glBegin(GL_POINTS);
//        for (int i=0; i<count; ++i) {
//            glArrayElement(i);
//        }
//        glEnd();
        
        //2.解引用数组元素的一个列表
        int ele_count =sizeof(vertices)/sizeof(vertices[0]);
        glDrawElements(GL_POINTS, ele_count, GL_UNSIGNED_SHORT, (GLvoid*)vertices);
        
        cout << glGetError() << endl;
        
        //Stride跨距
//        static GLfloat intertwined[]={
//            1.0,0.2,1.0,100.0,100.0,0.0,
//            1.0,0.2,0.2,0.0,200.0,0.0,
//            1.0,1.0,0.2,100.0,300.0,0.0,
//            0.2,1.0,0.2,200.0,300.0,0.0,
//            0.2,1.0,1.0,300.0,200.0,0.0,
//            0.2,0.2,1.0,200.0,100.0,0.0
//        };
//        
//        glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &intertwined[0]);
//        glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &intertwined[3]);
        
        
        glFlush();
        
    });
    
    glutMainLoop();
    return 0;
}
