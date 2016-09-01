//
// Created by William Meaton on 01/09/2016.
//

#ifndef TileComponent_hpp
#define TileComponent_hpp

class Tile;
class Scene;
class TileComponent {
    Tile* owner;
public:
    //set the owner of the component
    void setOwner(Tile* owner);
    //returns the owner of this component
    Tile* getOwner();
    //returns the scene that the owner belongs to
    Scene* getScene();

    virtual void start(){};
    virtual void update(){};

};


#endif
