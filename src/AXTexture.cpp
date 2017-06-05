#include "headers/AXTexture.hpp"
#include "headers/AXWindow.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "headers/stb_image.h"
#include <cstdlib> // Used for copying data
#include <cstring> // Used for copying data
AXTexture::AXTexture(int id, const std::string& path) : AXResource(id){
	this->loadImage(path);
}


AXTexture::AXTexture(const std::string& path) : AXResource(-1){
	this->loadImage(path);
}

AXTexture::AXTexture(SDL_Texture* texture, int width, int height) : AXResource(-1){
    //this is used mainly by AXFonts
    if(texture){
        this->texture = texture;
        this->w = width;
        this->h = height;
        loaded = true;
        setPath("SDL");
    }else{
        AXLog::log("AXTexture", "Incorrect SDL_Texture data given.", AX_LOG_ERROR);
    }
}


AXTexture::AXTexture() : AXResource(-1){
}

AXTexture::~AXTexture(){
    if(texture){
	   SDL_DestroyTexture(texture);
    }
    if(loaded){
        stbi_image_free(imageDataPtr);
    }
}

bool AXTexture::loadImage(const std::string& path){
    std::string temp = AXWindow::runPath+ path;
    //if it's already loaded, free the data
    if(loaded){
    	SDL_DestroyTexture(texture);
        stbi_image_free(imageDataPtr);
    }
    loaded = false;
    //load the image
    int format = STBI_rgb_alpha;
    int formatFound;
    imageDataPtr = stbi_load(temp.c_str(), &this->w, &this->h, &formatFound, format);
    if(imageDataPtr == NULL){
        AXLog::log("Image file failed to load", stbi_failure_reason(), AX_LOG_ERROR);
        loaded = false;
        return false;
    }
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(imageDataPtr, this->w, this->h, 32, 4*this->w, SDL_PIXELFORMAT_RGBA32);
    if (surface == NULL) {
        AXLog::log("SDLSurface failed to create", SDL_GetError(), AX_LOG_ERROR);
        stbi_image_free(imageDataPtr);
        loaded = false;
        return false;
    }
    texture = SDL_CreateTextureFromSurface(AXWindow::renderer, surface);
    if(texture == NULL){
        AXLog::log("SDLTexture failed to create", SDL_GetError(), AX_LOG_ERROR);
        loaded = false;
        return false;
    }
    SDL_FreeSurface(surface);
    setPath(temp);
    loaded = true;
    return true;
}

SDL_Texture* AXTexture::getTextureData() const{
	if(loaded && texture){
		return texture;
	}
	return 0;
}

int AXTexture::getWidth() const{
	return w;
}

int AXTexture::getHeight() const{
	return h;
}

unsigned char* AXTexture::getRawPixelData() const{
    if(loaded){
        return imageDataPtr;
    }else{
        return 0;
    }
}

AXTexture* AXTexture::clone(){
    AXTexture* temp = new AXTexture();
    if(loaded){
        temp->imageDataPtr = (unsigned char*) std::malloc(sizeof(imageDataPtr));
        std::memcpy(temp->imageDataPtr, imageDataPtr, sizeof(imageDataPtr));
        temp->w = w;
        temp->h = h;
        SDL_Surface* tempSurface = SDL_CreateRGBSurfaceWithFormatFrom(temp->imageDataPtr, temp->w, temp->h, 32, 4*temp->w, SDL_PIXELFORMAT_RGBA32);
        if (tempSurface == NULL) {
            AXLog::log("SDLSurface failed to create", SDL_GetError(), AX_LOG_ERROR);
            temp->loaded = false;
            stbi_image_free(temp->imageDataPtr);
            return temp;
        }
        temp->texture = SDL_CreateTextureFromSurface(AXWindow::renderer, tempSurface);
        if (temp->texture == NULL){
            AXLog::log("SDLTexture failed to create", SDL_GetError(), AX_LOG_ERROR);
            temp->loaded = false;
            stbi_image_free(temp->imageDataPtr);
            return temp;
        }
        SDL_FreeSurface(tempSurface);
        temp->loaded = true;
    }
    return temp;
}
