#include "PlayerController.hpp"

void PlayerController::update(){
	owner->getTransform()->set(((AXInput::mouseX)-40), AXWindow::getHeight()-20);
	owner->getCollider()->getBounds()->set(
		AXVector2D(AXInput::mouseX-40, AXWindow::getHeight()-20), 
		owner->getCollider()->getBounds()->getSize());
}