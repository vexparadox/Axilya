#include "PlayerTwoController.hpp"

void PlayerTwoController::update(){
	if(AXInput::getValue("DOWN") || AXInput::getValue("GC1_RIGHTSTICK_Y") < -3000){
		owner->moveEntity(AXVector2D(0, 4));
	}else if(AXInput::getValue("UP") || AXInput::getValue("GC2_RIGHTSTICK_Y") > 3000){
		owner->moveEntity(AXVector2D(0, -4));
	}
}