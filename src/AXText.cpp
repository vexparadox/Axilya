#include "headers/AXText.hpp"
AXText::AXText(const std::string& s) : path(s){
	init(path);
}

void AXText::init(std::string& s){
}

void AXText::draw(float x, float y, char* text){

}

Component* AXText::clone(){
	return nullptr;
}