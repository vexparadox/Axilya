//
// Created by William Meaton on 02/09/2016.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "../ResourceManager.hpp"
class Sprite {
    std::string name;
protected:
    ResourceManager* resourceManager = ResourceManager::getInstance();
public:
    Sprite(const std::string& name);
    virtual void draw(float x, float y) = 0;
    std::string getName();
};

#endif
