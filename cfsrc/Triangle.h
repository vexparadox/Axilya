//
//  Triangle.h
//  GLFW3
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h

#include "Vector2D.h"
#include "Shape.h"

namespace Graphics{
class Triangle : public Shape{
    Math::Vector2D v1, v2, v3;
public:
    Triangle(const Math::Vector2D &v1, const Math::Vector2D &v2, const Math::Vector2D &v3){
        this->v1=v1;
        this->v2=v2;
        this->v3=v3;
    }
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3){
        this->v1 = Math::Vector2D(x1, y1);
        this->v2 = Math::Vector2D(x2, y2);
        this->v3 = Math::Vector2D(x3, y3);
    }
    
    void set(const Math::Vector2D &v1, const Math::Vector2D &v2, const Math::Vector2D &v3){
        this->v1=v1;
        this->v2=v2;
        this->v3=v3;
    }
    
    void set(float x1, float y1, float x2, float y2, float x3, float y3){
        this->set(Math::Vector2D(x1, y1), Math::Vector2D(x2, y2), Math::Vector2D(x3, y3));
    }
    
    const Math::Vector2D& getV1() const {
        return v1;
    }
    
    const Math::Vector2D& getV2() const{
        return v2;
    }
    
    const Math::Vector2D& getV3() const{
        return v3;
    }
    
};
}

#endif /* Triangle_h */
