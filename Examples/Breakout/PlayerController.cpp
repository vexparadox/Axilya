#include "PlayerController.hpp"

void PlayerController::update(){
	owner->getTransform()->set(((Input::mouseX)-40), AXWindow::getHeight()-20);
	owner->getCollider()->getBounds()->set(
		Math::Vector2D(Input::mouseX-40, AXWindow::getHeight()-20), 
		owner->getCollider()->getBounds()->getSize());
}