#include "PlayerController.hpp"
#include "Bullet.hpp"

void PlayerController::start(){
	text = getScene()->findEntity("text")->getRenderer()->getCurrentText();
}

void PlayerController::update(){
	if(AXInput::getValue("D") || AXInput::getValue("RIGHT")){
		owner->moveEntity(3, 0);
	}else if(AXInput::getValue("A") || AXInput::getValue("LEFT")){
		owner->moveEntity(-3, 0);
	}

	if(AXInput::getValue("SPACE") && bullet == 0){
		AXEntity* e = getScene()->instantiate("bullet", 
			prefabManager->getPrefab("bullet"),
			new AXTransform(
				transform->getPosition().x+owner->getTransform()->getSize().x/2,
				transform->getPosition().y, 16, 32));
		if(e != 0){
			bullet = e->getComponent<Bullet>();
			bullet->pc = this;
			owner->getAudioPlayer()->playAudioChunk("fire");
		}
	}
}

void PlayerController::bulletDead(bool hitEnemy){
	if(hitEnemy){
		score++;
		text->setText("Score: "+std::to_string(score));
	}
	bullet = 0;
}