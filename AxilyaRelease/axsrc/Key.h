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
    int value;
public:
    Key(const std::string& identifier, int keyCode){
        this->identifier = identifier;
        this->keyCode = keyCode;
        this->value = 0;
    }
    void setValue(int v){
        this->value = v;
    }

    int getValue(){
        return this->value;
    }

    std::string getIdentifier(){
        return this->identifier;
    }

    const int getKeyCode(){
        return this->keyCode;
    }
};


#endif //Axilya_KEY_H
