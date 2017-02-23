#include "BallController.hpp"
#include "GameMaster.hpp"
void BallController::start(){
	hasStarted = false;
	srand(time(0));
}

void BallController::update(){
	if(hasStarted){
		owner->moveEntity(velocity);
	}else if(Input::getValue("SPACE")){
		hasStarted = true;
		velocity.x = 4;
		velocity.y = rand()%2;
	}
}

void BallController::onCollision(Entity* e){
	//reverse the balls direction
	velocity.x *= -1;
	if(Math::absolute(velocity.x) < 8){
		if(velocity.x < 0){
			velocity.x -= 0.5;
		}else{
			velocity.x += 0.5;
		}
	}
	//if the middle of the ball is greater than the middle of the paddle it hit
	if(transform->getPosition().y+(transform->getSize().y/2) > e->getTransform()->getPosition().y+(e->getTransform()->getSize().y/2)){
		//if it's on the top half of the paddle
		//knock it downwards
		velocity.y = 1.5;
	}else{
		//if it's on the bottom half of the paddle
		//knock it upwards
		velocity.y = -1.5;
	}
}

void BallController::onWorldCollision(int direction){
	//if the collision is on the Top or Bottom of the screen just bounce the ball
	if(direction == AX_COLLIDE_UP || direction == AX_COLLIDE_DOWN){
		velocity.y *= -1;
	}else{
		//if it goes past player one
		if(direction == AX_COLLIDE_LEFT){
			//give player 2 some score
			getScene()->getGameMaster()->getComponent<GameMaster>()->addScore(2, 1);
		}else{
			//else if it goes past player two
			getScene()->getGameMaster()->getComponent<GameMaster>()->addScore(1, 1);
		}
		//else reset the ball
		transform->set(AXWindow::getWidth()/2, AXWindow::getHeight()/2);
		hasStarted = false;
		velocity.x = 0;
		velocity.y = 0;
	}
}