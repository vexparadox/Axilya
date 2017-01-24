#include <iostream>
#include "Input.hpp"

bool Input::keyIsPressed = false;
bool Input::mouseIsPressed = false;
int Input::keyCode = 0;
int Input::mouseButton = -1;
int Input::mouseX = 0;
int Input::mouseY = 0;
int Input::inputsPressed = 0;
int Input::mouseButtonsPressed = 0;
SDL_GameController* Input::controllers[4];
std::vector<Key*> Input::inputs;
std::unordered_map<int, Key*> Input::inputCodes;
std::unordered_map<std::string, Key*> Input::inputNames;

void Input::init() {
    inputs.reserve(111);
    inputs.push_back(new Key("SPACE", SDL_SCANCODE_SPACE));
    inputs.push_back(new Key("A", SDL_SCANCODE_A));
    inputs.push_back(new Key("B", SDL_SCANCODE_B));
    inputs.push_back(new Key("C", SDL_SCANCODE_C));
    inputs.push_back(new Key("D", SDL_SCANCODE_D));
    inputs.push_back(new Key("E", SDL_SCANCODE_E));
    inputs.push_back(new Key("F", SDL_SCANCODE_F));
    inputs.push_back(new Key("G", SDL_SCANCODE_G));
    inputs.push_back(new Key("H", SDL_SCANCODE_H));
    inputs.push_back(new Key("I", SDL_SCANCODE_I));
    inputs.push_back(new Key("J", SDL_SCANCODE_J));
    inputs.push_back(new Key("K", SDL_SCANCODE_K));
    inputs.push_back(new Key("L", SDL_SCANCODE_L));
    inputs.push_back(new Key("M", SDL_SCANCODE_M));
    inputs.push_back(new Key("N", SDL_SCANCODE_N));
    inputs.push_back(new Key("O", SDL_SCANCODE_O));
    inputs.push_back(new Key("P", SDL_SCANCODE_P));
    inputs.push_back(new Key("Q", SDL_SCANCODE_Q));
    inputs.push_back(new Key("R", SDL_SCANCODE_R));
    inputs.push_back(new Key("S", SDL_SCANCODE_S));
    inputs.push_back(new Key("T", SDL_SCANCODE_T));
    inputs.push_back(new Key("U", SDL_SCANCODE_U));
    inputs.push_back(new Key("V", SDL_SCANCODE_V));
    inputs.push_back(new Key("W", SDL_SCANCODE_W));
    inputs.push_back(new Key("X", SDL_SCANCODE_X));
    inputs.push_back(new Key("Y", SDL_SCANCODE_Y));
    inputs.push_back(new Key("Z", SDL_SCANCODE_Z));
    inputs.push_back(new Key("1", SDL_SCANCODE_1));
    inputs.push_back(new Key("2", SDL_SCANCODE_2));
    inputs.push_back(new Key("3", SDL_SCANCODE_3));
    inputs.push_back(new Key("4", SDL_SCANCODE_4));
    inputs.push_back(new Key("5", SDL_SCANCODE_5));
    inputs.push_back(new Key("6", SDL_SCANCODE_6));
    inputs.push_back(new Key("7", SDL_SCANCODE_7));
    inputs.push_back(new Key("8", SDL_SCANCODE_8));
    inputs.push_back(new Key("9", SDL_SCANCODE_9));
    inputs.push_back(new Key("0", SDL_SCANCODE_0));
    inputs.push_back(new Key("RIGHT", SDL_SCANCODE_RIGHT));
    inputs.push_back(new Key("LEFT", SDL_SCANCODE_LEFT));
    inputs.push_back(new Key("DOWN", SDL_SCANCODE_DOWN));
    inputs.push_back(new Key("UP", SDL_SCANCODE_UP));
    inputs.push_back(new Key("ENTER", SDL_SCANCODE_RETURN));
    inputs.push_back(new Key("TAB", SDL_SCANCODE_TAB));
    inputs.push_back(new Key("LCTRL", SDL_SCANCODE_LCTRL));
    inputs.push_back(new Key("LSHIFT", SDL_SCANCODE_LSHIFT));
    inputs.push_back(new Key("LALT", SDL_SCANCODE_LALT));
    inputs.push_back(new Key("RCTRL", SDL_SCANCODE_RCTRL));
    inputs.push_back(new Key("RALT", SDL_SCANCODE_RALT));
    inputs.push_back(new Key("RSHIFT", SDL_SCANCODE_RSHIFT));

    inputs.push_back(new Key("GC1_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new Key("GC1_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET));

    inputs.push_back(new Key("GC1_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC1_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC1_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC1_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC1_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC1_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));

    inputs.push_back(new Key("GC2_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new Key("GC2_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET*2));

    inputs.push_back(new Key("GC2_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC2_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC2_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC2_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC2_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC2_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));


    inputs.push_back(new Key("GC3_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new Key("GC3_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET*3));

    inputs.push_back(new Key("GC3_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC3_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC3_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC3_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC3_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC3_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));


    inputs.push_back(new Key("GC4_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new Key("GC4_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET*4));

    inputs.push_back(new Key("GC4_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC4_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC4_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC4_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC4_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new Key("GC4_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));


    inputCodes.reserve(inputs.size());
    inputNames.reserve(inputs.size());
    //loop through and add the inputs to the maps
    for(auto it = inputs.begin(); it != inputs.end(); it++){
        inputCodes.insert(std::pair<int, Key*>((*it)->getKeyCode(), (*it)));
        inputNames.insert(std::pair<std::string, Key*>((*it)->getIdentifier(), (*it)));
    }
    inputs.clear();
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
    inputsPressed++;
    keyIsPressed = true;
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(1);
    }
}

void Input::setAxisValue(int key, int value){
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(value);
    }
}

void Input::setKeyUp(int key){
    inputsPressed++;
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(0);
    }
    if(inputsPressed < 1){
        keyIsPressed = false;
        keyCode = -1;
    }
}

int Input::getValue(const std::string& key){
    if(inputNames.find(key) != inputNames.end()){
        return inputNames.at(key)->getValue();
    }
    return 0;
}

int Input::numControllers(){
    int i = 0;
    for(int j = 0; j < 4; j++){
        if(controllers[j]){
            i++;
        }
    }
    return i;
}

int Input::keyUp(){
    return getValue("UP");
}
int Input::keyDown(){
    return getValue("DOWN");
}
int Input::keyRight(){
    return getValue("RIGHT");
}
int Input::keyLeft(){
    return getValue("LEFT");
}
