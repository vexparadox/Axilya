#ifndef Scene_hpp
#define Scene_hpp
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "world/World.hpp"
#include "PUGIXML/pugixml.hpp"

class Entity;
class Transform;
class Scene{
    //the vector of entities
    std::vector<Entity*> entities;
    World* world = 0;
    Entity* gameMaster = 0;
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
    * @return wheather it was succesful or not
    */
    bool addEntity(Entity* e);

    bool addGameMaster(Entity* e);

    Entity* getGameMaster();

    void addWorld(World* w);

    void removeEntity(Entity* e);

    Entity* instantiate(const std::string& name, Entity* e, Transform* t);
    Entity* instantiate(const std::string& name, Entity* e);

    Entity* findEntity(const std::string& name);

    void collideCheck(Entity* e, Math::Vector2D& proposedMovement);

    void parseSceneFile(const std::string& path);
    /*!
    * Returns the number of Entities in this Scene
    * @return number of Entities in the Scene vector
    */
    int numEntities();
};

#endif