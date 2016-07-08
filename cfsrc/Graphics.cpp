//
//  Graphics.cpp
//  GLFW3
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

    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        glBegin(GL_TRIANGLES);
        glVertex3f(x1, y1, 0.f);
        glVertex3f(x2, y2, 0.f);
        glVertex3f(x3, y3, 0.f);
        glEnd();
    }

    //RECTANGLES
    void drawRect(float x, float y, float w, float h){
        glBegin(GL_QUADS);
        glVertex3f(x, y, 0.0f);
        //top left
        glVertex3f(x, y+h, 0.0f );
        //bottom left
        glVertex3f(x+w, y+h, 0.0f );
        //bottom right
        glVertex3f(x+w, y, 0.0f );
        //top right
        glEnd();
    }

    void drawRect(const Math::Vector2D &v, float w, float h){
        drawRect(v.x, v.y, w, h);
    }
    
    //POLYGONS
    void drawPoly(const Polygon &p){
        drawPoly(p.getVerticies());
    }
    
    void drawPoly(const std::vector<Math::Vector2D>& v){
        glBegin(GL_POLYGON);
        for(auto points : v){
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
        glBegin(GL_TRIANGLE_FAN);
    
        float degToRad = M_PI/180.0;
        
        for(int i = 0; i < 360; i++)
        {
            float rad = i*degToRad;
            glVertex3f(cos(rad)*xR+x, sin(rad)*yR+y, 0.0f);
        }
        glEnd();
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
    
    //MATRIXES
    void popMatrix(){
        glPopMatrix();
    }
    
    void pushMatrix(){
        glPushMatrix();
    }
    
    void translate(float &x, float &y, float &z){
        glTranslatef(x, y, z);
    }
    
    void translate(float &x, float &y){
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
        glColor4f(c.getR(), c.getG(), c.getB(), c.getA());
    }
    
    void fill(const float &rgb){
        glColor4f(rgb/255, rgb/255, rgb/255, 1);
    }
    
    void fill(const float &r, const float &g, const float &b, const float &a){
        glColor4f(r/255, g/255, b/255, a/255);
    }
    
    void fill(const float &r, const float &g, const float &b){
        glColor4f(r/255, g/255, b/255, 1);
    }
    
    void clearFill(){
        glColor4f(1, 1, 1, 0);
    }

}