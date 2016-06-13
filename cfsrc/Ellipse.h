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

        Ellipse(const Math::Vector2D &cp, float xR, float yR) : Shape(cp, Math::Vector2D(xR, yR))
        {
        }
        Ellipse(const Math::Vector2D &cp, float r) : Shape(cp, Math::Vector2D(r, r))
        {   
        }
        Ellipse(float x, float y, float xR, float yR) : Shape(Math::Vector2D(x, y), Math::Vector2D(xR, yR))
        {
        }
        
        //Circle
        Ellipse(float x, float y, float r) : Shape(Math::Vector2D(x, y), Math::Vector2D(r, r))
        {
        }
        
        void set(const Math::Vector2D &cp, float xR, float yR)
        {
            this->set(cp.x, cp.y, xR, yR);
        }
        
        void set(const Math::Vector2D &cp, float r)
        {
            this->set(cp.x, cp.y, r, r);
        }
        
        void set(float x, float y, float xR, float yR)
        {
            this->position.x = x;
            this->position.y = y;
            this->size.x = xR;
            this->size.y = yR;
        }

        void set(float x, float y, float r)
        {
            this->set(x, y, r, r);
        }

        //Getters
        Math::Vector2D getVec() const { return  position;};
        
        const Math::Vector2D& getPosition() const{
            return position;
        }
        const Math::Vector2D& getSize() const {
            return size;
        } 
    };
}

#endif /* Ellipse_h */
