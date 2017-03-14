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
 * This is a base class for Components that render AXFont data to the window.
 */
#ifndef AXText_hpp
#define AXText_hpp
#include "Component.hpp"
#include <stdio.h>
#include "ResourceManager.hpp"
#include "Entity.hpp"
class AXText {
protected:
	AXFont* font = 0;
	ResourceManager* resourceManager = ResourceManager::getInstance();
   int height, width;
   std::string name;
   Entity* owner = 0;
   AXGraphics::Colour colour;
public:
   /*!
   * A method to sets the owner of this AXText
   * @param e the owner of this AXText
   */
   void setOwner(Entity* e){
      if(e){
         this->owner = e;
      }
   }
   /*!
   * The virtual destructor of this AXText
   */
   virtual ~AXText(){}
   /*!
   * A method to set the font of the AXText
   * @param font the AXFont that will be used to draw the text
   */
	virtual void setFont(AXFont* font) = 0;
   /*!
   * A virtual method to set the font of the AXText
   * @param id the ID of the AXFont (given by the ResourceManager) that will be used to draw the text
   */
	virtual void setFont(int id) = 0;
   /*!
   * A virtual method to bake the text of this AXText to a SDL_Texture
   * @return if the bake was successful 
   */
   virtual bool bakeText() = 0;
   /*!
   * A method to set the Colour of this text
   * @param r the red value of the colour
   * @param g the green value of the colour
   * @param b the blue value of the colour
   * @param a the alpha value of the colour
   */
   void setColour(int r, int g, int b, int a){
      colour.set(r, g, b, a);
   }
      /*!
   * A method to get the name of this AXText
   * @return the name of this AXText
   */  
   std::string getName(){ return this->name; }
	/*!
   * A virtual method to draw the AXText
   * @param x the x position that the text will be drawn at
   * @param y the y position that the text will be drawn at
   */  
	virtual void draw(float x, float y) = 0;

   /*!
   * A virtual method to clone this AXText
   * @return a clone of this AXText
   */  
   virtual AXText* clone() = 0;
};
#endif