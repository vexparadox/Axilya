//
//  Graphics.hpp
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Graphics_hpp
#define Graphics_hpp

#include "Types.h"
#include <SDL2/SDL.h>
#include <vector>
#include "Math.h"
#include "glad/glad.h"
namespace Graphics{
    //Triangles
    void drawTriangle(const Triangle &t);
    void drawTriangle(const Math::Vector2D &v1, const Math::Vector2D &v2, const Math::Vector2D &v3);
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
    //Rectangles
    void drawRect(const Rect &r);
    void drawRect(const Math::Vector2D &v1, float w, float h);
    void drawRect(float x, float y, float w, float h);
    void drawRectCenter(float x, float y, float w, float h);

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
    
    //gets the pixel data between two points, (x,y) and (w,h)
    std::vector<unsigned char> getScreenData(int x, int y, int w, int h);
    
    //set the background to be flushed
    void setBackground(float r, float g, float b, float a);
    void setBackground(float r, float g, float b);
    void setBackground(float rgba);
    void setBackground(const Colour &c);
    
    //push and pop a new matrix
    void pushMatrix();
    void popMatrix();
    
    //translate the current pushed matrix
    void translate(float x, float y, float z);
    void translate(float x, float y);
    void translate(const Math::Vector2D& v);
    void translate(const Math::Vector3D& v);

    //colours
    void fill(const Graphics::Colour &c);
    void fill(const float &rgb);
    void fill(const float &r, const float &g, const float &b, const float &a);
    void fill(const float &r, const float &g, const float &b);
    void clearFill();
}


#endif /* Graphics_hpp */
