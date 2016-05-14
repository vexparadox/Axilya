//
//  BaseCore.hpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef BaseCore_hpp
#define BaseCore_hpp

#include <stdio.h>
#include "SOIL/SOIL.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <stdlib.h>
#include "Graphics.hpp"

//this class is a virtual instance of the core
//it allows for the users to not implement methods but stil make use of GLFW method call backs on events
class BaseCore{
protected:
    GLFWwindow* window;
    BaseCore(){};
    BaseCore(BaseCore const&){};
    //Needs assignemnet made private
public:
    int mouseX = 0, mouseY = 0;
    int windowWidth= 0, windowHeight = 0;
    bool keyIsPressed = false;
    bool mouseIsPressed = false;
    int mouseButton = -1;
    int keyCode = 0;
    virtual ~BaseCore(){};
    virtual void draw(){};
    virtual void setup(){};
    virtual void update(){};
    virtual void keyPressed(int key){};
    virtual void keyReleased(int key){};
    virtual void mousePressed(int button){};
    virtual void mouseReleased(int button){};
    virtual void exitCalled(){};
    GLFWwindow*& getWindow();
};

#endif /* BaseCore_hpp */