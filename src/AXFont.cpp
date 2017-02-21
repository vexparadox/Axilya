#include "headers/AXFont.hpp"
#define STB_TRUETYPE_IMPLEMENTATION 
#include "headers/stb_truetype.hpp"

const int AXFont::charDataSize = 96;

AXFont::AXFont(std::string& name, std::string& path) : name(name){
	charData = (stbtt_bakedchar*)malloc(sizeof(stbtt_bakedchar)*charDataSize);
	hasLoaded = loadFont(path);
}

bool AXFont::loadFont(std::string& path){
	if(surface){
		//freeup the surface
		SDL_FreeSurface(surface);
	}
	if(charData){
		//set the chardata to 0s
		memset(charData, 0, sizeof(stbtt_bakedchar)*charDataSize);
	}
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, 512, 512, 8, 0, 0, 0, 0);
	// fontInfo = new stbtt_fontinfo();
	path.insert(0, "data/");
	FILE* file = fopen(path.c_str(), "rb"); // load the file
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
        	colors[i].a = i;
    	}
    	SDL_SetPaletteColors(surface->format->palette, colors, 0, 256);
	    //bake all the glyphs into the sdl surface
	    stbtt_BakeFontBitmap(ttfBuffer, stbtt_GetFontOffsetForIndex(ttfBuffer, 0), 32.0, (unsigned char*)surface->pixels, 512, 512, 32, 96, charData); // writes the 
	    free(ttfBuffer); // free the buffer
	    return true;
	}else{
		return false;
	}
}
void AXFont::draw(float x, float y, char* text){
	int font_height = 32;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(AXWindow::renderer, surface);
    for (char* c = text; *c; c++) {
        /* stbtt_aligned_quad effectively holds a source and destination
         * rectangle for the glyph. we get one for the current char */
        stbtt_aligned_quad q;
        stbtt_GetBakedQuad(charData, 512, 512, *c-32, &x, &y, &q, 1);

        /* now convert from stbtt_aligned_quad to source/dest SDL_Rects */

        /* width and height are simple */
        int w = q.x1-q.x0;
        int h = q.y1-q.y0;

         // t0,s0 and t1,s1 are texture-space coordinates, that is floats from
         // * 0.0-1.0. we have to scale them back to the pixel space used in the
         // * glyph data bitmap. its a simple as multiplying by the glyph bitmap
         // * dimensions 
        SDL_Rect src  = { .x = static_cast<int>(q.s0*512), .y = static_cast<int>(q.t0*512), .w = w, .h = h };

        /* in gl/d3d the y value is inverted compared to what sdl expects. y0
         * is negative here. we add (subtract) it to the baseline to get the
         * correct "top" position to blit to */
        SDL_Rect dest = { .x = static_cast<int>(q.x0), .y = static_cast<int>(font_height+q.y0), .w = w, .h = h };

        /* draw it */
		SDL_RenderCopy(AXWindow::renderer, texture, &src, &dest);
    }
	SDL_DestroyTexture(texture);
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