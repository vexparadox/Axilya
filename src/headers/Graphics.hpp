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
 * This is a collection of base graphics functions, these can be called in the draw portion of the game loop.
 */

#ifndef AXGraphics_hpp
#define AXGraphics_hpp

#include "Types.h"
#include <SDL2/SDL.h>
#include <vector>
#include "Math.h"
#include "glad.h"
namespace AXGraphics{
    //Triangles
    void drawTriangle(const Triangle &t);
    void drawTriangle(const Math::Vector2D &v1, const Math::Vector2D &v2, const Math::Vector2D &v3);
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
    //Rectangles
    void drawRect(const Rect &r);
    void drawRect(const Math::Vector2D &v1, float w, float h);
    void drawRect(float x, float y, float w, float h);
    void drawRectCenter(float x, float y, float w, float h);

    void drawPoint(const Math::Vector2D &v);

    void drawLine(float x, float y, float x2, float y2, float width);
    void drawLine(float x, float y, float x2, float y2);
    void drawLine(const Math::Vector2D& v1, const Math::Vector2D& v2, float width);
    void drawLine(const Math::Vector2D& v1, const Math::Vector2D& v2);

    //Polygons
    void drawPoly(const Polygon &p);
    void drawPoly(const std::vector<Math::Vector2D>& v);
    //Ellipses
    void drawEllipse(Ellipse &e);
    void drawEllipse(const Math::Vector2D &cp, float xR, float yR);
    void drawEllipse(const Math::Vector2D &cp, float r);
    void drawEllipse(float x, float y, float xR, float yR);
    void drawEllipse(float x, float y, float r);
    void drawEllipseCenter(float x, float y, float xR, float yR);
    void drawEllipseCenter(float x, float y, float r);
    void drawEllipseCenter(const Math::Vector2D &cp, float r);
        
    //set the background to be flushed
    void setBackground(float r, float g, float b, float a);
    void setBackground(float r, float g, float b);
    void setBackground(float rgba);
    void setBackground(const Colour &c);
    
    //colours
    void fill(const AXGraphics::Colour &c);
    void fill(const float &rgb);
    void fill(const float &r, const float &g, const float &b, const float &a);
    void fill(const float &r, const float &g, const float &b);
    void clearFill();
}


#endif /* AXGraphics_hpp */
