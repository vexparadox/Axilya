#include "headers/AXFont.hpp"
#include "headers/AXWindow.hpp"
AXFont::AXFont(int id, const std::string& p, int size) : AXResource(id){
	loadFont(p, size);
}

AXFont::AXFont(const std::string& p, int size) : AXResource(-1){
	loadFont(p, size);
}

AXFont::~AXFont(){
	TTF_CloseFont(fontData);
}

bool AXFont::loadFont(const std::string& p, int size){
	if(hasLoaded){
		//freeup the surface
		TTF_CloseFont(fontData);
	}
	std::string path = AXWindow::runPath+"data/" + p;

	fontData = TTF_OpenFont(path.c_str(), size);
	if(!fontData){
		std::cout << "Font failed load at: " << p << std::endl;
		std::cout << TTF_GetError() << std::endl;
		return false;
	}
	fontHeight = TTF_FontHeight(fontData);
	hasLoaded = true;
	return true;
}

SDL_Texture* AXFont::bakeTexture(const std::string string, AXColour& colour){
	if(hasLoaded){
		SDL_Surface* temp = TTF_RenderUTF8_Blended(fontData, string.c_str(), colour.toSDL());
		if(!temp){
			std::cout << "Font failed to bake! SDL Error: " << TTF_GetError() << std::endl;
			return 0;
		}
		SDL_Texture* texture = SDL_CreateTextureFromSurface(AXWindow::renderer, temp);
		if(!texture){
			std::cout << "Font failed to bake! SDL Error: " << SDL_GetError() << std::endl;
			return 0;
		}
		SDL_FreeSurface(temp);
		return texture;
	}
	std::cout << "Font not loaded, bake failed" << std::endl;
	return 0;
}

AXVector2D AXFont::getStringSize(const std::string string){
	AXVector2D size;
	if(hasLoaded){
		int width, height;
		TTF_SizeText(fontData, string.c_str(), &width, &height);
		size.x = width;
		size.y = height;
	}
	return size;
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