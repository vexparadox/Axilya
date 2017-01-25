#ifndef Scene_hpp
#define Scene_hpp
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "World.hpp"
#include "pugixml.hpp"

class Entity;
class Transform;
class Scene{
    //the vector of entities
    std::vector<Entity*> entities;
    World* world = 0;
    Entity* gameMaster = 0;
    Math::Vector2D renderOffset;
    std::unordered_map<std::string, Entity*> uMap;
public:
    Scene();
    ~Scene();
    
    void start();

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

    Math::Vector2D& getRenderOffset();
    void offsetRenderer(float x, float y);
    void offsetRenderer(Math::Vector2D& v);
    void setRenderOffset(float x, float y);
    void setRenderOffset(Math::Vector2D& v);
    
    bool addEntity(Entity* e);

    bool setGameMaster(Entity* e);

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
    std::vector<Entity*>& getEntities();
    int numEntities();
};

#endif