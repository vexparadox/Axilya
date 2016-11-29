//
//  Graphics.cpp
//  Axilya
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
//Ellipse work by Charlie Ringer
//

#include "Graphics.hpp"
#include "Runner.hpp"
namespace Graphics{
    //TRIANGLES
    void drawTriangle(Triangle& t){
        drawTriangle(t.getV1(), t.getV2(), t.getV3());
    }

    void drawTriangle(const Math::Vector2D &v1, const Math::Vector2D &v2, const Math::Vector2D &v3){
        drawTriangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
    }

    void drawPoint(const Math::Vector2D &v){
        SDL_RenderDrawPoint(Runner::renderer, v.x, v.y);
    }

    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLES);
        glVertex3f(x1, y1, 0.f);
        glVertex3f(x2, y2, 0.f);
        glVertex3f(x3, y3, 0.f);
        glEnd();
    }

    //lines
    void drawLine(float x, float y, float x2, float y2, float width){
        SDL_RenderDrawLine(Runner::renderer, x, y, x2, y2);
    }
    void drawLine(float x, float y, float x2, float y2){
        drawLine(x, y, x2, y2, 0);
    }

    void drawLine(const Math::Vector2D& v1, const Math::Vector2D& v2, float width){
        drawLine(v1.x, v1.y, v2.x, v2.y, width);
    }

    void drawLine(const Math::Vector2D& v1, const Math::Vector2D& v2){
        drawLine(v1.x, v1.y, v2.x, v2.y, 0);
    }

    //RECTANGLES
    void drawRect(float x, float y, float w, float h){
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        SDL_RenderFillRect(Runner::renderer, &rect);
    }

    void drawRectCenter(float x, float y, float w, float h){
        drawRect(x-w/2, y-h/2, w, h);
    }

    void drawRect(const Math::Vector2D &v, float w, float h){
        drawRect(v.x, v.y, w, h);
    }
    
    //POLYGONS
    void drawPoly(const Polygon &p){
        drawPoly(p.getVerticies());
    }
    
    void drawPoly(const std::vector<Math::Vector2D>& v){
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_POLYGON);
        for(auto& points : v){
            glVertex3f(points.x, points.y, 0.0f);
        }
        glEnd();
    }
    
    //ELLIPSES
    void drawEllipse(Ellipse &e){
        drawEllipse(e.getPosition().x, e.getPosition().y, e.getSize().x, e.getSize().y);
    }
    
    void drawEllipse(const Math::Vector2D &cp, float xR, float yR){
        drawEllipse(cp.x, cp.y, xR, yR);
    }
    
    void drawEllipse(const Math::Vector2D &cp, float r){
        drawEllipse(cp.x, cp.y, r, r);
    }
    
    void drawEllipse(float x, float y, float r){
        drawEllipse(x, y, r, r);
    }
    
    void drawEllipse(float x, float y, float xR, float yR){
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_TRIANGLE_FAN);
        // xR /= 2;
        // yR /= 2;
        float degToRad = M_PI/180.0;
        for(int i = 0; i < 360; i++)
        {
            float rad = i*degToRad;
            glVertex3f(cos(rad)*xR+x, sin(rad)*yR+y, 0.0f);
        }
        glEnd();
    }

    void drawEllipseCenter(float x, float y, float xR, float yR){
        drawEllipse(x-xR/2, y-yR/2, xR, yR);
    }

    void drawEllipseCenter(float x, float y, float r){
        drawEllipse(x-r/2, y-r/2, r, r);
    }

    void drawEllipseCenter(const Math::Vector2D &cp, float r){
        drawEllipse(cp.x-r/2, cp.y-r/2, r, r);
    }


    
    std::vector<unsigned char> getScreenData(int x, int y, int w, int h){
        std::vector<unsigned char> data(4*w*h);
        glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);
        return data;
    }
    
    //BACKGROUNDS
    void setBackground(float r, float g, float b, float a){
        Runner::r = r/255;
        Runner::g = g/255;
        Runner::b = b/255;
        Runner::a = a/255;
    }
    
    void setBackground(float r, float g, float b){
        setBackground(r, g, b, 0);
    }
    
    void setBackground(const Colour &c){
        setBackground(c.getR(), c.getG(), c.getB(), c.getA());
    }

    void setBackground(float rgba){
        setBackground(rgba, rgba, rgba, rgba);
    }
    
    //MATRIXES
    void popMatrix(){
        glPopMatrix();
    }
    
    void pushMatrix(){
        glPushMatrix();
    }
    
    void translate(float x, float y, float z){
        glTranslatef(x, y, z);
    }
    
    void translate(float x, float y){
        glTranslatef(x, y, 0);
    }
    
    void translate(const Math::Vector2D &v){
        glTranslatef(v.x, v.y, 0);
    }
    
    void translate(const Math::Vector3D &v){
        glTranslatef(v.x, v.y, v.z);
    }
    
    
    //FILLS
    void fill(const Graphics::Colour &c){
        SDL_SetRenderDrawColor(Runner::renderer, c.getR(), c.getG(), c.getB(), c.getA());
    }
    
    void fill(const float &rgb){
        SDL_SetRenderDrawColor(Runner::renderer, rgb, rgb, rgb, 255);
    }
    
    void fill(const float &r, const float &g, const float &b, const float &a){
        SDL_SetRenderDrawColor(Runner::renderer, r, g, b, a);
    }
    
    void fill(const float &r, const float &g, const float &b){
        SDL_SetRenderDrawColor(Runner::renderer, r, g, b, 255);
    }
    
    void clearFill(){
        SDL_SetRenderDrawColor(Runner::renderer, 255, 255, 255, 255);
    }

}