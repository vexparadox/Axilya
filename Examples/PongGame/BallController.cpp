#include "BallController.hpp"

void BallController::start(){
	velocity.x = 3;
}

void BallController::update(){
	owner->moveEntity(velocity);
}