//
// Created by William Meaton on 01/09/2016.
//

#include "StaticWorld.hpp"
#include "Runner.hpp"

StaticWorld::StaticWorld() {

}

void StaticWorld::loadTexture(int textureID) {
    if(resourceManager->getTexture(textureID)){
        texture = resourceManager->getTexture(textureID);
    }else{
        std::cout << "TextureID not found.";
    }
}

void StaticWorld::loadTexture(Texture *t) {
    if(t){
        texture = t;
    }
}

void StaticWorld::draw() {
    texture->getImage()->draw(0, 0, Runner::getWidth(), Runner::getHeight());
}

void StaticWorld::update() {

}