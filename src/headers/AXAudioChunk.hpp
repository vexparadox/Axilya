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
 * This class describes an AXAudioChunk, this holds loaded audio data.
 */
#ifndef AXAudioChunk_hpp
#define AXAudioChunk_hpp
#include "AXResource.hpp"
#ifdef __APPLE__
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif
class AXAudioChunk : public AXResource{
	Mix_Chunk* chunk;
    AXAudioChunk() : AXResource(-1) {};
public:
    /*!    
    * The constructor for an AXAudioChunk
    *
    * It's not reccomended you construct your own AXAudioChunk object, see the AXResourceManager
    * @param id the id given by the AXResourceManager
    * @param path the path of the audio file to load
    */
	AXAudioChunk(int id, const std::string& path);
    /*!    
    * The constructor for an AXAudioChunk
    *
    * It's not reccomended you construct your own AXAudioChunk object, see the AXResourceManager. 
    * This constructor is reccomended when you're not using the ECS system.
    * @param path the path of the audio file to load
    */
	AXAudioChunk(const std::string& path);
    /*!    
    * The deconstructor for an AXAudioChunk
    *
    * This will release the audio data loaded. 
    */
    ~AXAudioChunk();
    /*!    
    * A method to load an audio file into this AXAudioChunk
    *
    * Any previous data loaded will be released
    *
    * This function can load WAV, AIFF, RIFF, OGG, and VOC files (provided the host has the appropriate libraries)
    * @param path the path of the audio file to load
    * @return if the load was successful or not
    */
	bool loadAudio(const std::string& path);
    /*!    
    * A method to set the volume of this AXAudioChunk
    *
    * @param volume the volume of this AXAudioChunk
    * @return the previous volume level or -1 if not loaded
    */
	int setVolume(int volume);
    /*!    
    * A method to get the audio data of this AXAudioChunk
    *
    * @return the audio data that's been loaded
    * @see AXAudio::playAudioChunk
    */
    Mix_Chunk* getAudioData();
    /*!
    * A method to clone this AXAudioChunk
    * @return a clone of this AXAudioChunk
    */
    AXAudioChunk* clone();
};

#endif