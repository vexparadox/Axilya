#include "headers/AXWorld.hpp"

void AXWorld::setScene(AXScene *scene) {
    if(scene) {
        this->scene = scene;
    }
}

AXScene* AXWorld::getScene() {
    return scene;
}
