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
 * This class manages resources like textures, fonts and sound files. It handles loading and destruction.
 */
#ifndef AXResourceManager_h
#define AXResourceManager_h

#include "AXTexture.hpp"
#include "AXFont.hpp"
#include <vector>
#include <unordered_map>
class AXTexture;
class AXFont;
class AXResourceManager{
    AXResourceManager(){}
    std::vector<AXTexture*> textures;
    std::vector<AXFont*> fonts;
    std::unordered_map<std::string, AXTexture*> textureMap;
    std::unordered_map<std::string, AXFont*> fontMap;
    static AXResourceManager* instance;
    ~AXResourceManager();
public:
    static AXResourceManager* getInstance();
    //add a new AXTexture, will return -1 or new id
    int addTexture(const std::string&);
    int addFont(const std::string&, int size);
    bool isTextureLoaded(const std::string&);
    bool isFontLoaded(const std::string&);
    AXFont* getFont(int);
    AXFont* getFont(const std::string&);
    AXTexture* getTexture(int);
    AXTexture* getTexture(const std::string&);
};

#endif
