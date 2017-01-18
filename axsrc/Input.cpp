
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
SDL_GameController* Input::controller = 0;
std::vector<Key*> Input::keys;
std::unordered_map<int, Key*> Input::keyCodes;
std::unordered_map<std::string, Key*> Input::keyNames;

void Input::init() {
    keys.reserve(45);
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
    keys.push_back(new Key("1", SDL_SCANCODE_1));
    keys.push_back(new Key("2", SDL_SCANCODE_2));
    keys.push_back(new Key("3", SDL_SCANCODE_3));
    keys.push_back(new Key("4", SDL_SCANCODE_4));
    keys.push_back(new Key("5", SDL_SCANCODE_5));
    keys.push_back(new Key("6", SDL_SCANCODE_6));
    keys.push_back(new Key("7", SDL_SCANCODE_7));
    keys.push_back(new Key("8", SDL_SCANCODE_8));
    keys.push_back(new Key("9", SDL_SCANCODE_9));
    keys.push_back(new Key("0", SDL_SCANCODE_0));
    keys.push_back(new Key("RIGHT", SDL_SCANCODE_RIGHT));
    keys.push_back(new Key("LEFT", SDL_SCANCODE_LEFT));
    keys.push_back(new Key("DOWN", SDL_SCANCODE_DOWN));
    keys.push_back(new Key("UP", SDL_SCANCODE_UP));
    keys.push_back(new Key("ENTER", SDL_SCANCODE_RETURN));
    keys.push_back(new Key("TAB", SDL_SCANCODE_TAB));
    keys.push_back(new Key("LCTRL", SDL_SCANCODE_LCTRL));
    keys.push_back(new Key("LSHIFT", SDL_SCANCODE_LSHIFT));
    keys.push_back(new Key("LALT", SDL_SCANCODE_LALT));
    keys.push_back(new Key("RCTRL", SDL_SCANCODE_RCTRL));
    keys.push_back(new Key("RALT", SDL_SCANCODE_RALT));
    keys.push_back(new Key("RSHIFT", SDL_SCANCODE_RSHIFT));

    keys.push_back(new Key("GC_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET));
    keys.push_back(new Key("GC_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET));

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
