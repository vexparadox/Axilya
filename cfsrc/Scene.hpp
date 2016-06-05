#ifndef Scene_hpp
#define Scene_hpp
#include <vector>

class Entity;
class Scene{
    //the vector of entities
    std::vector<Entity*> entities;
public:
    Scene();
    ~Scene();
    
    /*!
    * Called via the Core game loop
    * This will call Update on all Entities and thus Components 
    */
    void update();
    
    /*!
    * Called via the Core game loop
    * This will call Draw on all Entities and thus Components 
    */
    void draw();
    /*!
    * Adds a new Entity to this Scene
    * @param e the new Entity being added
    */
    void addEntity(Entity* e);
    /*!
    * Returns the number of Entities in this Scene
    * @return number of Entities in the Scene vector
    */
    int numEntities();
};

#endif