//
//  Core.hpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#ifndef Core_hpp
#define Core_hpp
#include "../cfsrc/Runner.hpp" //This file is required.
#include "CoreMain.h"
#include "exampleComponent.hpp"

class Core : public BaseCore{
public:
    Core();
    ~Core();
    void draw();
    void update();
    void setup();
    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int button);
    void mouseReleased(int button);
    void exitCalled();
    Scene* scene1 = 0;
    Entity* character = 0;
};

#endif /* Core_hpp */
