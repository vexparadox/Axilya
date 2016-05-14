//
//  Poly.h
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Poly_h
#define Poly_h
#include <vector>
#include "Vector2D.h"
namespace Graphics{
class Polygon{
private:
    std::vector<Math::Vector2D> v;
public:
    Polygon();
    ~Polygon();
    void addVertex(const Math::Vector2D &v){
        this->v.push_back(v);
    }
    
    void clear(){
        this->v.clear();
    }
    
    std::vector<Math::Vector2D> getVerticies() const{
        return v;
    }
    
};
}

#endif /* Poly_h */
