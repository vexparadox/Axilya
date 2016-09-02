//
// Created by William Meaton on 02/09/2016.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "../ResourceManager.hpp"
class Sprite {
    ResourceManager* resourceManager = ResourceManager::getInstance();
    std::string name;
public:
    Sprite(const std::string& name);
    virtual void draw() = 0;
    std::string getName();
};

#endif
