//
//  Core.hpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#ifndef Core_hpp
#define Core_hpp

#include "../CoreMain.h"

class frameworkCore : public BaseCore{
public:
    void setup();
    void draw();
    void update();
};

#endif /* Core_hpp */
