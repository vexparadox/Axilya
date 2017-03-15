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
 * This is a pre-built component that handles the drawing of Entities, it's attached by default.
 */
#ifndef Renderer_hpp
#define Renderer_hpp

#include <unordered_map>
#include <SDL2/SDL.h>
#include "EntityDrawTypes.hpp"
#include "AXSprite.hpp"
#include "AXComponent.hpp"
class AXEntity;
class AXText;
class AXRenderer : public AXComponent{
    std::unordered_map<std::string, AXSprite*> sprites;
    std::unordered_map<std::string, AXText*> texts;
    AXSprite* currentSprite = 0;
    AXText* currentText = 0;
    AXEntity* owner = 0;
    //set a colour to be used in place of a sprite
    AXGraphics::AXColour colour;
    //default to drawing a rect
    int drawType = AX_DRAW_RECT;
public:
   /*!
   * The constructor of a AXRenderer
   * 
   * This is called when an AXEntity is created
   */
    AXRenderer();
   /*!
   * The deconstructor of a AXRenderer
   * 
   * This will delete all the Sprites and AXText stored in this AXRenderer, it won't delete resources
   */
    ~AXRenderer();
   /*!
   * A method to set which AXEntity owns this AXRenderer
   * 
   * @param entity The AXEntity that owns this AXRenderer
   */
    void setOwner(AXEntity* entity);
   /*!
   * A method to add a new AXSprite
   * 
   * This AXSprite will be set to the current one to be drawn and added to the list, you can use this AXSprite's name in setSprite()
   *
   * This method will also set the draw type
   * @param sprite the new sprite
   */
    void addSprite(AXSprite* sprite);
   /*!
   * A method to set the current AXSprite
   * 
   * The AXSprite must be first added with addSprite()
   * @param name the name of the AXSprite to set
   */
    void setSprite(const std::string& name);
   /*!
   * A method to add a new AXText
   * 
   * This AXText will be set to the current one to be drawn and added to the list, you can use this AXText's name in setText()
   *
   * This method will also set the draw type
   * @param text the next AXText
   */
    void addText(AXText* text);
   /*!
   * A method to set the current AXText
   * 
   * The AXText must be first added with addText()
   * @param name the name of the AXText to set
   */
    void setText(const std::string& name);
   /*!
   * A method to get the current AXSprite
   * 
   * @return the current AXSprite
   */
    AXSprite* getCurrentSprite();
   /*!
   * A method to get the AXColour of this AXRenderer
   * 
   * Note that colours only take place when drawing basic shapes, AXText and AXSprite's have their own AXColour methods
   * @return the current AXColour of this AXRenderer
   */
    AXGraphics::AXColour& getColour();
   /*!
   * A method to set the AXColour of this AXRenderer
   * 
   * Note that colours only take place when drawing basic shapes, AXText and AXSprite's have their own AXColour methods
   *
   * AXColour values are clamped (0-255)
   * @param r the red value of this AXColour
   * @param g the green value of this AXColour
   * @param b the blue value of this AXColour
   * @param a the alpha value of this AXColour
   */
    void setColour(float r, float g, float b, float a);
   /*!
   * A method to set the AXColour of this AXRenderer
   * 
   * Note that colours only take place when drawing basic shapes, AXText and AXSprite's have their own AXColour methods
   *
   * AXColour values are clamped (0-255)
   * @param r the red value of this AXColour
   * @param g the green value of this AXColour
   * @param b the blue value of this AXColour
   *
   * The alpha value will default to 255
   */
    void setColour(float r, float g, float b);
   /*!
   * A method to set the AXColour of this AXRenderer
   * 
   * Note that colours only take place when drawing basic shapes, AXText and AXSprite's have their own AXColour methods
   * @param c the AXColour object to set this AXRenderer to
   */
    void setColour(const AXGraphics::AXColour& c);
   /*!
   * A method to get the DrawType of this AXRenderer
   * 
   * @return the DrawType of this AXRenderer (AX_DRAW_RECT/AX_DRAW_ELLIPSE/AX_DRAW_TEXT/AX_DRAW_SPRITE/AX_DRAW_NONE)
   */
    int getDrawType();
   /*!
   * A method to set the DrawType of this AXRenderer
   * 
   * @param type the DrawType of this AXRenderer (AX_DRAW_RECT/AX_DRAW_ELLIPSE/AX_DRAW_TEXT/AX_DRAW_SPRITE/AX_DRAW_NONE)
   */
    void setDrawType(int type);
   /*!
   * A method to draw this AXRenderer
   * 
   * This method is called by the AXEntity and AXScene class, don't call it yourself
   * @param offset the offset to draw by
   */
    void draw(const AXVector2D& offset);
   /*!
   * A method to clone this AXRenderer
   * 
   * @return a clone of this AXRenderer
   */
    AXRenderer* clone();
};

#endif
