#include "headers/AXStaticText.hpp"
#include "headers/AXGraphics.hpp"

AXStaticText::AXStaticText(const std::string& text, AXFont* font) : text(text){
	setFont(font);
	isBaked = false;
}

AXStaticText::AXStaticText(const std::string& text, int fontID) : text(text){
	setFont(fontID);
	isBaked = false;
}

AXStaticText::~AXStaticText(){
	SDL_DestroyTexture(this->texture);
}

bool AXStaticText::bakeText(){
	//bake the string
	if(this->font){
		if(this->font->isLoaded()){
			if(this->isBaked && this->texture){
				SDL_DestroyTexture(this->texture);
			}
			this->texture = this->font->bakeTexture(this->text, this->colour);
			if(!texture){
				isBaked = false;
				return false;
			}
			AXVector2D t = this->font->getStringSize(this->text);
			width = t.x;
			height = t.y;
			if(owner){
				//resize the entity to the size of this text
				owner->resizeEntity(width, height);
			}
			isBaked = true;
			return true;
		}
	}
	std::cout << "The font isn't loaded, this can't be baked." << std::endl;
	isBaked = false;
	return false;
}

void AXStaticText::setText(const std::string& text){
	this->text = text;
	bakeText();
}

void AXStaticText::setFont(AXFont* font){
	this->font = font;
}

void AXStaticText::setFont(int id){
	this->font = resourceManager->getFont(id);
}

void AXStaticText::draw(float x, float y){
	if(texture && isBaked){
		AXGraphics::drawSDLTexture(texture, x, y, width, height);
	}
}

AXText* AXStaticText::clone(){
	AXText* a = new AXStaticText(this->text, this->font);
	a->setOwner(this->owner);
	a->bakeText();
	return a;
}