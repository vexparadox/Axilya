//
// Created by William Meaton on 02/09/2016.
//

#include "Renderer.hpp"
#include "Entity.hpp"
Renderer::~Renderer(){
    for(auto it = sprites.begin(); it != sprites.end(); it++){
       delete it->second;
    }
}

void Renderer::addSprite(Sprite *s) {
    if(s) {
        sprites.insert(std::pair<std::string, Sprite *>(s->getName(), s));
        currentSprite = s;
    }
}

void Renderer::setSprite(const std::string &name) {
    if(sprites.find(name) != sprites.end()){
        this->currentSprite = sprites.at(name);
    }
}

void Renderer::setSprite(Sprite *s) {
    if(s){
        this->currentSprite = s;
    }
}

void Renderer::draw() {
    if(currentSprite){
        //make sure the colour is transparent
        Graphics::fill(255,255,255,255);
        currentSprite->draw(owner->getTransform()->getPos().x, owner->getTransform()->getPos().y, owner->getTransform()->getSize().x, owner->getTransform()->getSize().y);
    }else{
        if(owner->getDrawType() == AX_DRAW_RECT){
            Graphics::fill(colour);
            Graphics::drawRect(owner->getTransform()->getPos(), owner->getTransform()->getSize().x, owner->getTransform()->getSize().y);
        }else if(owner->getDrawType() == AX_DRAW_ELLIPSE){
            Graphics::fill(colour);
            Graphics::drawEllipse(owner->getTransform()->getPos().x+owner->getTransform()->getSize().x/2, 
                owner->getTransform()->getPos().y+owner->getTransform()->getSize().y/2
                , owner->getTransform()->getSize().x/2, owner->getTransform()->getSize().y/2);
        }
    }
}

void Renderer::setOwner(Entity *owner) {
    if(owner){
        this->owner = owner;
    }
}

Graphics::Colour& Renderer::getColour() {
    return colour;
}

void Renderer::setColour(float r, float g, float b, float a){
    this->colour.set(r, g, b, a);
}

void Renderer::setColour(float r, float g, float b){
    this->colour.set(r, g, b, 255);
}

void Renderer::setColour(const Graphics::Colour& c){
    this->colour.set(c.getR(), c.getG(), c.getB(), c.getA());
}

Renderer* Renderer::clone(){
    Renderer* a = new Renderer();
    for(auto it = sprites.begin(); it != sprites.end(); it++){
        a->addSprite(it->second->clone());
    }
    a->currentSprite = this->currentSprite;
    a->colour = this->colour;
    return a;
}