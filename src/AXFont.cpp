#include "headers/AXFont.hpp"
#define STB_TRUETYPE_IMPLEMENTATION 
#include "headers/stb_truetype.hpp"

const int AXFont::charDataSize = 96;

AXFont::AXFont(int id) : id(id){
	charData = (stbtt_bakedchar*)malloc(sizeof(stbtt_bakedchar)*charDataSize);
}

AXFont::~AXFont(){
	SDL_FreeSurface(surface);
	delete charData;
}

bool AXFont::loadFont(const std::string& p){
	if(surface){
		//freeup the surface
		SDL_FreeSurface(surface);
	}
	if(charData){
		//set the chardata to 0s
		memset(charData, 0, sizeof(stbtt_bakedchar)*charDataSize);
	}
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 512, 512, 8, 0, 0, 0, 0);
	if(!surface){
		return false;
	}
	this->path.insert(0, "data/");
	this->path.append(p);
	FILE* file = fopen(this->path.c_str(), "rb"); // load the file
	if(file != NULL){
		//find how big the file is
		fseek(file, 0, SEEK_END);
		//get the size
		long size = ftell(file);
		//reset the pointer
		fseek(file, 0, SEEK_SET);
		//allocate the buffer
		unsigned char* ttfBuffer = (unsigned char*)malloc(size);
		//read the file
	    fread(ttfBuffer, 1, size, file);
	    //close the file
	    fclose(file);
	    SDL_Color colors[256];
    	for(int i = 0; i < 256; i++){
        	colors[i].r = i;
        	colors[i].g = i;
        	colors[i].b = i;
    	}
    	SDL_SetPaletteColors(surface->format->palette, colors, 0, 256);
	    //bake all the glyphs into the sdl surface
	    if(stbtt_BakeFontBitmap(ttfBuffer, stbtt_GetFontOffsetForIndex(ttfBuffer, 0), 32.0, (unsigned char*)surface->pixels, 512, 512, 32, 96, charData) == 0){
	    	free(ttfBuffer); // free the buffer
	    	return false;	
	    }
	    free(ttfBuffer); // free the buffer
		return true;
	}else{
		return false;
	}
}

stbtt_bakedchar* AXFont::getCharData(){
	return charData;
}

bool AXFont::isLoaded(){
	return hasLoaded;
}
const std::string& AXFont::getPath(){
	return path;
}
SDL_Surface* AXFont::getSurface(){
	return surface;
}

int AXFont::getID(){
	return id;
}