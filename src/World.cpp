#include "headers/World.hpp"

void World::setScene(AXScene *scene) {
    if(scene) {
        this->scene = scene;
    }
}

AXScene* World::getScene() {
    return scene;
}
