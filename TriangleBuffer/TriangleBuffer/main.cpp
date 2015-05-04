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
#include <vector>
using namespace cross3d;


#ifndef GLSL
#define GLSL(version,A) "#version " #version "\n" #A
#endif

#ifndef GENVERTEXARRAYS
#define GENVERTEXARRAYS(n,id) \
    if(GLEW_APPLE_vertex_array_object) \
        glGenVertexArraysAPPLE(1,id); \
    else if(GLEW_ARB_vertex_array_object) \
        glGenVertexArrays(n,id)
#endif

#ifndef BINDVERTEXARRAY
#define BINDVERTEXARRAY(id) \
    if(GLEW_APPLE_vertex_array_object) glBindVertexArrayAPPLE(id); \
    else if(GLEW_ARB_vertex_array_object) glBindVertexArray(id)
#endif


const char * vert = GLSL(120,
    attribute vec4 position;
    void main(){
        gl_position = position;
    }
);

const char * frag=GLSL(120,
    void main(){
        gl_FragColor = vec4(1.0,0.0,0.0,1.0);
    }
);

void shaderCompilerCheck(GLuint ID){
    GLint comp;
    glGetShaderiv(ID,GL_COMPILE_STATUS,&comp);
    
    if (comp==GL_FALSE) {
        cout << "Shader Compilation FAILED" << endl;
        GLchar messages[256];
        glGetShaderInfoLog(ID,sizeof(messages),0,&messages[0]);
        cout << messages;
    }
}

void shaderLinkCheck(GLuint ID){
    GLint linkStatus,validateStatus;
    glGetProgramiv(ID,GL_LINK_STATUS,&linkStatus);
    if (linkStatus == GL_FALSE) {
        cout << "Shader Linking FAILED" << endl;
        GLchar messages[256];
        glGetProgramInfoLog(ID,sizeof(messages),0,&messages[0]);
        cout << messages;
    }
}

struct vec2{
    vec2(float _x=0,float _y=0):x(_x),y(_y){}
    float x,y;
};







class MyApp:public App{
public:
    MyApp(const string &title, int width, int height):App(title,width,height){
        init();
    }
    
    void init(){
        triangle.push_back(vec2(-1,-.5) );
        triangle.push_back(vec2(0,1) );
        triangle.push_back(vec2(1,-.5) );
        
        GLuint vID = glCreateShader(GL_VERTEX_SHADER);
        GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);
        
        //1.创建Shader
        sID = glCreateProgram();
        
        //2.加载代码
        glShaderSource(vID,1 ,&vert,NULL);
        glShaderSource(fID,1,&frag,NULL);
        //3.编译
        glCompileShader(vID);
        glCompileShader(fID);
        //4.检查编译错误
        shaderCompilerCheck(vID);
        shaderCompilerCheck(fID);
        //5.附加Shaders到程序
        glAttachShader(sID,vID);
        glAttachShader(sID,fID);
        //6.Link Program
        glLinkProgram(sID);
        //7.检查链接错误
        shaderLinkCheck(sID);
        //8.使用Program
        glUseProgram(sID);
        //获取locations
        positionID = glGetAttribLocation(sID,"position");
        //9.Unbind Program
        glUseProgram(0);
        
        GENVERTEXARRAYS(1, &arrayID);
        BINDVERTEXARRAY(arrayID);
        
        glGenBuffers(1,&bufferID);
        glBindBuffer(GL_ARRAY_BUFFER,bufferID);
        glBufferData(GL_ARRAY_BUFFER,triangle.size()*sizeof(vec2),triangle.data(),GL_STATIC_DRAW);
        
        glEnableVertexAttribArray(positionID);
        
        glVertexAttribPointer(positionID,2,GL_FLOAT,GL_FALSE,sizeof(vec2),0);
        
        BINDVERTEXARRAY(0);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        
        
        
        
    }
    void onDraw(){
        App::onDraw();
        cout << "onDraw" << endl;
        glUseProgram(sID);
        BINDVERTEXARRAY(arrayID);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        BINDVERTEXARRAY(0);
        glUseProgram(0);
    }
private:
    vector<vec2> triangle;
    GLuint sID;
    GLuint positionID;
    GLuint bufferID;
    GLuint arrayID;
    
    
    
};


int main(int argc,char * argv[]) {

    MyApp app("Hello",250,250);
    app.start();
    
    return 0;
}

