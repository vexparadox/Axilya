/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This class describes an AnimatedSprite, it loops through textures at a set frame count.
 *
 */
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
   /*!
   * The destructor of an AnimatedSprite
   *
   * This will destruct the current class but will not delete the AXTexture's attached.
   */
    ~AnimatedSprite();
   /*!
   * The constructor of an AnimatedSprite
   * @param name the name of this AnimatedSprite
   * @param frameLength how many frames each AXTexture will be displayed for
   */
    AnimatedSprite(const std::string& name, int frameLength);
   /*!
   * A method to draw the AnimatedSprite
   * @param x the x position to draw the sprite
   * @param y the y position to draw the sprite
   * @param w the width to draw the sprite
   * @param h the height to draw the sprite
   */
    void draw(float x, float y, float w, float h);
   /*!
   * A method to add another frame to the AnimatedSprite
   * @param textureID the ID of a texture given by the ResourceManager
   */
    void addTexture(int textureID);
   /*!
   * A method to add another frame to the AnimatedSprite
   * @param filename the filename of an image to be loaded by the ResourceManager
   * @return the ID of the AXTexture loaded by the ResourceManager
   */
    int addTexture(const std::string& filename);
   /*!
   * A method to clone this Sprite
   * @return a clone of this AnimatedSprite
   */
    Sprite* clone();
};


#endif
