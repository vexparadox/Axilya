//
// Created by William Meaton on 02/09/2016.
//

#ifndef AnimatedSprite_hpp
#define AnimatedSprite_hpp

#include "Sprite.hpp"
class AnimatedSprite : Sprite {
    int framesPerSecond;
public:
    AnimatedSprite(const std::string& name, int framesPerSecond);
    void draw(float x, float y, float w, float h);
};


#endif
