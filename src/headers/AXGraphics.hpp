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

#include "AXTypes.h"
#include <SDL2/SDL.h>
#include <vector>
#include "AXMath.hpp"
#include "glad.h"
namespace AXGraphics{
    /*!
    * A function that draws an SDL_Texture
    *
    * Use this in conjunction with baked AXFonts or your own data
    * @param t the baked SDL_Texture
    * @param x the x position to draw the texture
    * @param y the y position to draw the texture
    * @param w the width to draw this texture
    * @param h the height to draw this texture
    */
    void drawSDLTexture(SDL_Texture* t, float x, float y, float w, float h);
    /*!
    * A function that draws an AXTexture
    * @param t the loaded AXTexture
    */
    void drawTexture(AXTexture* t, float x, float y);
    /*!
    * A function that draws an AXTexture
    * @param t the loaded AXTexture
    * @param v the position to draw the texture
    */
    void drawTexture(AXTexture* t, AXVector2D v);
    /*!
    * A function that draws an AXTexture
    * @param t the loaded AXTexture
    * @param v the position to draw the texture
    * @param w the width to draw the texture
    * @param h the height to draw the texture
    */
    void drawTexture(AXTexture* t, AXVector2D v, float w, float h);
    /*!
    * A function that draws an AXTexture
    * @param t the loaded AXTexture
    * @param x the x position to draw the texture
    * @param y the y position to draw the texture
    * @param w the width to draw the texture (-1 will default to texture size)
    * @param h the height to draw the texture (-1 will default to texture size)
    */
    void drawTexture(AXTexture* t, float x, float y, float w, float h);



    /*!
    * A function that draws a AXTriangle
    * @param t the AXTriangle to be drawn
    */
    void drawTriangle(const AXTriangle &t);
    /*!
    * A function that draws a triangle
    * @param v1 the first vertex of the triangle
    * @param v2 the second vertex of the triangle
    * @param v3 the third vertex of the triangle
    */
    void drawTriangle(const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3);
    /*!
    * A function that draws a AXTriangle
    * @param x1 the x position of the first vertex of the triangle
    * @param y1 the y position of the first vertex of the triangle
    * @param x2 the x position of the second vertex of the triangle
    * @param y2 the y position of the second vertex of the triangle
    * @param x3 the x position of the third vertex of the triangle
    * @param y3 the y position of the third vertex of the triangle
    */
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
    /*!
    * A function that draws a AXRect
    * @param r the AXRect to draw
    */
    void drawRect(const AXRect &r);
    /*!
    * A function that draws a rectangle
    * @param v1 the position of the rectangle
    * @param w the width of the rectangle
    * @param h the height of the rectangle
    */
    void drawRect(const AXVector2D &v1, float w, float h);
    /*!
    * A function that draws a AXRect
    * @param x the x position of the rectangle
    * @param y the y position of the rectangle
    * @param w the width of the rectangle
    * @param h the height of the recatangle
    */
    void drawRect(float x, float y, float w, float h);
    /*!
    * A function that draws a rectangle from the center outwards
    * @param x the x center position of the rectangle
    * @param y the y center position of the rectangle
    * @param w the width of the rectangle
    * @param h the height of the recatangle
    */
    void drawRectCenter(float x, float y, float w, float h);
    
    /*!
    * A function that colours a single pixel
    * @param v the position of the pixel
    */
    void drawPoint(const AXVector2D &v);

