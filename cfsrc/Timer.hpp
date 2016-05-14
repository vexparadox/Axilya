//
//  Timer.hpp
//  Project2
//
//  Created by William Meaton on 26/02/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <stdio.h>
#include <time.h>


namespace Math {
    class Timer{
    private:
        //stores the begin and end time of the timer
        unsigned long beginTime = 0;
        unsigned long endTime = 0;
        
        //bools state the current state of the timer
        bool running = false, started = false;
    public:
        Timer(bool);
        Timer();
        //start the timer, set the begin time
        void start();
        //stop the timer, set the end time
        void stop();
        //reset the timer like brand new
        void reset();
        //returns if it's running
        bool isRunning();
        //returns if the timer has been started before
        bool isStarted();
        
        //returns the elapsed time in seconds
        float elapsedTime();
    };
}

#endif /* Timer_hpp */
