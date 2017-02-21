//
// Created by William Meaton on 01/09/2016.
//

#ifndef StaticWorld_hpp
#define StaticWorld_hpp

#include "ResourceManager.hpp"
#include "World.hpp"

class StaticWorld : public World {
    AXTexture* texture;
    ResourceManager* resourceManager = ResourceManager::getInstance();
public:
    StaticWorld();
    void loadTexture(int textureID);
    void loadTexture(AXTexture* t);
    void draw();
    void update();
};


#endif //Axilya_STATICWORLD_HPP
