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
        /*!
        * Constructor of Timer
        * @param startNow if the timer should start when it's created
        */
        Timer(bool startNow);
        Timer();
        /*!
        * Starts the timer
        */
        void start();
        /*!
        * Stops the timer
        * @see Timer::elapsedTime()
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
        * Returns the elapsed time
        * If the timer has been stopped it will return between start and stop calls
        * If the timer is still running it will return between start and elapsedTime calls
        * If the timer hasn't been started/has been reset it will return 0
        * @return the elapsed time
        */
        float elapsedTime();
    };
}

#endif /* Timer_hpp */
