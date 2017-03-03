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
#include "AXNetwork.hpp"
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
typedef void (*AXFunction)();
//this class controls the main game loop, calls BaseCore update and render
class AXWindow{
    double currentTime, lastTime;
    static Scene* activeScene;
    static int go;
    static int windowWidth, windowHeight;
    static int displayWidth, displayHeight;
    static SDL_Window* window;
    static AXFunction draw, update;
    static bool initiated;
    AXWindow(){};
    ~AXWindow(){};
public:
    /*!    
    * the runpath of the Axilya application
    */
    static std::string runPath;
    /*!    
    * A static SDL_Renderer that is used to draw throughout Axilya
    */
    static SDL_Renderer* renderer;
    /*!
    * A static Colour variable that defines the background colour of the AXWindow
    * @see AXGraphics::setBackground()
    */
    static AXGraphics::Colour backgroundColour;
    /*!
    * A static Colour variable that defines the colour that shapes will be rendered in
    * @see AXGraphics::fill()
    */
    static AXGraphics::Colour renderColour;
    
    /*!
    * A static method initialise the AXWindow
    *
    * The AXWindow is the back bone of Axilya, you need to initialise everything before using the run method.
    * @param windowWidth the requested width of the window
    * @param windowHeight the requested height of the window
    * @param windowStyle the style of the window, can be AX_WINDOWED or AX_FULLSCREEN
    * @param title the title that's shown in the top bar of the window
    * @return Returns 1 on success and -1 on failure
    */
    static int init(float windowWidth, float windowHeight, int windowStyle, const char* title);
    /*!
    * A static method initialise the AXWindow
    *
    * The AXWindow is the back bone of Axilya, you need to initialise everything before using the run method.
    * @param windowWidth the requested width of the window
    * @param windowHeight the requested height of the window
    * @param windowStyle the style of the window, can be AX_WINDOWED or AX_FULLSCREEN
    * @param title the title that's shown in the top bar of the window
    * @param update the function pointer to an update method, this will be called in the game loop along side the current Scene being updated
    * @param draw the function pointer to an draw method, this will be called in the game loop along side the current Scene being updated
    * @return Returns 1 on success and -1 on failure
    */
    static int init(float windowWidth, float windowHeight, int windowType, const char* title, AXFunction update, AXFunction draw);
    /*!
    * A static method to start and maintain the game loop
    *
    * This method should be returned by your `int main()` method. It will update the set Scene and draw the AXWindow.  
    * @return Will return 0 on a successfull game loop when AXWindow::shutdown() is called
    */
    static int run();
    /*!
    * A static method to get the window width
    * @return The window width 
    */
    static int getWidth();
    /*!
    * A static method to get the window height
    * @return The window height 
    */
    static int getHeight();
    /*!
    * A static method to set if the cursor should be hidden or not
    * @param value if the cursor should be hidden or not 
    */
    static void hideCursor(bool value);
    /*!
    * A static method to set if the cursor should be locked to the AXWindow bounds or not
    * @param value if the cursor should be locked or not 
    */
    static void lockCursor(bool value);
    /*!
    * A static method to get the current display width
    * @return The current display width 
    */
    static int getDisplayWidth();
    /*!
    * A static method to get the current display height
    * @return The current display height 
    */
    static int getDisplayHeight();
    /*!
    * A static method to get the SDL_Window 
    * @return The SDL_Window
    */
    static SDL_Window* getWindow();
    /*!
    * A static method to set the current Scene that should be drawn and updated 
    * @param s the scene that should be updated and drawn
    */
    static void setCurrentScene(Scene* s);
    /*!
    * A static method to safely shut down the AXWindow's game loop
    * 
    * This releases all resources and makes AXWindow::run() return 0.
    * Note that this method will only release the current set Scene
    */
    static void shutdown();
};

#endif /* AXWindow_hpp */
