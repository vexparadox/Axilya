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
#include "gamesrc/myComponents/Entities/RigidBodyMove.hpp"
#include "../myComponents/Entities/Destroyable.hpp"
#include "../myComponents/Tiles/exampleTileComponent.hpp"


class Core : public BaseCore{
public:
    void draw();
    void update();
    void setup();
    void loadTiles();
    Scene* scene1 = 0;
    TiledWorld* tileWorld = 0;
    StaticWorld* staticWorld = 0;
    Entity* character1 = 0;
    Entity* character2 = 0;
    int tile1ID, backgroundID;
};

#endif /* Core_hpp */
