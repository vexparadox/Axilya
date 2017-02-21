//
// Created by William Meaton on 02/09/2016.
//

#ifndef AnimatedSprite_hpp
#define AnimatedSprite_hpp

#include "Sprite.hpp"
class AnimatedSprite : public Sprite {
    //the amount of frames per image
    int frameLength;
    std::vector<AXTexture*> textures;
    //current frame we're on
    int frameCount;
    //the current texture being drawn
    int texturePosition;
public:
    ~AnimatedSprite();
    AnimatedSprite(const std::string& name, int frameLength);
    void draw(float x, float y, float w, float h);
    void addTexture(int textureID);
    int addTexture(const std::string& filename);
    Sprite* clone();
};


#endif
