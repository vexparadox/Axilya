//
//  Timer.cpp
//  Project2
//
//  Created by William Meaton on 26/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/Timer.hpp"
namespace Math{
    Timer::Timer(bool startNow) : beginTime(0), endTime(0), started(false), running(false) {
        if(startNow){
            this->start();
        }
    }
    Timer::Timer() : beginTime(0), endTime(0), started(false), running(false){
        
    }
    void Timer::start(){
        beginTime = clock();
        started = true;
        running = true;
    }
    void Timer::stop(){
        endTime = clock();
        running = false;
    }
    void Timer::reset(){
        running = false;
        started = false;
        beginTime = 0;
        endTime = 0;
    }

    float Timer::elapsedTime(){
        if(running){
            return ((float) clock() - beginTime)/CLOCKS_PER_SEC;
        }
        if(!started){
            return 0;
        }
        return ((float) endTime - beginTime)/CLOCKS_PER_SEC;
    }
    bool Timer::isRunning(){
        return running;
    }
    
    bool Timer::isStarted(){
        return started;
    }
}
