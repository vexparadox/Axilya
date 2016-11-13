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
    SDL_Window* window;
    BaseCore(){};
    BaseCore(BaseCore const&){};
    ResourceManager* resourceManager = ResourceManager::getInstance();
    PrefabManager* prefabManager = PrefabManager::getInstance();
public:
    int windowWidth= 0, windowHeight = 0;
    virtual ~BaseCore();
    virtual void draw(){};
    virtual void setup(){};
    virtual void update(){};
    virtual void exitCalled();
    SDL_Window* getWindow();
    void setWindow(SDL_Window*);
};

#endif /* BaseCore_hpp */
