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
 * This class describes a AXAudioPlayer, it holds the AXAudioChunks attached to an AXEntity, use this for ECS audio playing
 */
#ifndef AXAudioPlayer_hpp
#define AXAudioPlayer_hpp

#include "AXComponent.hpp"
#include <unordered_map>
#include "AXAudio.hpp"

class AXAudioPlayer : public AXComponent{
	std::unordered_map<std::string, AXAudioChunk*> chunks;
public:
    /*!
    * A method to add an AXAudioChunk to this AXAudioPlayer
    * @param chunkID the ID of the AXAudioChunk loaded in by the AXResourceManager
    */
	void addAudioChunk(int chunkID);
    /*!
    * A method to play an AXAudioChunk already added to this AXAudioPlayer using the name given
    * 
    * @param name the name of the AXAudioChunk to play
    */
	void playAudioChunk(const std::string& name);
    /*!
    * A method to play an AXAudioChunk already added to this AXAudioPlayer using the name given
    * 
    * @param name the name of the AXAudioChunk to play
    * @param channel the audio channel to play this on, -1 for auto
    * @param times how many times to play this chunk, 0 for once, -1 for infinite loop
    */
	void playAudioChunk(const std::string& name, int channel, int times);
    /*!
    * A method to clone this AXComponent
    * 
    * @return a clone of this AXAudioPlayer
    */
	AXComponent* clone();
};

#endif