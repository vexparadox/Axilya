#include <iostream>
#include "headers/AXInput.hpp"

bool AXInput::keyIsPressed = false;
bool AXInput::mouseIsPressed = false;
int AXInput::keyCode = 0;
int AXInput::mouseX = 0;
int AXInput::mouseY = 0;
int AXInput::inputsPressed = 0;
int AXInput::mouseButton = -1;
int AXInput::mouseButtonsPressed = 0;
SDL_GameController* AXInput::controllers[4];
std::vector<AXKey*> AXInput::inputs;
std::unordered_map<int, AXKey*> AXInput::inputCodes;
std::unordered_map<std::string, AXKey*> AXInput::inputNames;

void AXInput::init() {
    inputs.reserve(113);
    inputs.push_back(new AXKey("MB1", -2));
    inputs.push_back(new AXKey("MB2", -1));
    inputs.push_back(new AXKey("SPACE", SDL_SCANCODE_SPACE));
    inputs.push_back(new AXKey("A", SDL_SCANCODE_A));
    inputs.push_back(new AXKey("B", SDL_SCANCODE_B));
    inputs.push_back(new AXKey("C", SDL_SCANCODE_C));
    inputs.push_back(new AXKey("D", SDL_SCANCODE_D));
    inputs.push_back(new AXKey("E", SDL_SCANCODE_E));
    inputs.push_back(new AXKey("F", SDL_SCANCODE_F));
    inputs.push_back(new AXKey("G", SDL_SCANCODE_G));
    inputs.push_back(new AXKey("H", SDL_SCANCODE_H));
    inputs.push_back(new AXKey("I", SDL_SCANCODE_I));
    inputs.push_back(new AXKey("J", SDL_SCANCODE_J));
    inputs.push_back(new AXKey("K", SDL_SCANCODE_K));
    inputs.push_back(new AXKey("L", SDL_SCANCODE_L));
    inputs.push_back(new AXKey("M", SDL_SCANCODE_M));
    inputs.push_back(new AXKey("N", SDL_SCANCODE_N));
    inputs.push_back(new AXKey("O", SDL_SCANCODE_O));
    inputs.push_back(new AXKey("P", SDL_SCANCODE_P));
    inputs.push_back(new AXKey("Q", SDL_SCANCODE_Q));
    inputs.push_back(new AXKey("R", SDL_SCANCODE_R));
    inputs.push_back(new AXKey("S", SDL_SCANCODE_S));
    inputs.push_back(new AXKey("T", SDL_SCANCODE_T));
    inputs.push_back(new AXKey("U", SDL_SCANCODE_U));
    inputs.push_back(new AXKey("V", SDL_SCANCODE_V));
    inputs.push_back(new AXKey("W", SDL_SCANCODE_W));
    inputs.push_back(new AXKey("X", SDL_SCANCODE_X));
    inputs.push_back(new AXKey("Y", SDL_SCANCODE_Y));
    inputs.push_back(new AXKey("Z", SDL_SCANCODE_Z));
    inputs.push_back(new AXKey("1", SDL_SCANCODE_1));
    inputs.push_back(new AXKey("2", SDL_SCANCODE_2));
    inputs.push_back(new AXKey("3", SDL_SCANCODE_3));
    inputs.push_back(new AXKey("4", SDL_SCANCODE_4));
    inputs.push_back(new AXKey("5", SDL_SCANCODE_5));
    inputs.push_back(new AXKey("6", SDL_SCANCODE_6));
    inputs.push_back(new AXKey("7", SDL_SCANCODE_7));
    inputs.push_back(new AXKey("8", SDL_SCANCODE_8));
    inputs.push_back(new AXKey("9", SDL_SCANCODE_9));
    inputs.push_back(new AXKey("0", SDL_SCANCODE_0));
    inputs.push_back(new AXKey("RIGHT", SDL_SCANCODE_RIGHT));
    inputs.push_back(new AXKey("LEFT", SDL_SCANCODE_LEFT));
    inputs.push_back(new AXKey("DOWN", SDL_SCANCODE_DOWN));
    inputs.push_back(new AXKey("UP", SDL_SCANCODE_UP));
    inputs.push_back(new AXKey("ENTER", SDL_SCANCODE_RETURN));
    inputs.push_back(new AXKey("TAB", SDL_SCANCODE_TAB));
    inputs.push_back(new AXKey("LCTRL", SDL_SCANCODE_LCTRL));
    inputs.push_back(new AXKey("LSHIFT", SDL_SCANCODE_LSHIFT));
    inputs.push_back(new AXKey("LALT", SDL_SCANCODE_LALT));
    inputs.push_back(new AXKey("RCTRL", SDL_SCANCODE_RCTRL));
    inputs.push_back(new AXKey("RALT", SDL_SCANCODE_RALT));
    inputs.push_back(new AXKey("RSHIFT", SDL_SCANCODE_RSHIFT));

    inputs.push_back(new AXKey("GC1_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET));
    inputs.push_back(new AXKey("GC1_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET));

    inputs.push_back(new AXKey("GC1_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC1_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC1_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC1_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC1_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC1_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+AX_INPUT_CONTROLLER_OFFSET+AX_INPUT_CONTROLLER_AXIS_OFFSET));

    inputs.push_back(new AXKey("GC2_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET*2));
    inputs.push_back(new AXKey("GC2_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET*2));

    inputs.push_back(new AXKey("GC2_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC2_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC2_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC2_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC2_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC2_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+(AX_INPUT_CONTROLLER_OFFSET*2)+AX_INPUT_CONTROLLER_AXIS_OFFSET));


    inputs.push_back(new AXKey("GC3_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET*3));
    inputs.push_back(new AXKey("GC3_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET*3));

    inputs.push_back(new AXKey("GC3_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC3_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC3_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC3_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC3_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC3_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+(AX_INPUT_CONTROLLER_OFFSET*3)+AX_INPUT_CONTROLLER_AXIS_OFFSET));

    inputs.push_back(new AXKey("GC4_A", SDL_CONTROLLER_BUTTON_A+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_B", SDL_CONTROLLER_BUTTON_B+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_X", SDL_CONTROLLER_BUTTON_X+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_Y", SDL_CONTROLLER_BUTTON_Y+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_BACK", SDL_CONTROLLER_BUTTON_BACK+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_GUIDE", SDL_CONTROLLER_BUTTON_GUIDE+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_START", SDL_CONTROLLER_BUTTON_START+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_LEFTSTICK", SDL_CONTROLLER_BUTTON_LEFTSTICK+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_RIGHTSTICK", SDL_CONTROLLER_BUTTON_RIGHTSTICK+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_LEFTSHOULDER", SDL_CONTROLLER_BUTTON_LEFTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_RIGHTSHOULDER", SDL_CONTROLLER_BUTTON_RIGHTSHOULDER+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_DUP", SDL_CONTROLLER_BUTTON_DPAD_UP+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_DDOWN", SDL_CONTROLLER_BUTTON_DPAD_DOWN+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_DLEFT", SDL_CONTROLLER_BUTTON_DPAD_LEFT+AX_INPUT_CONTROLLER_OFFSET*4));
    inputs.push_back(new AXKey("GC4_DRIGHT", SDL_CONTROLLER_BUTTON_DPAD_RIGHT+AX_INPUT_CONTROLLER_OFFSET*4));

    inputs.push_back(new AXKey("GC4_LEFTSTICK_X", SDL_CONTROLLER_AXIS_LEFTX+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC4_LEFTSTICK_Y", SDL_CONTROLLER_AXIS_LEFTY+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC4_RIGHTSTICK_X", SDL_CONTROLLER_AXIS_RIGHTX+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC4_RIGHTSTICK_Y", SDL_CONTROLLER_AXIS_RIGHTY+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC4_TRIGGERRIGHT", SDL_CONTROLLER_AXIS_TRIGGERLEFT+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));
    inputs.push_back(new AXKey("GC4_TRIGGERLEFT", SDL_CONTROLLER_AXIS_TRIGGERRIGHT+(AX_INPUT_CONTROLLER_OFFSET*4)+AX_INPUT_CONTROLLER_AXIS_OFFSET));


    inputCodes.reserve(inputs.size());
    inputNames.reserve(inputs.size());
    //loop through and add the inputs to the maps
    for(auto it = inputs.begin(); it != inputs.end(); it++){
        inputCodes.insert(std::pair<int, AXKey*>((*it)->getKeyCode(), (*it)));
        inputNames.insert(std::pair<std::string, AXKey*>((*it)->getIdentifier(), (*it)));
    }
    inputs.clear();
}


const std::string& AXInput::mousePressed(int button){
    mouseIsPressed = true;
    mouseButton = button;
    mouseButtonsPressed++;
    int key;
    if(button == SDL_BUTTON_LEFT){
        key = -2;
    }else if(button == SDL_BUTTON_RIGHT){
        key = -1;
    }
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(1);
        return inputCodes.at(key)->getIdentifier();
    }
    return "";
}

const std::string& AXInput::mouseReleased(int button){
    mouseButtonsPressed--;
    if(mouseButtonsPressed < 1){
        mouseIsPressed = false;
        mouseButton = -1;
    }
    std::cout << button << " BUT" << std::endl;
    int key;
    if(button == SDL_BUTTON_LEFT){
        key = -2;
    }else if(button == SDL_BUTTON_RIGHT){
        key = -1;
    }
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(0);
        return inputCodes.at(key)->getIdentifier();
    }
    return "";
}

const std::string& AXInput::setKeyDown(int key){
    keyCode = key;
    inputsPressed++;
    keyIsPressed = true;
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(1);
        return inputCodes.at(key)->getIdentifier();
    }
    return "";
}

const std::string& AXInput::setAxisValue(int key, int value){
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(value);
        return inputCodes.at(key)->getIdentifier();
    }
    return "";
}

const std::string& AXInput::setKeyUp(int key){
    inputsPressed--;
    if(inputsPressed < 1){
        keyIsPressed = false;
        keyCode = -1;
    }
    if(inputCodes.find(key) != inputCodes.end()){
        inputCodes.at(key)->setValue(0);
        return inputCodes.at(key)->getIdentifier();
    }
    return "";
}

int AXInput::getValue(const std::string& key){
    if(inputNames.find(key) != inputNames.end()){
        return inputNames.at(key)->getValue();
    }
    return 0;
}

int AXInput::numControllers(){
    int i = 0;
    for(int j = 0; j < 4; j++){
        if(controllers[j]){
            i++;
        }
    }
    return i;
}