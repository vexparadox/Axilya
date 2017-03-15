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
#include "AXAudioChunk.hpp"
#include <vector>
#include <unordered_map>
class AXResourceManager{
    AXResourceManager(){}
    std::vector<AXTexture*> textures;
    std::vector<AXFont*> fonts;
    std::vector<AXAudioChunk*> chunks;
    std::unordered_map<std::string, AXTexture*> textureMap;
    std::unordered_map<std::string, AXAudioChunk*> audioMap;
    std::unordered_map<std::string, AXFont*> fontMap;
    static AXResourceManager* instance;
    ~AXResourceManager();
public:
    /*!
    * A method to get the singleton instance of this AXResourceManager
    * 
    * @return the instance of this singleton
    */
    static AXResourceManager* getInstance();
    /*!
    * A method to load in an AXTexture from an image file
    * 
    * @param path the path of the image file to load (auto prefixed with runpath+"data/")
    * @return the resourceID of the new AXTexture or -1 on failure
    */
    int addTexture(const std::string& path);
    /*!
    * A method to load in an AXFont from an font file (.ttf)
    * 
    * @param path the path of the font file to load (auto prefixed with runpath+"data/")
    * @return the resourceID of the new AXFont or -1 on failure
    */
    int addFont(const std::string& path, int size);
    /*!
    * A method to load in an AXAudioChunk from an audio file (.wav etc)
    * 
    * @param path the path of the audio file to load (auto prefixed with runpath+"data/")
    * @return the resourceID of the new AXFont or -1 on failure
    */
    int addAudioChunk(const std::string&);
    /*!
    * A method to check if the image file at @p path has been loaded already
    * 
    * @param path the path of the image file to check (auto prefixed with runpath+"data/")
    * @return if the image file has been loaded
    */
    bool isTextureLoaded(const std::string& path);
    /*!
    * A method to check if the font file at @p path has been loaded already
    * 
    * @param path the path of the font file to check (auto prefixed with runpath+"data/")
    * @return if the font file has been loaded
    */
    bool isFontLoaded(const std::string& path);
    /*!
    * A method to check if the audio file at @p path has been loaded already
    * 
    * @param path the path of the audio file to check (auto prefixed with runpath+"data/")
    * @return if the audio file has been loaded
    */
    bool isAudioChunkLoaded(const std::string& path);
    /*!
    * A method to get the AXFont with the given id
    * 
    * @param id the id of the AXFont to get
    * @return the AXFont that's loaded or nullptr
    * @see AXResourceManager::addFont()
    */
    AXFont* getFont(int id);
    /*!
    * A method to get the AXFont with the original path
    * 
    * This is mainly used interally, use the id version of this method instead
    * @param path the path of the font file to get (auto prefixed with runpath+"data/")
    * @return the AXFont that's loaded or nullptr
    */
    AXFont* getFont(const std::string& path);
    /*!
    * A method to get the AXTexture with the given id
    * @param id the id of the AXTexture loaded (auto prefixed with runpath+"data/")
    * @return the AXTexture that's loaded or nullptr
    * @see AXResourceManager::addTexture()
    */
    AXTexture* getTexture(int id);
    /*!
    * A method to get the AXTexture with the original path
    * 
    * This is mainly used interally, use the id version of this method instead
    * @param path the path of the image file to get (auto prefixed with runpath+"data/")
    * @return the AXTexture that's loaded or nullptr
    */
    AXTexture* getTexture(const std::string& path);
    /*!
    * A method to get the AXAudioChunk with the given id
    * 
    * @param id the id of the AXAudioChunk to get
    * @return the AXAudioChunk that's loaded or nullptr
    * @see AXResourceManager::addAudioChunk()
    */
    AXAudioChunk* getAudioChunk(int id);
    /*!
    * A method to get the AXAudioChunk with the original path
    * 
    * This is mainly used interally, use the id version of this method instead
    * @param path the path of the audio file to get (auto prefixed with runpath+"data/")
    * @return the AXAudioChunk that's loaded or nullptr
    */
    AXAudioChunk* getAudioChunk(const std::string& path);
};

#endif
