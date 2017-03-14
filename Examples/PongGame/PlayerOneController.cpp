#include "PlayerOneController.hpp"

void PlayerOneController::update(){
	if(AXInput::getValue("S") || AXInput::getValue("GC1_RIGHTSTICK_Y") < -3000){
		owner->moveEntity(Math::Vector2D(0, 4));
	}else if(AXInput::getValue("W") || AXInput::getValue("GC1_RIGHTSTICK_Y") > 3000){
		owner->moveEntity(Math::Vector2D(0, -4));
	}
}