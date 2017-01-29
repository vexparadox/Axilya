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