    /*!
    * A function that draws a line between two points
    * @param x1 the x position of the first point
    * @param y1 the y position of the first point
    * @param x2 the x position of the second point
    * @param y2 the y position of the second point
    * @param width Not currently used
    */
    void drawLine(float x1, float y1, float x2, float y2, float width);
    /*!
    * A function that draws a line between two points
    * @param x1 the x position of the first point
    * @param y1 the y position of the first point
    * @param x2 the x position of the second point
    * @param y2 the y position of the second point
    */
    void drawLine(float x1, float y1, float x2, float y2);
    /*!
    * A function that draws a line between two points
    * @param v1 the first point
    * @param v2 the second point
    * @param width Not currently used
    */
    void drawLine(const AXVector2D& v1, const AXVector2D& v2, float width);
    /*!
    * A function that draws a line between two points
    * @param v1 the first point
    * @param v2 the second point
    */
    void drawLine(const AXVector2D& v1, const AXVector2D& v2);
    /*!
    * A function that draws a AXPolygon (not tested)
    * @param p the polygon to draw
    */
    void drawPoly(const AXPolygon &p);
    /*!
    * A function that draws a polygon
    * @param v an array of points that'll be drawn
    */
    void drawPoly(const std::vector<AXVector2D>& v);

    /*!
    * A function that draws an AXEllipse
    * @param e the AXEllipse to draw
    */
    void drawEllipse(AXEllipse &e);
    /*!
    * A function that draws an ellipse
    * @param v the position of the ellipse
    * @param xR the radius in the x direction
    * @param yR the radius in the y direction
    */
    void drawEllipse(const AXVector2D &v, float xR, float yR);
    /*!
    * A function that draws an ellipse
    * @param v the position of the ellipse
    * @param r the radius 
    */
    void drawEllipse(const AXVector2D &v, float r);
    /*!
    * A function that draws an ellipse
    * @param x the x position of the of the ellipse
    * @param y the y position of the of the ellipse
    * @param xR the radius in the x direction
    * @param yR the radius in the y direction
    */
    void drawEllipse(float x, float y, float xR, float yR);
    /*!
    * A function that draws an ellipse
    * @param x the x position of the ellipse
    * @param y the y position of the ellipse
    * @param r the radius in the x direction
    */
    void drawEllipse(float x, float y, float r);
    /*!
    * A function that draws an ellipse
    * @param x the x position of the center point of the ellipse
    * @param y the y position of the center point of the ellipse
    * @param xR the radius in the x direction
    * @param yR the radius in the y direction
    */
    void drawEllipseCenter(float x, float y, float xR, float yR);
    /*!
    * A function that draws an ellipse
    * @param x the x position of the center point of the ellipse
    * @param y the y position of the center point of the ellipse
    * @param r the radius of the ellipse
    */
    void drawEllipseCenter(float x, float y, float r);
    /*!
    * A function that draws an ellipse
    * @param cp the center point of the ellipse
    * @param r the radius of the ellipse
    */
    void drawEllipseCenter(const AXVector2D &cp, float r);
        
    /*!
    * A function that sets the background colour
    *
    * AXColour values are clamped 0-255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    * @param a the alpha value
    */    
    void setBackground(float r, float g, float b, float a);
    /*!
    * A function that sets the background colour
    *
    * AXColour values are clamped 0-255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    */
    void setBackground(float r, float g, float b);
    /*!
    * A function that sets the background colour
    * 
    * AXColour values are clamped 0-255
    * @param rgba all colour values are set to this
    */
    void setBackground(float rgba);
    /*!
    * A function that sets the background AXColour
    * 
    * @param c the AXColour object that the background is set
    */
    void setBackground(const AXColour &c);
    
    /*!
    * A function that sets the fill AXColour
    * 
    * @param c the AXColour object that the fill is set to
    */
    void fill(const AXColour &c);

    /*!
    * A function that sets the fill AXColour
    * 
    * AXColour values are clamped 0-255
    * @param rgba all the colour values are set to this
    */
    void fill(const float &rgb);
    /*!
    * A function that sets the fill AXColour
    * 
    * AXColour values are clamped 0-255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    * @param a the alpha value
    */
    void fill(const float &r, const float &g, const float &b, const float &a);

    /*!
    * A function that sets the fill AXColour
    * 
    * AXColour values are clamped 0-255
    * @param r the red value
    * @param g the green value
    * @param b the blue value
    */
    void fill(const float &r, const float &g, const float &b);
    /*!
    * A function that clears the fill colour
    */
    void clearFill();
}


#endif /* AXGraphics_hpp */
