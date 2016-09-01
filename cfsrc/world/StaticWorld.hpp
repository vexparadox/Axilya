//
// Created by William Meaton on 01/09/2016.
//

#ifndef StaticWorld_hpp
#define StaticWorld_hpp

#include "cfsrc/ResourceManager.hpp"
#include "World.hpp"

class StaticWorld : public World {
    Texture* texture = 0;
    ResourceManager* resourceManager = ResourceManager::getInstance();
public:
    StaticWorld();
    void loadTexture(int textureID);
    void loadTexture(Texture* t);
    void draw();
    void update();
};


#endif //CLOSEDFRAMEWORKS_STATICWORLD_HPP
