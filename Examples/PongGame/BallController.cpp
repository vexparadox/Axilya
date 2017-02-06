#include "BallController.hpp"

void BallController::start(){
	velocity.x = 5;
	velocity.y = 1;
}

void BallController::update(){
	owner->moveEntity(velocity);
}

void BallController::onCollision(Entity* e){
	velocity.x += 1;
	velocity.y += 1;
	velocity.x *= -1;
	velocity.y *= -1;
}

void BallController::onWorldCollision(int direction){
	if(direction == AX_COLLIDE_UP || direction == AX_COLLIDE_DOWN){
		velocity.y *= -1;
	}else{
		AXWindow::shutdown();
	}
}