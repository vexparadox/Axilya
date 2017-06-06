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
 * This class describes methods for playing Audio in Axilya
 */

#ifndef AXAudio_hpp
#define AXAudio_hpp
#include "AXAudioChunk.hpp"
#include <memory>
#ifdef __APPLE__
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif
namespace AXAudio{
   /*!
   * Will play an AXAudioChunk
   * @param chunk an AXAudioChunk
   * @param channel which buffer to play on
   * @param loopNumber how many times to loop
   */
   void playAudioChunk(const AXAudioChunk* chunk, int channel, int loopNumber);
   /*!
   * Will play an AXAudioChunk
   * @param chunk an AXAudioChunk
   * @param loopNumber how many times to loop
   */
   void playAudioChunk(const AXAudioChunk* chunk, int loopNumber);
   /*!
   * Will play an AXAudioChunk
   * @param chunk an AXAudioChunk
   */
   void playAudioChunk(const AXAudioChunk* chunk);

	/*!
   * Will play an AXAudioChunk unique_ptr
   * @param chunk an AXAudioChunk unqiue_ptr
   * @param channel which buffer to play on
   * @param loopNumber how many times to loop
   */
	void playAudioChunk(const std::unique_ptr<AXAudioChunk>& chunk, int channel, int loopNumber);
	/*!
   * Will play an AXAudioChunk unique_ptr
   * @param chunk an AXAudioChunk unqiue_ptr
   * @param channel which buffer to play on
   */
	void playAudioChunk(const std::unique_ptr<AXAudioChunk>& chunk, int channel);
	/*!
   * Will play an AXAudioChunk unique_ptr
   * @param chunk an AXAudioChunk unqiue_ptr
   */
	void playAudioChunk(const std::unique_ptr<AXAudioChunk>& chunk);
};

#endif