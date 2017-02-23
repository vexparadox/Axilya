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
 * This class allows users to get access to the state of input devices like the mouse, keyboard and game controllers.
 */
#ifndef Input_hpp
#define Input_hpp

#include <vector>
#include <unordered_map>
#include "Key.h"
#include <SDL2/SDL.h>
#define AX_INPUT_CONTROLLER_OFFSET 300
#define AX_INPUT_CONTROLLER_AXIS_OFFSET 20
class Input{
    Input(){};
    ~Input(){};
    static std::unordered_map<int, Key*> inputCodes;
    static std::unordered_map<std::string, Key*> inputNames;
    static std::vector<Key*> inputs;
    
    static int inputsPressed, mouseButtonsPressed;
    public:
    static SDL_GameController* controllers[4];
    static bool keyIsPressed, mouseIsPressed;
    static int keyCode, mouseButton;
    static int mouseX, mouseY;
    static void init();
    static void setKeyDown(int key);
    static void setAxisValue(int key, int value);
    static void setKeyUp(int key);
    static void mousePressed(int button);
    static void mouseReleased(int button);
    static int keyUp();
    static int keyDown();
    static int keyRight();
    static int keyLeft();
    static int numControllers();
    static int getValue(const std::string& key);
};

#endif
