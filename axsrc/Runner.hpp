//
//  Runner.hpp
//  Axilya
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp
#include <vector>
#include "BaseCore.hpp"
#include "Scene.hpp"
#include "Input.hpp"
//this class controls the main game loop, calls BaseCore update and render
class Runner{
    static BaseCore* c;
    double currentTime, lastTime;
    static Scene* activeScene;
    static int go;
public:
    static std::string runPath;
    //the RGBA of the next screen flush IE the background
    static float r, g, b, a;
    //the creation of the runner
    
    /*!
    * Constructor of the Runner
    * The runner class encompasses the entire program
    * It controls the game loop and key, mouse and cursor callbacks
    */
    Runner(float windowWidth, float windowHeight, const char* title, BaseCore* c);
    ~Runner(){};
    //get window size
    
    /*!
    * Returns the window width
    * @return window width 
    */
    static int getWidth();
    
    /*!
    * Returns the window height
    * @return window height 
    */
    static int getHeight();
    //event call backs
    /*!
    * Called when GLFW errors 
    */
    static void setCurrentScene(Scene* s);
    static void shutdown();
};

#endif /* Runner_hpp */