#ifndef Shape_H
#define Shape_H
#include "Vector2D.h"
class Shape{
protected:
    Math::Vector2D position;
public:
    /*!
    * Constructor of Shapes
    * Rects, Ellipses (and Triangles) are Shapes
    * @param v the center position of the Shape
    */
    Shape(const Math::Vector2D& v){
        this->position = v;
    }
};
#endif