//
//  Utils.cpp
//  Project2
//
//  Created by William Meaton on 02/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Utils.h"
namespace Math {
    float absolute(float f){
        if(f < 0){
            f = f*-1;
        }
        return f;
    }
    int absolute(int i){
        if(i < 0){
            i = i*-1;
        }
        return i;
    }
    
    float& setAbsolute(float &f){
        if(f < 0){
            f = f*-1;
        }
        return f;
    }
    
    int& setAbsolute(int &i){
        if(i < 0){
            i = i*-1;
        }
        return i;
    }
}
