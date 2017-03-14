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
 * It also holds the ID given by the Resource Manager. It's not recomended to use this without the ResourceManager.
 */
#ifndef AXFont_hpp
#define AXFont_hpp
#include <SDL2_ttf/SDL_ttf.h>
#include "AXGraphics.hpp"
#include "AXResource.hpp"
class AXFont : public AXResource{
	bool hasLoaded;
	std::string path;
   TTF_Font* fontData;
   int fontHeight;
public:
	/*!
   * The constructor of an AXFont
   *
   * It's not recommended that you construct your own AXFont, see the ResourceManager.
   * @param id this ID will be given by the ResourceManager when it's created
   */
	AXFont(int id);
   /*!
   * The constructor of an AXFont
   *
   * It's not recommended that you construct your own AXFont as it's more complex to manually render.
   * Use this constructor when not using the ECS
   * @param p the path of the font data
   * @param size the size of the font to load
   */
   AXFont(const std::string& p, int size);
	/*!
   * The destructor of an AXFont
   *
   * This will release the glyph map and character data stored. Do not manually delete resources loaded by the ResourceManger
   */
	~AXFont();
   /*!
   * A method to bake a texture of a string using this AXFont
   *
   * @param string the string to bake
   * @param colour the colour to bake
   * @return the baked texture
   * @see AXGraphics::drawSDLTexture to draw
   */
   SDL_Texture* bakeTexture(const std::string string, AXGraphics::Colour& colour);

   /*!
   * A method to get the pixel size of a baked string using this AXFont
   *
   * @return A 2D Vector that holds (w, h)
   */
   Math::Vector2D getStringSize(const std::string string);
	/*!
   * A method to load a font file
   *
   * If this font is already loaded the previous font data will be overwritten.
   * @param path the path of the .ttf file to be loaded into this AXFont
   * @param size the point size of the font to load
   * @return Whether the font file successfully loaded
   */
	bool loadFont(const std::string& path, int size);
	/*!
   * A method to check if the AXFont has been loaded
   * @return Whether the font is loaded
   */
	bool isLoaded();
   /*!
   * A method to get the font data
   * @return the loaded font data
   */

   TTF_Font* getFontData();
	/*!
   * A method to get the path of the loaded font file
   * @return The path of the loaded font file
   */
	const std::string& getPath();
};
#endif