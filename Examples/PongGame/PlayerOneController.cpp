#include "PlayerOneController.hpp"

void PlayerOneController::update(){
	if(Input::getValue("S") || Input::getValue("GC1_RIGHTSTICK_Y") < -3000){
		owner->moveEntity(Math::Vector2D(0, 4));
	}else if(Input::getValue("W") || Input::getValue("GC1_RIGHTSTICK_Y") > 3000){
		owner->moveEntity(Math::Vector2D(0, -4));
	}
}