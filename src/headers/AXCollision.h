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
 * This file contains some common collision code.
 */

#ifndef Collision_h
#define Collision_h
#include <vector>
#include "Math.h"
#include "Types.h"

namespace Math {
    struct lineCollide{
        AXVector2D v1, v2;
        lineCollide(const AXVector2D &v1, const AXVector2D &v2);
    };

    AXVector2D lineCollisionCheckX(const AXVector2D &originalPosition, const AXVector2D &proposedMovement, const lineCollide &lc);
    
    AXVector2D lineCollisionCheckY(const AXVector2D &originalPosition, const AXVector2D &proposedMovement, const lineCollide &lc);

    /*!
    * A function that will return if the poing is inside the quad created by v1 and v2.
    *
    * @param point 
    * @param v1 the first point of the quad 
    * @param v2 the second point of the quad 
    * @return if the point is inside the quad created by v1 and v2
    */
    bool isInsideQuad(const AXVector2D &point, const AXVector2D &v1, const AXVector2D &v2);
    /*!
    * A function that will return if the point is inside the quad created by v and w,h.
    *
    * @param point the point to be checked 
    * @param v the position of the quad
    * @param w the width of the quad
    * @param h the height of the quad
    * @return if the point is inside the quad created by v and w,h
    */
    bool isInsideQuad(const AXVector2D &point, const AXVector2D &v, float w, float h);
    /*!
    * A function that will return if x1,y1 is inside the quad created by x2,y2 and x3,y3
    *
    * @param x1 the x position of the point
    * @param y1 the y position of the point
    * @param x2 the x position of the quad
    * @param y2 the y position of the quad
    * @param x3 the second x position of the quad
    * @param y3 the second y position of the quad
    * @return if x1,y1 is inside the quad created by x2,y2 and x3,y3
    */
    bool isInsideQuad(const float &x1, const float &y1, const float &x2, const float &y2, const float &x3, const float &y3);
    
    /*!
    * A function that will the area of a AXTriangle
    *
    * @param x1 the first x position of the triangle
    * @param y1 the first y position of the triangle
    * @param x2 the second x position of the triangle
    * @param y2 the second y position of the triangle
    * @param x3 the third x position of the triangle
    * @param y3 the third y position of the triangle
    * @return the area of the triangle given
    */
    float areaTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
    /*!
    * A function that will the area of a AXTriangle
    *
    * @param v1 the first vertex of the triangle
    * @param v2 the second vertex of the triangle
    * @param v3 the third vertex of the triangle
    * @return the area of the triangle given
    */
    float areaTriangle(const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3);
    /*!
    * A function that will the area of a AXTriangle
    *
    * @param t the triangle to be calculated
    * @return the area of the triangle given
    */
    float areaTriangle(const AXGraphics::AXTriangle &t);
    /*!
    * A function that will return if a point is inside of the AXTriangle given
    *
    * @param point the point to be checked
    * @param v1 the first vertex of the triangle
    * @param v2 the second vertex of the triangle
    * @param v3 the third vertex of the triangle
    * @return if the point is inside of the triangle
    */
    bool isInsideTriangle(const AXVector2D &point, const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3);
    /*!
    * A function that will return if a point is inside of the AXTriangle given
    *
    * @param point the point to be checked
    * @param t the triangle to be calculated
    * @return if the point is inside of the triangle
    */
    bool isInsideTriangle(const AXVector2D &point, const AXGraphics::AXTriangle &t);
    
    /*!
    * A function that will return if a point is inside of an AXEllipse
    *
    * @param point the point to be checked
    * @param cp the center point of the AXEllipse
    * @param xR the radius in the x direction
    * @param yR the radius in the y direction
    * @return if the point is inside of the ellipse
    */    
    bool isInsideEllipse(const AXVector2D &point, const AXVector2D &cp, float xR, float yR);
    /*!
    * A function that will return if a point is inside of an AXEllipse
    *
    * @param point the point to be checked
    * @param cp the center point of the ellipse
    * @param r the radius of the  ellpise
    * @return if the point is inside of the ellipse
    */  
    bool isInsideEllipse(const AXVector2D &point, const AXVector2D &cp, float r);
    /*!
    * A function that will return if a point is inside of an AXEllipse
    *
    * @param point the point to be checked
    * @param e the AXEllipse to be calculated
    * @return if the point is inside of the ellipse
    */ 
    bool isInsideEllipse(const AXVector2D &point, const AXGraphics::AXEllipse &e);
    
    /*!
    * A function that will return a distance between two vectors
    *
    * @param v1 the first vector
    * @param v2 the second vector
    * @return the distance between the two vectors
    */ 
    float vectorDistance(const AXVector2D& v1, const AXVector2D& v2);
    /*!
    * A function that will return a distance between two vectors
    *
    * @param x1 the x position of the first vector
    * @param y1 the y position of the first vector
    * @param x2 the x position of the second vector
    * @param y2 the y position of the second vector
    * @return the distance between the two vectors
    */ 
    float vectorDistance(float x1, float y1, float x2, float y2);
}

#endif /* Collision_h */
