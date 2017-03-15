//
//  AXTimer.cpp
//  Project2
//
//  Created by William Meaton on 26/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "headers/AXTimer.hpp"
namespace Math{
    AXTimer::AXTimer(bool startNow) : beginTime(0), endTime(0), started(false), running(false) {
        if(startNow){
            this->start();
        }
    }
    AXTimer::AXTimer() : beginTime(0), endTime(0), started(false), running(false){
        
    }
    void AXTimer::start(){
        beginTime = clock();
        started = true;
        running = true;
    }
    void AXTimer::stop(){
        endTime = clock();
        running = false;
    }
    void AXTimer::reset(){
        running = false;
        started = false;
        beginTime = 0;
        endTime = 0;
    }

    float AXTimer::elapsedTime(){
        if(running){
            return ((float) clock() - beginTime)/CLOCKS_PER_SEC;
        }
        if(!started){
            return 0;
        }
        return ((float) endTime - beginTime)/CLOCKS_PER_SEC;
    }
    bool AXTimer::isRunning(){
        return running;
    }
    
    bool AXTimer::isStarted(){
        return started;
    }
}
