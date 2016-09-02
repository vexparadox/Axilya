//
// Created by William Meaton on 02/09/2016.
//

#ifndef StaticSprite_hpp
#define StaticSprite_hpp

#include "Sprite.hpp"
class StaticSprite : public Sprite{
    Texture* texture = 0;
public:
    StaticSprite(const std::string& name);
    void draw(float x, float y);
    void setTexture(int textureID);
};


#endif
