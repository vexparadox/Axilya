#include "BallController.hpp"

void BallController::start(){
	velocity.x = 3;
}

void BallController::update(){
	owner->moveEntity(velocity);
}

void BallController::onCollision(Entity* e){
	velocity.x *= -1;
	velocity.y *= -1;
}