
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
    keys.push_back(new Key("SPACE", SDL_SCANCODE_SPACE));
    keys.push_back(new Key("A", SDL_SCANCODE_A));
    keys.push_back(new Key("B", SDL_SCANCODE_B));
    keys.push_back(new Key("C", SDL_SCANCODE_C));
    keys.push_back(new Key("D", SDL_SCANCODE_D));
    keys.push_back(new Key("E", SDL_SCANCODE_E));
    keys.push_back(new Key("F", SDL_SCANCODE_F));
    keys.push_back(new Key("G", SDL_SCANCODE_G));
    keys.push_back(new Key("H", SDL_SCANCODE_H));
    keys.push_back(new Key("I", SDL_SCANCODE_I));
    keys.push_back(new Key("J", SDL_SCANCODE_J));
    keys.push_back(new Key("K", SDL_SCANCODE_K));
    keys.push_back(new Key("L", SDL_SCANCODE_L));
    keys.push_back(new Key("M", SDL_SCANCODE_M));
    keys.push_back(new Key("N", SDL_SCANCODE_N));
    keys.push_back(new Key("O", SDL_SCANCODE_O));
    keys.push_back(new Key("P", SDL_SCANCODE_P));
    keys.push_back(new Key("Q", SDL_SCANCODE_Q));
    keys.push_back(new Key("R", SDL_SCANCODE_R));
    keys.push_back(new Key("S", SDL_SCANCODE_S));
    keys.push_back(new Key("T", SDL_SCANCODE_T));
    keys.push_back(new Key("U", SDL_SCANCODE_U));
    keys.push_back(new Key("V", SDL_SCANCODE_V));
    keys.push_back(new Key("W", SDL_SCANCODE_W));
    keys.push_back(new Key("X", SDL_SCANCODE_X));
    keys.push_back(new Key("Y", SDL_SCANCODE_Y));
    keys.push_back(new Key("Z", SDL_SCANCODE_Z));
    keys.push_back(new Key("RIGHT", SDL_SCANCODE_RIGHT));
    keys.push_back(new Key("LEFT", SDL_SCANCODE_LEFT));
    keys.push_back(new Key("DOWN", SDL_SCANCODE_DOWN));
    keys.push_back(new Key("UP", SDL_SCANCODE_UP));
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
