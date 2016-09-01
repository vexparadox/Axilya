#include "World.hpp"

void World::setScene(Scene *scene) {
    if(scene) {
        this->scene = scene;
    }
}

Scene* World::getScene() {
    return scene;
}