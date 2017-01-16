#ifndef BaseCore_hpp
#define BaseCore_hpp

#include <stdio.h>
#include "ResourceManager.hpp"
#include "PrefabManager.hpp"
#include <SDL2/SDL.h>
#include "glad/glad.h"
#include <iostream>
#include <stdlib.h>
#include "Graphics.hpp"

//this class is a virtual instance of the core
//it allows for the users to not implement methods but stil make use of GLFW method call backs on events
class Runner;
class BaseCore{
protected:
    BaseCore(){};
    BaseCore(BaseCore const&){};
    ResourceManager* resourceManager = ResourceManager::getInstance();
    PrefabManager* prefabManager = PrefabManager::getInstance();
public:
    virtual ~BaseCore();
    virtual void draw(){};
    virtual void setup(){};
    virtual void update(){};
    virtual void exitCalled();
    int windowWidth();
    int windowHeight();
    SDL_Window* getWindow();
};

#endif /* BaseCore_hpp */
