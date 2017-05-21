//
//  AXTimer.cpp
//  Axilya
//
//  Created by William Meaton on 26/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//
#include "headers/AXTimer.hpp"
AXTimer::AXTimer(bool startNow) : beginTime(0), endTime(0), started(false), running(false) {
    if(startNow){
        this->start();
    }
}
AXTimer::AXTimer() : beginTime(0), endTime(0), started(false), running(false){
    
}
void AXTimer::start(){
    beginTime = SDL_GetTicks();
    started = true;
    running = true;
}
void AXTimer::stop(){
    endTime = SDL_GetTicks();
    running = false;
}
void AXTimer::reset(){
    running = false;
    started = false;
    beginTime = 0;
    endTime = 0;
}

Uint32 AXTimer::elapsedTime(){
    if(running){
        return (Uint32)(SDL_GetTicks() - beginTime);
    }
    if(!started){
        return 0;
    }
    return ((Uint32) endTime - beginTime);
}
bool AXTimer::isRunning(){
    return running;
}

bool AXTimer::isStarted(){
    return started;
}
