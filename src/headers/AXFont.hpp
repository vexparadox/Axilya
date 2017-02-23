/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This class is used to hold font data and the instructions to load from TTF files.
 * It also holds the ID given by the Resource Manager. It's not recomended to use this without the RM.
 */
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
	stbtt_bakedchar* getCharData();
	int getID();
};
#endif