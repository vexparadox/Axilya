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
* This class describes a AXTimer, it allows you to get the elapsed time between two points.
*/
#ifndef AXTimer_hpp
#define AXTimer_hpp

#include <iostream>
#include <SDL2/SDL.h>
class AXTimer{
private:
    //stores the begin and end time of the timer
    Uint32 beginTime;
    Uint32 endTime;
    //bools state the current state of the timer
    bool running, started;
public:
    /*!
    * Constructor of AXTimer
    * @param startNow if the timer should start when it's created
    */
    AXTimer(bool startNow);
    AXTimer();
    /*!
    * Starts the timer
    */
    void start();
    /*!
    * Stops the timer
    * @see AXTimer::elapsedTime()
    */
    void stop();
    /*!
    * Resets the timer
    * Takes the timer back to as if it were just created
    */       
    void reset();
    /*!
    * Returns if the timer is running
    * @return current state of timer
    */
    bool isRunning();
    /*!
    * Returns if the timer has been started
    * @return start state of the timer
    */
    bool isStarted();
    
    /*!
    * Returns the elapsed time in milliseconds.
    *
    * If the timer has been stopped it will return between start and stop calls
    *
    * If the timer is still running it will return between start and elapsedTime calls
    *
    * If the timer hasn't been started/has been reset it will return 0
    * @return the elapsed time in milliseconds
    */
    Uint32 elapsedTime();
};
#endif /* Timer_hpp */
