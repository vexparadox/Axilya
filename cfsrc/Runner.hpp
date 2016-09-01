//
//  Runner.hpp
//  GLFW3
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
    bool fps(int framerate);
public:
    //the RGBA of the next screen flush IE the background
    static float r, g, b, a;
    //the creation of the runner
    
    /*!
    * Constructor of the Runner
    * The runner class encompasses the entire program
    * It controls the game loop and key, mouse and cursor callbacks
    */
    Runner(float windowWidth, float windowHeight, int frameRate, const char* title, BaseCore* c);
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
    static void errorCallback(int error, const char* description);
    /*!
    * Called when GLFW detects a key input
    * This data is passed into the Input class
    * @see Input class 
    */
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    /*!
    * Called when GLFW detects MouseButton input
    * This data is passed into the Input class
    * @see Input class 
    */
    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
    /*!
    * Called when GLFW detects mouse movement
    * This data is passed into the Input class
    * @see Input class 
    */
    static void cursorCallback(GLFWwindow* window, double xpos, double ypos);
};

#endif /* Runner_hpp */