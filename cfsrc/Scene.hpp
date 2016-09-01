#ifndef Scene_hpp
#define Scene_hpp
#include <vector>
#include <unordered_map>
 #include <algorithm>
#include "World.hpp"

class Entity;
class Scene{
    //the vector of entities
    std::vector<Entity*> entities;
    World* world = 0;
    std::unordered_map<std::string, Entity*> uMap;
public:
    Scene();
    ~Scene();
    
    /*!
    * Called via the Core game loop. 
    * This will call Update on all Entities and thus Components 
    */
    void update();
    
    /*!
    * Called via the Core game loop.
    * This will call Draw on all Entities and thus Components 
    */
    void draw();
    /*!
    * Adds a new Entity to this Scene
    * @param e the new Entity being added
    */
    void addEntity(Entity* e);

    void addWorld(World* w);

    void removeEntity(Entity* e);

    Entity* findEntity(const std::string& name);

    void collideCheck(Entity* e, Math::Vector2D& proposedMovement);
    /*!
    * Returns the number of Entities in this Scene
    * @return number of Entities in the Scene vector
    */
    int numEntities();
};

#endif