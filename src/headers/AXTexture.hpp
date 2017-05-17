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
 * This is used to hold image data loaded from a file.
 */
#ifndef AXTexture_hpp
#define AXTexture_hpp
#include "AXResource.hpp"
#include <SDL2/SDL.h>
#include "AXMath.hpp"
class AXTexture : public AXResource{
  SDL_Texture* texture;
  unsigned char* imageDataPtr = 0;
  int w = 0, h = 0;
public:
	/*!
   * The constructor of an AXTexture 
   * @param id the ID provided when created by the AXResourceManager
   * @param path the path of the image file to load
   */  
    AXTexture(int id, const std::string& path);
    /*!
   * The constructor of an AXTexture 
   *
   * This constructor is for internal use only
   * @param texture the SDL_Texture to be drawn
   */  
    AXTexture(SDL_Texture* texture);
  /*!
   * The constructor of an AXTexture 
   * 
   * The id parameter is only used with the AXResourceManager
   * @param path the path of the image file to load
   */  
    AXTexture(const std::string& path);
  /*!
   * The constructor of an AXTexture 
   * 
   * Used for building an empty AXTexture, use loadImage
   */  
    AXTexture();
    /*!
   * The deconstructor of an AXTexture 
   * 
   * This will free the texture data, do not manually delete resources loaded by the ResourceManger
   */  
    ~AXTexture();
  /*!
   * A method to load image data from a file into this AXTexture
   * 
   * This will free any already exsisting texture data
   * @return if the load was successful
   */ 
    bool loadImage(const std::string& path);
  /*!
   * A method to get the width of the AXTexture
   * @return the width of the loaded texture
   */  
    int getWidth();
  /*!
   * A method to get the height of the AXTexture
   * @return the height of the loaded texture
   */  
    int getHeight();
    /*!
   * A method to get the texture data that's been loaded
   * @return The texture data that's been loaded
   */     
    SDL_Texture* getTextureData();
    /*!
   * A method to get the raw pixel data that's been loaded
   *
   * This is not "live" data, this is just for observations. 
   * To write changes to texture, make changes to the pixel data and clone this AXTexture, that will regenerate the SDL_Texture
   * @return The raw pixel data that's been loaded
   */  
    unsigned char* getRawPixelData();
    /*!
    * A method to clone this AXTexture
    * @return a clone of this AXTexture
    */
    AXTexture* clone();
};
#endif