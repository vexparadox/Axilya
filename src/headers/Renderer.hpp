//
// Created by William Meaton on 02/09/2016.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <unordered_map>
#include "Sprite.hpp"
#include "Graphics.hpp"
#include <SDL2/SDL.h>
#include "EntityDrawTypes.hpp"
class Entity;
class Renderer {
    std::unordered_map<std::string, Sprite*> sprites;
    Sprite* currentSprite = 0;
    Entity* owner = 0;
    //set a colour to be used in place of a sprite
    Graphics::Colour colour;
public:
    Renderer();
    ~Renderer();
    void setOwner(Entity*);
    void addSprite(Sprite*);
    void setSprite(Sprite*);
    void setSprite(const std::string&);
    Sprite* getCurrentSprite();
    Graphics::Colour& getColour();
    void setColour(float, float, float, float);
    void setColour(float, float, float);
    void setColour(const Graphics::Colour&);
    void draw(const Math::Vector2D&);
    Renderer* clone();
};

#endif
