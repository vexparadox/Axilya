//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#include "../../src/headers/AXMain.h"
#include "frameworkCore.hpp"

int main(int argc, char *argv[])
{
    //start a new runner with the constructor
    //Runner(int width, int height, int windowType, const char* title, new "corename");
    //there are two example cores given with the repo, frameworkCore and engineCore
    //framework core is for showing off the simple framework code
    //engine core is for showing off the ECS and engine code
    Runner(720, 480, AX_WINDOWED, "Axilya", new frameworkCore());
}