//
// Created by William Meaton on 02/09/2016.
//

#include "StaticSprite.hpp"



StaticSprite::~StaticSprite(){
	
}

StaticSprite::StaticSprite(const std::string& name) : Sprite(name){
}

StaticSprite::StaticSprite(const std::string &name, const std::string &filename) : Sprite(name){
    this->setTexture(resourceManager->addTexture(filename));
}

void StaticSprite::draw(float x, float y, float w, float h) {
    if(texture){
        texture->getImage()->draw(x, y, w, h);
    }

}

void StaticSprite::setTexture(int textureID) {
    texture = resourceManager->getTexture(textureID);
}

Sprite* StaticSprite::clone(){
	StaticSprite* ss = new StaticSprite(this->getName());
	ss->texture = this->texture;
	return ss;
}