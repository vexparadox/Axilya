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
 * This class handles window creation and event handling, it's the entry point of Axilya.
 */
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
