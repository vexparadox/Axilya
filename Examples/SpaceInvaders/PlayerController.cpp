#include "PlayerController.hpp"
#include "Bullet.hpp"

void PlayerController::update(){
	if(Input::getValue("D") || Input::getValue("RIGHT")){
		owner->moveEntity(3, 0);
	}else if(Input::getValue("A") || Input::getValue("LEFT")){
		owner->moveEntity(-3, 0);
	}

	if(Input::getValue("SPACE") && bullet == 0){
		Entity* e = getScene()->instantiate("bullet", 
			prefabManager->getPrefab("bullet"),
			new Transform(
				transform->getPosition().x+owner->getTransform()->getSize().x/2,
				transform->getPosition().y, 16, 32));
		if(e != 0){
			bullet = e->getComponent<Bullet>();
			bullet->pc = this;
		}
	}
}

void PlayerController::bulletDead(){
	bullet = 0;
}