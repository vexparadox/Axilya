//
// Created by William Meaton on 02/09/2016.
//

#ifndef Animator_hpp
#define Animator_hpp

#include <unordered_map>
#include "sprite/Sprite.hpp"
#include "Graphics.hpp"
class Entity;
class Animator {
    std::unordered_map<std::string, Sprite*> sprites;
    Sprite* currentSprite = 0;
    Entity* owner = 0;
    //set a colour to be used in place of a sprite
    Graphics::Colour colour = Graphics::Colour(0, 0, 0, 255);
public:
    void setOwner(Entity* owner);
    void addSprite(Sprite* s);
    void setSprite(Sprite* s);
    void setSprite(const std::string& name);
    Graphics::Colour& getColour();
    void draw();
    Animator* clone();
};


#endif
