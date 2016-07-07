#ifndef Input_hpp
#define Input_hpp

#include <vector>
class Input{
    Input(){};
    ~Input(){};
    static bool Down, Up, Right, Left;
    static std::vector<int> miscKeysPressed;
    public:
    static bool keyIsPressed, mouseIsPressed;
    static int keyCode, mouseButton;
    static int mouseX, mouseY; 
    static void setKeyDown(int key);
    static void setKeyUp(int key);
    static void mousePressed(int button);
    static void mouseReleased(int button);
    static bool keyUp();
    static bool keyDown();
    static bool keyRight();
    static bool keyLeft();
};

#endif
