#include "PlayerTwoController.hpp"

void PlayerTwoController::update(){
	if(Input::getValue("DOWN") || Input::getValue("GC1_RIGHTSTICK_Y") < -3000){
		owner->moveEntity(Math::Vector2D(0, 4));
	}else if(Input::getValue("UP") || Input::getValue("GC2_RIGHTSTICK_Y") > 3000){
		owner->moveEntity(Math::Vector2D(0, -4));
	}
}