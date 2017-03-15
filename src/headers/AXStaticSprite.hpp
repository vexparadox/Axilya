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
 * This class describes a AXStaticSprite, it holds and draws a single texture.
 */
#ifndef AXStaticSprite_hpp
#define AXStaticSprite_hpp

#include "AXSprite.hpp"
class AXStaticSprite : public AXSprite{
    AXTexture* texture = 0;
public:
    /*!
    * The constructor of a AXStaticSprite
    *
    * @param name the name of this AXStaticSprite
    */
    AXStaticSprite(const std::string& name);
    /*!
    * The constructor of a AXStaticSprite
    *
    * @param name the name of this AXStaticSprite
    * @param filename the image file to load for this AXStaticSprite (will go through the AXResourceManager)
    */
    AXStaticSprite(const std::string& name, const std::string& filename);
    /*!
    * The deconstructor of a AXStaticSprite
    *
    * This won't release resources used by this AXStaticSprite
    */
    ~AXStaticSprite();
    /*!
    * A method to draw this AXStaticSprite, this is called by the AXRenderer
    *
    * @param x the x position to draw this AXStaticSprite 
    * @param y the y position to draw this AXStaticSprite
    * @param w the width to draw this AXStaticSprite
    * @param h the height to draw this AXStaticSprite
    */
    void draw(float x, float y, float w, float h);
    /*!
    * A method to set the AXTexture this AXStaticSprite will draw
    *
    * @param textureID the ID of the AXTexture given by the AXResourceManager
    */
    void setTexture(int textureID);
    /*!
    * A method to get the AXTexture this AXStaticSprite is drawing
    *
    * @return the AXTexture this AXStaticSprite is drawing
    */
    AXTexture* getTexture();
    /*!
    * A method to clone this AXSprite
    *
    * @return a clone of this AXStaticSprite
    */
    AXSprite* clone();
};


#endif
