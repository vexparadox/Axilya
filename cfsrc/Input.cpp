
#include "Input.hpp"

bool Input::Down = false;
bool Input::Up = false;
bool Input::Right = false;
bool Input::Left = false;
bool Input::keyIsPressed = false;
bool Input::mouseIsPressed = false;
int Input::keyCode = 0;
int Input::mouseButton = -1;
int Input::mouseX = 0;
int Input::mouseY = 0;
std::vector<int> Input::miscKeysPressed;


void Input::mousePressed(int button){

}

void Input::mouseReleased(int button){

    
}

void Input::setKeyDown(int key){
    switch(key){
    case 263:
            Left = true;
            break;
            //LETTER A
        case 65:
            Left = true;
            break;
            //UP ARROW
        case 265:
            Up = true;
            break;
            //LETTER W
        case 87:
            Up = true;
            break;
            //RIGHT ARROW
        case 262:
            Right = true;
            break;
            //LETTER D
        case 68:
            Right = true;
            break;
            //DOWN ARROR
        case 264:
            Down = true;
            break;
            //LETTER S
        case 83:
            Down = true;
            break;
        default:
            // miscKeysPressed.push_back(key);
            break;
    }
}
void Input::setKeyUp(int key){
     switch(key){
    case 263:
            Left = false;
            break;
            //LETTER A
        case 65:
            Left = false;
            break;
            //UP ARROW
        case 265:
            Up = false;
            break;
            //LETTER W
        case 87:
            Up = false;
            break;
            //RIGHT ARROW
        case 262:
            Right = false;
            break;
            //LETTER D
        case 68:
            Right = false;
            break;
            //DOWN ARROR
        case 264:
            Down = false;
            break;
            //LETTER S
        case 83:
            Down = false;
            break;
        default:
            // miscKeysPressed.push_back(key);
            break;
    //32 = space
    //E = 69
     }
    
}
bool Input::keyUp(){
    return Up;
}
bool Input::keyDown(){
    return Down;
}
bool Input::keyRight(){
    return Right;
}
bool Input::keyLeft(){
    return Left;
}
