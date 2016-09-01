//
// Created by William Meaton on 01/09/2016.
//

#ifndef CustomTile_hpp
#define CustomTile_hpp

#include "../CoreMain.h"

class CustomTile : public Tile{
public:
    CustomTile(int textureId);
    virtual void draw();
    virtual void update();
};


#endif
