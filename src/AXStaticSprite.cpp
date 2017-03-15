//
// Created by William Meaton on 02/09/2016.
//

#include "headers/AXStaticSprite.hpp"

AXStaticSprite::~AXStaticSprite(){
	
}

AXStaticSprite::AXStaticSprite() : texture(0){
}

AXStaticSprite::AXStaticSprite(const std::string &filename) : texture(0){
    this->setTexture(resourceManager->addTexture(filename));
}

void AXStaticSprite::draw(float x, float y, float w, float h) {
    if(texture){
    	AXGraphics::drawTexture(texture, x, y, w, h);
    }

}

AXTexture* AXStaticSprite::getTexture(){
	return texture;
}

void AXStaticSprite::setTexture(int textureID) {
    texture = resourceManager->getTexture(textureID);
}

AXSprite* AXStaticSprite::clone(){
	AXStaticSprite* ss = new AXStaticSprite();
	ss->texture = this->texture;
	return ss;
}
