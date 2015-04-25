//
//  main.cpp
//  Chap2_2.3
//
//  Created by colin on 15/4/25.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

#pragma clang  diagnostic ignored "-Wdeprecated-declarations"


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(250, 250);
    glutCreateWindow("Chap2");
    
    
    glutDisplayFunc([](){
    
    
    });
    
    glutReshapeFunc([](int w,int h){
        
    });
    
    
    glutMainLoop();
    return 0;
}
