//
//  AXWindow.hpp
//  Axilya
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef AXWindow_hpp
#define AXWindow_hpp
#include <vector>
#include "Scene.hpp"
#include "Input.hpp"
#include "WindowTypes.hpp"
using UDFunction = void(*)();
//this class controls the main game loop, calls BaseCore update and render
class AXWindow{
    double currentTime, lastTime;
    static Scene* activeScene;
    static int go;
    static int windowWidth, windowHeight;
    static int displayWidth, displayHeight;
    static SDL_Window* window;
    static UDFunction draw, update;
    static bool initiated;
    AXWindow(){};
    ~AXWindow(){};
public:
    static SDL_Renderer* renderer;
    static std::string runPath;

    //the RGBA of the next screen flush IE the background
    static AXGraphics::Colour backgroundColour;
    static AXGraphics::Colour renderColour;
    
    //the creation of the AXWindow
    static int init(float wWidth, float wHeight, int windowStyle, const char* title);
    static int init(float windowWidth, float windowHeight, int windowType, const char* title, UDFunction update, UDFunction draw);
    static int run();
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
    static void hideCursor(bool);
    static void lockCursor(bool);
    static int getDisplayWidth();
    static int getDisplayHeight();
    static SDL_Window* getWindow();
    static void setCurrentScene(Scene* s);
    static void shutdown();
};

#endif /* AXWindow_hpp */
