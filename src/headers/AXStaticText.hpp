#ifndef AXStaticText_hpp
#define AXStaticText_hpp
#include "AXText.hpp"
class AXStaticText : public AXText{
	std::string& text;
	void bakeText();
	SDL_Texture* texture;
public:
	AXStaticText(const std::string& text, AXFont* font);
	AXStaticText(const std::string& text, int fontID);
	void setText(const std::string& text);
	void setFont(AXFont* font);
	void setFont(int id);
	void draw(float x, float y);
};
#endif