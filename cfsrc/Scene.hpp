#ifndef Scene_hpp
#define Scene_hpp
#include <vector>

class Entity;
class Scene{
    //if the scene is active
    std::vector<Entity*> entities;
public:
    //constructor
    Scene();
    ~Scene();
    //loop calls
    virtual void update();
    virtual void draw();
    void addEntity(Entity*);
    int numEntities();
};

#endif