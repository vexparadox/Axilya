//
//  Ellipse.h
//  closedFrameworks
//
//  Created by Charles Ringer on 27/03/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Ellipse_h
#define Ellipse_h
#include "Vector2D.h"
#include "Shape.h"

namespace Graphics{
    class Ellipse : public Shape{
    private:
        //x radius and y radius
        float xR, yR;
    public:

        Ellipse(const Math::Vector2D &cp, float xR, float yR) : Shape(cp)
        {
            this->xR=xR;
            this->yR=yR;   
        }
        
        //Circle
        Ellipse(const Math::Vector2D &cp, float r) : Shape(cp)
        {
            xR=r;
            yR=r;   
        }
        
        Ellipse(float x, float y, float xR, float yR) : Shape(Math::Vector2D(x, y))
        {
            xR = xR;
            yR = yR;
        }
        
        //Circle
        Ellipse(float x, float y, float r) : Shape(Math::Vector2D(x, y))
        {
            xR = r;
            yR = r;
        }
        
        void set(const Math::Vector2D &cp, float xR, float yR)
        {
            this->position=cp;
            this->xR=xR;
            this->yR=yR;
            
        }
        
        void set(const Math::Vector2D &cp, float r)
        {
            this->position=cp;
            this->xR=r;
            this->yR=r;
        }
        
        void set(float x, float y, float xR, float yR)
        {
            position = Math::Vector2D(x, y);
            this->xR = xR;
            this->yR = yR;
        }

        void set(float x, float y, float r)
        {
            position = Math::Vector2D(x, y);
            this->xR = r;
            this->yR = r;
        }
        //Getters
        Math::Vector2D getVec() const { return  position;};
        float getCX() const { return position.x;};
        float getCY() const { return position.y;};
        float getXR() const { return xR;};
        float getYR() const { return yR;};
    };
}

#endif /* Ellipse_h */
