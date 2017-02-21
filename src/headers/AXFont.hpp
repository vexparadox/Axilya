#ifndef AXFont_hpp
#define AXFont_hpp
#include "AXWindow.hpp"
struct stbtt_bakedchar;
class AXFont{
	bool hasLoaded;
	std::string path, name;
	SDL_Surface* surface;
	stbtt_bakedchar* charData;
	int id;
	static const int charDataSize;
public:
	AXFont(int id);
	~AXFont();
	bool loadFont(const std::string& path);
	bool isLoaded();
	const std::string& getPath();
	SDL_Surface* getSurface();
	void draw(float x, float y, char* text);
	int getID();
};
#endif