//
// Created by William Meaton on 01/09/2016.
//

#ifndef Key_h
#define Key_h

#include <string>
#include <iostream>

class Key {
    std::string identifier;
    int keyCode;
    bool pressed;
public:
    Key(const std::string& identifier, int keyCode){
        this->identifier = identifier;
        this->keyCode = keyCode;
        pressed = false;
    }
    void setPressed(bool p){
        this->pressed = p;
    }

    bool getPressed(){
        return this->pressed;
    }

    std::string getIdentifier(){
        return this->identifier;
    }

    const int getKeyCode(){
        return this->keyCode;
    }
};


#endif //CLOSEDFRAMEWORKS_KEY_H
