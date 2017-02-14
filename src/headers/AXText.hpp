#ifndef AXText_hpp
#define AXText_hpp

#include "Component.hpp"
#include <stdio.h>
#include "AXWindow.hpp"
struct stbtt_bakedchar;
class AXText : public Component{
	unsigned char* ttfBuffer; // the file buffer
	stbtt_bakedchar* charData; // char asciis
	SDL_Surface* glyphData; // the whole font data
	std::string path;	
public:
	AXText(const std::string& s);
	void init(std::string& s);
	void draw(float x, float y, char* text);
	Component* clone();
};
#endif