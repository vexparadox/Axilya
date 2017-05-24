//
//  AXGraphics.cpp
//  Axilya
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
//AXEllipse work by Charlie Ringer
//

#include "headers/AXGraphics.hpp"
#include "headers/AXWindow.hpp"
#include "headers/SDL2_gfxPrimitives.h"
namespace AXGraphics{
    //Textures
    void drawSDLTexture(SDL_Texture* t, float x, float y, float w, float h){
        SDL_Rect dest = {.x = (int)x, .y = (int)y, .w = (int)w, .h = (int)h};
        if(SDL_RenderCopy(AXWindow::renderer, t, NULL, &dest) != 0){
            AXLog::log("SDL Render copy failed", SDL_GetError(), AX_LOG_ERROR);
        }
    }

    void drawTexture(AXTexture* t, float x, float y){
        drawTexture(t, x, y, -1, -1);
    }

    void drawTexture(AXTexture* t, AXVector2D v){
        drawTexture(t, v.x, v.y, -1, -1);
    }
    void drawTexture(AXTexture* t, AXVector2D v, float w, float h){
        drawTexture(t, v.x, v.y, w, h);
    }

    void drawTexture(AXTexture* t, float x, float y, float w, float h){
        if(!t){
            AXLog::log("Texture data invalid", "Nullptr was passed", AX_LOG_ERROR);
            return;
        }
        if(!t->isLoaded()){
            AXLog::log("Texture failed to draw", "AXTexture isn't loaded", AX_LOG_ERROR);
            return;
        }
        if(w == -1){
            w = t->getWidth();
        }
        if(h == -1){
            h = t->getHeight();
        }
        SDL_Rect dest = {.x = (int)x, .y = (int)y, .w = (int)w, .h = (int)h};
        if(SDL_RenderCopy(AXWindow::renderer, t->getTextureData(), NULL, &dest) != 0){
            AXLog::log("SDL Render copy failed", SDL_GetError(), AX_LOG_ERROR);
        }
    }
    //TRIANGLES
    void drawTriangle(AXTriangle& t){
        drawTriangle(t.getV1(), t.getV2(), t.getV3());
    }

