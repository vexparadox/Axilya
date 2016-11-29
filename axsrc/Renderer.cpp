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

Sprite* Renderer::getCurrentSprite(){
    return currentSprite;
}

void Renderer::draw(const Math::Vector2D& renderOffset) {
    Math::Vector2D position = owner->getTransform()->getPos()+renderOffset;
    Math::Vector2D size = owner->getTransform()->getSize();
    if(currentSprite){
        //make sure the colour is transparent
        Graphics::fill(255,255,255, 0);
        currentSprite->draw(position.x, position.y, size.x, size.y);
    }else{
        Graphics::fill(colour);
        if(owner->getDrawType() == AX_DRAW_RECT){
            Graphics::drawRect(position.x, position.y, size.x, size.y);
        }else if(owner->getDrawType() == AX_DRAW_ELLIPSE){
            Graphics::drawEllipse(position.x+size.x/2, position.y+size.y/2, size.x/2, size.y/2);
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