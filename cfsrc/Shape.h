#ifndef Shape_H
#define Shape_H
#include "Vector2D.h"
class Shape{
protected:
    Math::Vector2D position;
public:
    Shape(const Math::Vector2D& v){
        this->position = v;
    }
};
#endif