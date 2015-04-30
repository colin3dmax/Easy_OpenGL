//
//  main.cpp
//  TriangleBuffer
//
//  Created by colin3dmax on 15/4/30.
//  Copyright (c) 2015年 colin3dmax. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "OpenGLApp.h"
using namespace cross3d;

class MyApp:public App{
public:
    MyApp(const string &title, int width, int height):App(title,width,height){}
    void onDraw(){
        App::onDraw();
        cout << "onDraw" << endl;
    }
    
};


int main(int argc,char * argv[]) {

    MyApp app("Hello",250,250);
    app.start();
    
    return 0;
}

