#include "headers/AXTexture.hpp"
#include "headers/AXWindow.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
AXTexture::AXTexture(int id, const std::string& path) : AXResource(id){
	this->loadImage(path);
}


AXTexture::AXTexture(const std::string& path) : AXResource(-1){
	this->loadImage(path);
}


AXTexture::AXTexture() : AXResource(-1){
}

AXTexture::~AXTexture(){
	SDL_DestroyTexture(texture);
}

bool AXTexture::loadImage(const std::string& path){
    std::string temp = AXWindow::runPath+"data/" + path;
    //if it's already loaded, free the data
    if(loaded){
    	SDL_DestroyTexture(texture);
    }
    loaded = false;
    //load the image
    int format = STBI_rgb_alpha;
    int formatFound;
    imageDataPtr = stbi_load(temp.c_str(), &this->w, &this->h, &formatFound, format);
    if(imageDataPtr == NULL){
        std::cout << stbi_failure_reason() << std::endl;
        loaded = false;
        return false;
    }
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(imageDataPtr, this->w, this->h, 32, 4*this->w, SDL_PIXELFORMAT_RGBA32);
    if (surface == NULL) {
        std::cout << SDL_GetError() << std::endl;
        stbi_image_free(imageDataPtr);
        loaded = false;
        return false;
    }
    texture = SDL_CreateTextureFromSurface(AXWindow::renderer, surface);
    if(texture == NULL){
        std::cout << SDL_GetError() << std::endl;
        loaded = false;
        return false;
    }
    stbi_image_free(imageDataPtr);
    SDL_FreeSurface(surface);
    setPath(temp);
    loaded = true;
    return true;
}

SDL_Texture* AXTexture::getTextureData(){
	if(loaded && texture){
		return texture;
	}
	return 0;
}

int AXTexture::getWidth(){
	return w;
}

int AXTexture::getHeight(){
	return h;
}