#ifndef Input_hpp
#define Input_hpp

#include <vector>
class Input{
    Input(){};
    ~Input(){};
    static bool Down, Up, Right, Left;
    static std::vector<int> miscKeysPressed;
    public:
    static void setKeyDown(int key);
    static void setKeyUp(int key);
    static bool keyUp();
    static bool keyDown();
    static bool keyRight();
    static bool keyLeft();
};

#endif
