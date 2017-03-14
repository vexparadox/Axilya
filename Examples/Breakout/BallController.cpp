#include "BallController.hpp"

void BallController::start(){
	hasStarted = false;
}

void BallController::update(){
	if(AXInput::getValue("SPACE") && !hasStarted){
		hasStarted = true;
		velocity.y = 5;
	}
	if(hasStarted){
		owner->moveEntity(velocity);
	}
}

void BallController::onCollision(Entity* e){
	velocity.y *= -1;
	if(Math::absolute(velocity.y) < 8){
		if(velocity.y < 0){
			velocity.y -= 0.5;
		}else{
			velocity.y += 0.5;
		}
	}

	if(e->getName() != "player"){
		e->destroy();
	}else{
		if(transform->getPosition().x+(transform->getWidth()/2) > e->getTransform()->getPosition().x+(e->getTransform()->getWidth()/2)){
			//if it's on the right half of the paddle
			//knock it left
			velocity.x = 2;
		}else{
			//if it's on the bottom half of the paddle
			//knock it right
			velocity.x = -2;
		}
	}
}

void BallController::onWorldCollision(int direction){
	switch(direction){
		case AX_COLLIDE_DOWN:
			hasStarted = false;
			transform->set(50, AXWindow::getHeight()/2);
			break;
		case AX_COLLIDE_UP:
			velocity.y *= -1;
			break;
		case AX_COLLIDE_RIGHT:
		case AX_COLLIDE_LEFT:
			velocity.x *= -1;
			break;
	}
}
