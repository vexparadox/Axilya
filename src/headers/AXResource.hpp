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
 * This that describes all AXResources, AXFont, AXTexture and AXAudioChunk.
 */
#ifndef AXResource_hpp
#define AXResource_hpp
#include <string>
#include <iostream>
class AXResource{
protected:
	int id;
	bool loaded = false;
	std::string path;
	AXResource(int id) : id(id){};
public:
	/*!
   * A method to get the ID of this AXResource given by the AXResourceManager
   * @return the ID of the AXResource
   */
	int getID(){ return id; };
	/*!
   * A method to set the loaded path of this AXResource
   */
	void setPath(const std::string s){ this->path = s;}
	/*!
   * A method to get the path of the loaded AXResource
   * @return the path of the loaded AXResource
   */
	std::string getPath(){ return path; }
	/*!
   * A method to check if the AXResource has been loaded
   * @return Whether the AXResouce is loaded
   */
	bool isLoaded(){ return loaded; }
};
#endif
