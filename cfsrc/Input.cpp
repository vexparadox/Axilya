
#include <iostream>
#include "Input.hpp"

bool Input::keyIsPressed = false;
bool Input::mouseIsPressed = false;
int Input::keyCode = 0;
int Input::mouseButton = -1;
int Input::mouseX = 0;
int Input::mouseY = 0;
int Input::keysPressed = 0;
int Input::mouseButtonsPressed = 0;
std::vector<Key*> Input::keys;
std::unordered_map<int, Key*> Input::keyCodes;
std::unordered_map<std::string, Key*> Input::keyNames;

void Input::init() {
    keys.reserve(31);
    keys.push_back(new Key("SPACE", 32));
    keys.push_back(new Key("A", 65));
    keys.push_back(new Key("B", 66));
    keys.push_back(new Key("C", 67));
    keys.push_back(new Key("D", 68));
    keys.push_back(new Key("E", 69));
    keys.push_back(new Key("F", 70));
    keys.push_back(new Key("G", 71));
    keys.push_back(new Key("H", 72));
    keys.push_back(new Key("I", 73));
    keys.push_back(new Key("J", 74));
    keys.push_back(new Key("K", 75));
    keys.push_back(new Key("L", 76));
    keys.push_back(new Key("M", 77));
    keys.push_back(new Key("N", 78));
    keys.push_back(new Key("O", 79));
    keys.push_back(new Key("P", 80));
    keys.push_back(new Key("Q", 81));
    keys.push_back(new Key("R", 82));
    keys.push_back(new Key("S", 83));
    keys.push_back(new Key("T", 84));
    keys.push_back(new Key("U", 85));
    keys.push_back(new Key("V", 86));
    keys.push_back(new Key("W", 87));
    keys.push_back(new Key("X", 88));
    keys.push_back(new Key("Y", 89));
    keys.push_back(new Key("Z", 90));
    keys.push_back(new Key("RIGHT", 262));
    keys.push_back(new Key("LEFT", 263));
    keys.push_back(new Key("DOWN", 264));
    keys.push_back(new Key("UP", 265));
    keyCodes.reserve(keys.size());
    keyNames.reserve(keys.size());
    //loop through and add the keys to the maps
    for(auto it = keys.begin(); it != keys.end(); it++){
        keyCodes.insert(std::pair<int, Key*>((*it)->getKeyCode(), (*it)));
        keyNames.insert(std::pair<std::string, Key*>((*it)->getIdentifier(), (*it)));
    }
    keys.clear();
}


void Input::mousePressed(int button){
    mouseButton = button;
    mouseIsPressed = true;
    mouseButtonsPressed++;
}

void Input::mouseReleased(int button){
    mouseButtonsPressed--;
    if(mouseButtonsPressed < 1){
        mouseIsPressed = false;
        mouseButton = -1;
    }
}

void Input::setKeyDown(int key){
    keyCode = key;
    keysPressed++;
    keyIsPressed = true;
    if(keyCodes.find(key) != keyCodes.end()){
        keyCodes.at(key)->setPressed(true);
    }
}
void Input::setKeyUp(int key){
    keysPressed++;
    if(keyCodes.find(key) != keyCodes.end()){
        keyCodes.at(key)->setPressed(false);
    }
    if(keysPressed < 1){
        keyIsPressed = false;
        keyCode = -1;
    }
}

bool Input::getKey(const std::string& key){
    if(keyNames.find(key) != keyNames.end()){
        return keyNames.at(key)->getPressed();
    }
    return false;
}

bool Input::getKey(int key) {
    if (keyCodes.find(key) != keyCodes.end()) {
        return keyCodes.at(key)->getPressed();
    }
    return false;
}

bool Input::keyUp(){
    return getKey("UP");
}
bool Input::keyDown(){
    return getKey("DOWN");
}
bool Input::keyRight(){
    return getKey("RIGHT");
}
bool Input::keyLeft(){
    return getKey("LEFT");
}
