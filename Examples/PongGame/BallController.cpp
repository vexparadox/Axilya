#include "BallController.hpp"

void BallController::start(){
	velocity.x = 3;
	velocity.y = 1;
}

void BallController::update(){
	owner->moveEntity(velocity);
}

void BallController::onCollision(Entity* e){
	//reverse the balls direction
	velocity.x *= -1;
	if(Math::absolute(velocity.x) < 5){
		if(velocity.x < 0){
			velocity.x -= 0.5;
		}else{
			velocity.x += 0.5;
		}
	}
	//if the middle of the ball is greater than the middle of the paddle it hit
	if(owner->getTransform()->getPos().y+(e->getTransform()->getSize().y/2) > e->getTransform()->getPos().y+(e->getTransform()->getSize().y/2)){
		//if it's on the top half of the paddle
		//knock it downwards
		velocity.y = 1;
	}else{
		//if it's on the bottom half of the paddle
		//knock it upwards
		velocity.y = -1;
	}
}

void BallController::onWorldCollision(int direction){
	//if the collision is on the Top or Bottom of the screen just bounce the ball
	if(direction == AX_COLLIDE_UP || direction == AX_COLLIDE_DOWN){
		velocity.y *= -1;
	}else{
		//else reset the ball
		owner->getTransform()->set(AXWindow::getWidth()/2, AXWindow::getHeight()/2);
		velocity.x = 3;
	}
}