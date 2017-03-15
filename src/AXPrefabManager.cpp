#include "headers/AXPrefabManager.hpp"
#include "headers/AXEntity.hpp"

AXPrefabManager* AXPrefabManager::instance = new AXPrefabManager();

AXPrefabManager::~AXPrefabManager(){
    for(auto it = entityMap.begin(); it != entityMap.end(); it++){
        delete it->second;
        it->second = 0;
    }
}

AXPrefabManager* AXPrefabManager::getInstance(){
	if(!instance){
		instance = new AXPrefabManager();
	}
	return instance;
}

bool AXPrefabManager::addPrefab(AXEntity* e){
    if (entityMap.find(e->getName()) == entityMap.end() && e){
	    entityMap.insert(std::pair<std::string, AXEntity*>(e->getName(), e));
    	return true;
    }
    return false;
}

AXEntity* AXPrefabManager::getPrefab(const std::string& name){
	if (entityMap.find(name) != entityMap.end()){
		return entityMap.at(name);
    }
    return 0;
}

bool AXPrefabManager::doesPrefabExist(const std::string& name){
    if (entityMap.find(name) != entityMap.end()){
        return true;
    }
    return false;
}