    void drawTriangle(const AXVector2D &v1, const AXVector2D &v2, const AXVector2D &v3){
        drawTriangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y);
    }

    void drawPoint(const AXVector2D &v){
        SDL_RenderDrawPoint(AXWindow::renderer, v.x, v.y);
    }

    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3){
        filledTrigonRGBA(AXWindow::renderer, x1, y1, x2, y2, x3, y3,
            AXWindow::renderColour.getR(),
            AXWindow::renderColour.getG(),
            AXWindow::renderColour.getB(),
            AXWindow::renderColour.getA());
    }

    //lines
    void drawLine(float x, float y, float x2, float y2, float width){
        SDL_RenderDrawLine(AXWindow::renderer, x, y, x2, y2);
    }
    void drawLine(float x, float y, float x2, float y2){
        drawLine(x, y, x2, y2, 0);
    }

    void drawLine(const AXVector2D& v1, const AXVector2D& v2, float width){
        drawLine(v1.x, v1.y, v2.x, v2.y, width);
    }

    void drawLine(const AXVector2D& v1, const AXVector2D& v2){
        drawLine(v1.x, v1.y, v2.x, v2.y, 0);
    }

    //RECTANGLES
    void drawRect(float x, float y, float w, float h){
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        SDL_RenderFillRect(AXWindow::renderer, &rect);
    }

    void drawRectCenter(float x, float y, float w, float h){
        drawRect(x-w/2, y-h/2, w, h);
    }

    void drawRect(const AXVector2D &v, float w, float h){
        drawRect(v.x, v.y, w, h);
    }

    void drawRectOutline(float x, float y, float w, float h){
        rectangleRGBA(AXWindow::renderer, x, y, w, h, 
        AXWindow::renderColour.getR(),
        AXWindow::renderColour.getG(),
        AXWindow::renderColour.getB(),
        AXWindow::renderColour.getA());
    }
    
    //POLYGONS
    void drawPoly(const AXPolygon &p){
        drawPoly(p.getVerticies());
    }
    
    void drawPoly(const std::vector<AXVector2D>& v){
        glDisable(GL_TEXTURE_2D);
        glBegin(GL_POLYGON);
        for(auto& points : v){
            glVertex3f(points.x, points.y, 0.0f);
        }
        glEnd();
    }
    
    //ELLIPSES
    void drawEllipse(AXEllipse &e){
        drawEllipse(e.getPosition().x, e.getPosition().y, e.getSize().x, e.getSize().y);
    }
    
    void drawEllipse(const AXVector2D &cp, float xR, float yR){
        drawEllipse(cp.x, cp.y, xR, yR);
    }
    
    void drawEllipse(const AXVector2D &cp, float r){
        drawEllipse(cp.x, cp.y, r, r);
    }
    
    void drawEllipse(float x, float y, float r){
        drawEllipse(x, y, r, r);
    }
    
    void drawEllipse(float x, float y, float xR, float yR){
        filledEllipseRGBA(AXWindow::renderer, x, y, xR, yR, 
        AXWindow::renderColour.getR(),
        AXWindow::renderColour.getG(),
        AXWindow::renderColour.getB(),
        AXWindow::renderColour.getA());
    }

    void drawEllipseCenter(float x, float y, float xR, float yR){
        drawEllipse(x-xR/2, y-yR/2, xR, yR);
    }

    void drawEllipseCenter(float x, float y, float r){
        drawEllipse(x-r/2, y-r/2, r, r);
    }

    void drawEllipseCenter(const AXVector2D &cp, float r){
        drawEllipse(cp.x-r/2, cp.y-r/2, r, r);
    }
        
    //BACKGROUNDS
    void setBackground(float r, float g, float b, float a){
        AXWindow::backgroundColour.set(r, g, b, a);
    }
    
    void setBackground(float r, float g, float b){
        setBackground(r, g, b, 0);
    }
    
    void setBackground(const AXColour &c){
        setBackground(c.getR(), c.getG(), c.getB(), c.getA());
    }

    void setBackground(float rgba){
        setBackground(rgba, rgba, rgba, rgba);
    }
    
    //MATRIXES
    // void popMatrix(){
    //     glPopMatrix();
    // }
    
    // void pushMatrix(){
    //     glPushMatrix();
    // }
    
    // void translate(float x, float y, float z){
    //     glTranslatef(x, y, z);
    // }
    
    // void translate(float x, float y){
    //     glTranslatef(x, y, 0);
    // }
    
    // void translate(const AXVector2D &v){
    //     glTranslatef(v.x, v.y, 0);
    // }
    
    // void translate(const AXVector3D &v){
    //     glTranslatef(v.x, v.y, v.z);
    // }
    
    
    //FILLS
    void fill(const AXColour &c){
        AXWindow::renderColour.set(c.getR(), c.getG(), c.getB(), c.getA());
        SDL_SetRenderDrawColor(AXWindow::renderer, c.getR(), c.getG(), c.getB(), c.getA());
    }
    
    void fill(const float &rgb){
        AXWindow::renderColour.set(rgb, rgb, rgb, 255);
        SDL_SetRenderDrawColor(AXWindow::renderer, rgb, rgb, rgb, 255);
    }
    
    void fill(const float &r, const float &g, const float &b, const float &a){
        AXWindow::renderColour.set(r, g, b, a);
        SDL_SetRenderDrawColor(AXWindow::renderer, r, g, b, a);
    }
    
    void fill(const float &r, const float &g, const float &b){
        AXWindow::renderColour.set(r, g, b, 255);
        SDL_SetRenderDrawColor(AXWindow::renderer, r, g, b, 255);
    }
    
    void clearFill(){
        AXWindow::renderColour.set(255, 255, 255, 255);
        SDL_SetRenderDrawColor(AXWindow::renderer, 255, 255, 255, 255);
    }

}