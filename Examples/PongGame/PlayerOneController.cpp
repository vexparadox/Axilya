#include "PlayerOneController.hpp"

void PlayerOneController::update(){
	if(Input::getValue("S")){
		owner->moveEntity(Math::Vector2D(0, 4));
	}else if(Input::getValue("W")){
		owner->moveEntity(Math::Vector2D(0, -4));
	}
}