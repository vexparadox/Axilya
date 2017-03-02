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

#include "Graphics.hpp"

#include <SDL2/SDL.h>
#include "EntityDrawTypes.hpp"
#include "Sprite.hpp"

class Entity;
class AXText;
class Renderer {
    std::unordered_map<std::string, Sprite*> sprites;
    Sprite* currentSprite = 0;
    AXText* currentText = 0;
    Entity* owner = 0;
    //set a colour to be used in place of a sprite
    AXGraphics::Colour colour;
    //default to drawing a rect
    int drawType = AX_DRAW_RECT;
public:
    Renderer();
    ~Renderer();
    void setOwner(Entity*);
    void addSprite(Sprite*);
    void setSprite(Sprite*);
    void setSprite(const std::string&);
    void addText(AXText*);
    Sprite* getCurrentSprite();
    AXGraphics::Colour& getColour();
    void setColour(float, float, float, float);
    void setColour(float, float, float);
    void setColour(const AXGraphics::Colour&);
    int getDrawType();
    void setDrawType(int type);
    void draw(const Math::Vector2D&);
    Renderer* clone();
};

#endif
