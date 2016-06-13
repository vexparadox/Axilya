//
//  Collision.cpp
//  Project2
//
//  Created by William Meaton on 26/01/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Collision.h"

namespace Math {
    lineCollide::lineCollide(const Math::Vector2D &v1, const Math::Vector2D &v2){
        this->v1 = v1;
        this->v2 = v2;
    }
    
    Math::Vector2D lineCollisionCheckX(const Math::Vector2D &originalPosition, const Math::Vector2D &proposedMovement, const lineCollide &lc){
        if(originalPosition.x < lc.v1.x && proposedMovement.x > lc.v1.x){
            return Math::Vector2D(lc.v1.x, proposedMovement.y);
        }
        return proposedMovement;
    }
    
    Math::Vector2D lineCollisionCheckY(const Math::Vector2D &originalPosition, const Math::Vector2D &proposedMovement, const lineCollide &lc){
        if(originalPosition.y < lc.v1.y && proposedMovement.y > lc.v1.y){
            return Math::Vector2D(proposedMovement.x, lc.v1.y);
        }
        return proposedMovement;
    }
    
    //returns if v3 is inside of v1-v2
    bool isInsideQuad(const Vector2D &point, const Vector2D &v1, const Vector2D &v2){
        return Math::isInsideQuad(point.x, point.y, v1.x, v1.y, v2.x, v2.y);
    }
    
    bool isInsideQuad(const Vector2D &point, const Vector2D &v, float w, float h){
        return Math::isInsideQuad(point.x, point.y, v.x, v.y, w, h);
    }
    
    bool isInsideQuad(const Vector2D &point, const Graphics::Rect &r){
        return Math::isInsideQuad(point.x, point.y, r.getX(), r.getY(), r.getWidth(), r.getHeight());
    }
    
    bool isInsideQuad(const float &x1, const float &y1, const float &x2, const float &y2, const float &x3, const float &y3){
        if(x1 > x2 && x1 < x3 && y1 > y2 && x3 < y3){
            return true;
        }
        return false;
    }
    
    float signVector(float x1, float y1, float x2, float y2, float x3, float y3){
        return signVector(Vector2D(x1, y1), Vector2D(x2, y2), Vector2D(x3, y3));
    }
    
    float signVector(const Vector2D &v1, const Vector2D &v2, const Vector2D &v3){
        float det = 0.0f;
        det = ((v1.x - v3.x) * (v2.y - v3.y)) - ((v2.x - v3.x) * (v1.y - v3.y));
        return (det / 2.0f);
    }
    
    float signVector(const Graphics::Triangle &t){
        return signVector(t.getV1(), t.getV2(), t.getV3());
    }
    
    bool isInsideTriangle(const Vector2D &point, const Vector2D &v1, const Vector2D &v2, const Vector2D &v3){
        bool b1, b2, b3;
        b1 = signVector(point, v1, v2) < 0.0f;
        b2 = signVector(point, v2, v3) < 0.0f;
        b3 = signVector(point, v3, v1) < 0.0f;
        return ((b1 == b2) && (b2 == b3));
    }
    
    bool isInsideTriangle(const Vector2D &point, const Graphics::Triangle &t){
        return isInsideTriangle(point, t.getV1(), t.getV2(), t.getV3());
    }
    
    bool isInsideEllipse(const Vector2D &point, const Vector2D &cp, float xR, float yR)
    {
        //(((x-cp.x)^2)/rX^2 + ((y-cp.y)^2)/rY^2) <= 1
        return  ( (pow((point.x-cp.x),2)/pow(xR,2)) + (pow((point.y-cp.y),2)/pow(yR,2)) ) <=1;
    }
    bool isInsideEllipse(const Vector2D &point, const Graphics::Ellipse &e)
    {
        //(((x-cp.x)^2)/rX^2 + ((y-cp.y)^2)/rY^2) <= 1
        return  ( (pow((point.x-e.getVec().x),2)/pow(e.getSize().x,2)) + (pow((point.y-e.getVec().y),2)/pow(e.getSize().y,2)) ) <=1;
    }
    
    bool isInsideEllipse(const Vector2D &point, const Vector2D &cp, float r)
    {
        return isInsideEllipse(point, cp, r, r);
    }

    
    float vectorDistance(const Vector2D& v1, const Vector2D& v2){
        return sqrt((v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y));
    }
    
    float vectorDistance(float x1, float y1, float x2, float y2){
        return vectorDistance(Vector2D(x1, y1), Vector2D(x2, y2));
    }
}