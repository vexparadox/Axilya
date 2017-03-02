#include "headers/AXFont.hpp"
AXFont::AXFont(int id) : id(id){
}

AXFont::~AXFont(){
	TTF_CloseFont(fontData);
}

bool AXFont::loadFont(const std::string& p, int size){
	if(hasLoaded){
		//freeup the surface
		TTF_CloseFont(fontData);
	}
	std::cout << p << std::endl;
	fontData = TTF_OpenFont(p.c_str(), size);
	if(!fontData){
		std::cout << "Font failed load at: " << p << std::endl;
		std::cout << TTF_GetError() << std::endl;
		return false;
	}
	fontHeight = TTF_FontHeight(fontData);
	hasLoaded = true;
	return true;
}


TTF_Font* AXFont::getFontData(){
	return fontData;
}
bool AXFont::isLoaded(){
	return hasLoaded;
}

const std::string& AXFont::getPath(){
	return path;
}

int AXFont::getID(){
	return id;
}