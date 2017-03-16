//
// Created by William Meaton on 02/09/2016.
//

#include "headers/AXRenderer.hpp"
#include "headers/AXEntity.hpp"
#include "headers/AXText.hpp"


AXRenderer::AXRenderer(){
     this->colour = AXColour(0, 0, 0, 255);
     currentSprite = sprites.end();
     currentText = texts.end();
}

AXRenderer::~AXRenderer(){
    for(auto it = sprites.begin(); it != sprites.end(); it++){
       delete it->second;
    }
    for(auto it = texts.begin(); it != texts.end(); it++){
       delete it->second;
    }
}

void AXRenderer::addSprite(AXSprite *s, const std::string& name) {
    if(s) {
        auto temp = sprites.insert(std::pair<std::string, AXSprite *>(name, s));
        if(temp.second){
            currentSprite = temp.first;
        }
        this->setDrawType(AX_DRAW_SPRITE);
    }
}

void AXRenderer::addText(AXText* text, const std::string& name){
    if(text){
        text->setOwner(owner);
        text->bakeText();
        this->setDrawType(AX_DRAW_TEXT);
        auto temp = this->texts.insert(std::pair<std::string, AXText*>(name, text));
        if(temp.second){
            currentText = temp.first;
        }
    }
}

void AXRenderer::setText(const std::string& name){
    std::unordered_map<std::string, AXText*>::iterator x = texts.find(name);
    if(x != texts.end()){
        this->currentText = x;
        this->setDrawType(AX_DRAW_TEXT);
    }
}

void AXRenderer::setSprite(const std::string &name) {
    std::unordered_map<std::string, AXSprite*>::iterator x = sprites.find(name);
    if(x != sprites.end()){
        this->currentSprite = x;
        this->setDrawType(AX_DRAW_SPRITE);
    }
}

int AXRenderer::getDrawType(){
    return drawType;
}

void AXRenderer::setDrawType(int type){
    this->drawType = type;
}

AXSprite* AXRenderer::getCurrentSprite(){
    return currentSprite->second;
}

void AXRenderer::draw(const AXVector2D& renderOffset) {
    AXVector2D position = owner->getTransform()->getPosition()+renderOffset;
    AXVector2D size = owner->getTransform()->getSize();
    //if there's a sprite
    int drawType = owner->getDrawType();
    if(drawType == AX_DRAW_SPRITE && currentSprite->second){
        //make sure the colour is transparent
        AXGraphics::fill(255,255,255, 0);
        currentSprite->second->draw(position.x, position.y, size.x, size.y);
    }else if(drawType == AX_DRAW_TEXT && currentText->second){
        //if there's a text
        currentText->second->draw(position.x, position.y);
    }else{
        //if it's set to shapes
        AXGraphics::fill(colour);
        if(drawType == AX_DRAW_RECT){
            AXGraphics::drawRect(position.x, position.y, size.x, size.y);
        }else if(drawType == AX_DRAW_ELLIPSE){
            AXGraphics::drawEllipse(position.x+size.x/2, position.y+size.y/2, size.x/2, size.y/2);
        }
    }
}

void AXRenderer::setOwner(AXEntity *owner) {
    if(owner){
        this->owner = owner;
    }
}

AXColour& AXRenderer::getColour() {
    return colour;
}

void AXRenderer::setColour(float r, float g, float b, float a){
    this->colour.set(r, g, b, a);
}

void AXRenderer::setColour(float r, float g, float b){
    this->colour.set(r, g, b, 255);
}

void AXRenderer::setColour(const AXColour& c){
    this->colour.set(c.getR(), c.getG(), c.getB(), c.getA());
}

AXRenderer* AXRenderer::clone(){
    AXRenderer* a = new AXRenderer();
    a->setDrawType(this->drawType);
    for(auto it = sprites.begin(); it != sprites.end(); it++){
        //for each sprite, make a clone of the sprite and give it the same name
        a->addSprite(it->second->clone(), it->first);
    }
    for(auto it = texts.begin(); it != texts.end(); it++){
        //for each text, make a clone of the sprite and give it the same name
        a->addText(it->second->clone(), it->first);
    }
    if(this->currentSprite != sprites.end()){
        a->setSprite(currentSprite->first);
    }
    if(this->currentText != texts.end()){
        a->setText(currentText->first);
    }
    a->colour = this->colour;
    return a;
}
