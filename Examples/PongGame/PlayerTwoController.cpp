#include "PlayerTwoController.hpp"

void PlayerTwoController::update(){
	if(Input::getValue("DOWN")){
		owner->moveEntity(Math::Vector2D(0, 4));
	}else if(Input::getValue("UP")){
		owner->moveEntity(Math::Vector2D(0, -4));
	}
}