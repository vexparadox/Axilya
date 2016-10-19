#include "PrefabManager.hpp"
#include "Entity.hpp"

PrefabManager* PrefabManager::instance = new PrefabManager();

PrefabManager::~PrefabManager(){
    for(auto it = entityMap.begin(); it != entityMap.end(); it++){
        delete it->second;
        it->second = 0;
    }
}

PrefabManager* PrefabManager::getInstance(){
	if(!instance){
		instance = new PrefabManager();
	}
	return instance;
}

bool PrefabManager::addPrefab(Entity* e){
    if (entityMap.find(e->getName()) == entityMap.end() && e){
	    entityMap.insert(std::pair<std::string, Entity*>(e->getName(), e));
    	return true;
    }
    return false;
}

Entity* PrefabManager::getPrefab(const std::string& name){
	if (entityMap.find(name) != entityMap.end()){
		return entityMap.at(name);
    }
    return 0;
}

bool PrefabManager::doesPrefabExist(const std::string& name){
    if (entityMap.find(name) != entityMap.end()){
        return true;
    }
    return false;
}