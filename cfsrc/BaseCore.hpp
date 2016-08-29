#include "../cfsrc/Input.hpp"
#ifndef BaseCore_hpp
#define BaseCore_hpp

#include <stdio.h>
#include "ResourceManager.hpp"
#include "SOIL/SOIL.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <stdlib.h>
#include "Client.hpp"
#include "Graphics.hpp"
//this class is a virtual instance of the core
//it allows for the users to not implement methods but stil make use of GLFW method call backs on events
class BaseCore{
protected:
    GLFWwindow* window;
    BaseCore(){};
    BaseCore(BaseCore const&){};
    ResourceManager* resourceManager = ResourceManager::getInstance();
public:
    int windowWidth= 0, windowHeight = 0;
    virtual ~BaseCore();
    virtual void draw(){};
    virtual void setup(){};
    virtual void update(){};
    virtual void exitCalled(){std::exit(0);};
    GLFWwindow*& getWindow();
};

#endif /* BaseCore_hpp */