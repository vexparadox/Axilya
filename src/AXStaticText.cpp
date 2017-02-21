#include "headers/stb_truetype.hpp"
#include "headers/AXStaticText.hpp"

AXStaticText::AXStaticText(const std::string& text, AXFont* font) : text(text){
	this->font = font;
	if(font){
		bakeText();
	}
}

AXStaticText::AXStaticText(const std::string& text, int fontID) : text(text){
	setFont(fontID);
	if(this->font){
		bakeText();
	}
}

void AXStaticText::bakeText(){
	//bake the string
	if(this->font->isLoaded()){
		SDL_DestroyTexture(this->texture);
		SDL_Surface* glyphSurface = font->getSurface();
		SDL_Surface* tempSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, 512, 512, 8, 0, 0, 0, 0);
	    SDL_Color colors[256];
    	for(int i = 0; i < 256; i++){
        	colors[i].r = i;
        	colors[i].g = i;
        	colors[i].b = i;
    	}
    	SDL_SetPaletteColors(tempSurface->format->palette, colors, 0, 256);
	    for (char* c = (char*)this->text.c_str(); *c; c++) {
	    	stbtt_aligned_quad q;
		    float x = 0, y = 0;
		    stbtt_GetBakedQuad(font->getCharData(), 512, 512, *c-32, &x, &y, &q, 1);	
	    	int w = q.x1-q.x0;
    		int h = q.y1-q.y0;
    		SDL_Rect src  = {.x = (int)(q.s0*512), .y = (int)(q.t0*512), .w = w, .h = h};
	        SDL_Rect dest = {.x = (int)(q.x0), .y = (int)(32+q.y0), .w = w, .h = h};
			SDL_BlitSurface(glyphSurface, &src, tempSurface, &dest);
	    }
	    this->texture = SDL_CreateTextureFromSurface(AXWindow::renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
	}
}

void AXStaticText::setText(const std::string& text){
	this->text = text;
	bakeText();
}

void AXStaticText::setFont(AXFont* font){
	this->font = font;
	if(this->font){
		bakeText();
	}
}

void AXStaticText::setFont(int id){
	this->font = resourceManager->getFont(id);
	if(this->font){
		bakeText();
	}
}

void AXStaticText::draw(float x, float y){
	if(texture){
		SDL_Rect dest = {.x = (int)(x), .y = (int)(y), .w = 512, .h = 512};
		SDL_RenderCopy(AXWindow::renderer, texture, NULL, &dest);
	}
}