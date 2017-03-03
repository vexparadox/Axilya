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
 * This class describes an AXStaticText object, this is a Component used to render text to the screen.
 * It uses font data from the AXFont class.
 */
#ifndef AXStaticText_hpp
#define AXStaticText_hpp
#include "AXText.hpp"
class AXStaticText : public AXText{
	std::string text;
	SDL_Texture* texture;
	bool isBaked;
public:    
	/*!
   * The constructor of an AXStaticText
   *
   * This method will bake the string you provide, this makes it fast to draw but slow to update.
   * @param text the text that will be drawn
   * @param font the AXFont that will be used to draw the text
   */    
	AXStaticText(const std::string& name, const std::string& text, AXFont* font);
	/*!
   * The constructor of an AXStaticText
   *
   * This method will bake the string you provide, this makes it fast to draw but slow to update.
   * @param text the text that will be drawn
   * @param id the ID of the AXFont (given by the ResourceManager) that will be used to draw the text
   */    
	AXStaticText(const std::string& name, const std::string& text, int fontID);
	/*!
   * A method to update the text this AXStaticText will draw
   *
   * This method will re-bake the string you provide, this makes it fast to draw but slow to use every frame.
   * @param text the text that will be drawn
   */    
   void setText(const std::string& text);

   /*!
   * A method to update the Texture that's drawn by this font
   */    
   bool bakeText();

	/*!
   * A method to update the AXFont this AXStaticText will use to draw
   *
   * This method will re-bake the string you have set.
   * @param font the AXFont that will be used to draw the text
   */  
	void setFont(AXFont* font);
	/*!
   * A method to update the AXFont this AXStaticText will use to draw
   *
   * This method will re-bake the string you have set.
   * @param id the ID of the AXFont (given by the ResourceManager) that will be used to draw the text
   */  
	void setFont(int id);
	/*!
   * A method to draw the AXStaticText
   * @param x the x position that the text will be drawn at
   * @param y the y position that the text will be drawn at
   */  
	void draw(float x, float y);
   /*!
   * A method to clone this AXText
   * @return a clone of this AXStaticText
   */
	AXText* clone();
};
#endif