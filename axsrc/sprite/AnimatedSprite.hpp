//
// Created by William Meaton on 02/09/2016.
//

#ifndef AnimatedSprite_hpp
#define AnimatedSprite_hpp

#include "Sprite.hpp"
class AnimatedSprite : Sprite {
    //the amount of frames per image
    int frameLength;
    std::vector<Texture*> textures;
    //current frame we're on
    int frameCount = 0;
    //the current texture being drawn
    int texturePosition =0;
public:
    AnimatedSprite(const std::string& name, int frameLength);
    void draw(float x, float y, float w, float h);
    void addTexture(int textureID);
    int addTexture(const std::string& filename);
    Sprite* clone();
};


#endif
