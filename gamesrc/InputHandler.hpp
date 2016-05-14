//
//  InputHandler.hpp
//  Project2
//
//  Created by William Meaton on 31/12/2015.
//
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <stdio.h>
#include <memory>
#include <iostream>

//this class handles keyboard input with predefined buttons
class InputHandler{
    
    //the one static instance of this class
    static std::shared_ptr<InputHandler> instance;
    
    InputHandler(InputHandler const &s){}; // no copy constructor
    //booleans for keys being used
    bool Q = false, I = false, E = false, UP = false, LEFT = false, RIGHT = false, DOWN = false, isKeyPressed = false, SPACE = false, MOUSE0 = false, MOUSE1 = false, isMousePressed = false;
    
    //holds the mouseX and mouseY
    int mouseX = 0, mouseY = 0;
public:
    InputHandler(){};
    //returns the singleton instance
    static std::shared_ptr<InputHandler> getInstance();
    
    //Setters for all the booleans and stored info
    //takes mouse input and sets mouseX and mouseY
    void mouseInput(int x, int y);
    //takes mouseDown and sets buttons
    void mouseDown(int button);
    //takes MouseUp and sets buttons
    void mouseUp(int button);
    //takes keyup and sets keys
    void keyUp(int key);
    //takes keydown and sets keys
    void keyDown(int key);    
    //Getters for all the booleans and stored info
    bool getUP();
    bool getLEFT();
    bool getRIGHT();
    bool getDOWN();
    bool getisKeyPressed();
    bool getisMousePressed();
    bool getSPACE();
    bool getMOUSE0();
    bool getMOUSE1();
    bool getQ();
    bool getE();
    bool getI();
    //returns the mouseX
    int getMouseX();
    //returns the mouseY
    int getMouseY();
};
#endif /* Keyboard_hpp */