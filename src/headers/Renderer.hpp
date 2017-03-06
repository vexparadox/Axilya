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
    std::unordered_map<std::string, AXText*> texts;
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
    void setOwner(Entity* entity);
    void addSprite(Sprite* sprite);
    void setSprite(Sprite* sprite);
    void setSprite(const std::string& name);
    void addText(AXText* text);
    void setText(const std::string& name);
    void setText(AXText* text);
    Sprite* getCurrentSprite();
    AXGraphics::Colour& getColour();
    void setColour(float r, float g, float b, float a);
    void setColour(float r, float g, float b);
    void setColour(const AXGraphics::Colour&);
    int getDrawType();
    void setDrawType(int type);
    void draw(const Math::Vector2D& offset);
    Renderer* clone();
};

#endif
