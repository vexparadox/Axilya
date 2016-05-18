#ifndef Scene_hpp
#define Scene_hpp
#include <vector>

class Entity;
class Scene{
    //if the scene is active
    bool active = false;
    std::vector<Entity*> entities;
public:
    //constructor
    Scene(bool);
    //loop calls
    virtual void update();
    virtual void draw();
    void addEntity(Entity*);
    bool isActive();
};

#endif