//
// Created by William Meaton on 02/09/2016.
//

#include "StaticSprite.hpp"

StaticSprite::StaticSprite(const std::string& name) : Sprite(name){
}

void StaticSprite::draw(float x, float y) {
    if(texture){
        texture->getImage()->draw(x, y);
    }

}

void StaticSprite::setTexture(int textureID) {
    texture = resourceManager->getTexture(textureID);
}