#ifndef PrefabManager_hpp
#define PrefabManager_hpp
#include "Entity.hpp"

class PrefabManager{
    PrefabManager(){};
    static PrefabManager* instance;
    ~PrefabManager();
    std::unordered_map<std::string, Entity*> entityMap;
public:
	static PrefabManager* getInstance();
	bool addPrefab(const std::string& name, Entity* e);
	Entity* getPrefab(const std::string& name);
	bool doesPrefabExist(const std::string& name);
};

#endif