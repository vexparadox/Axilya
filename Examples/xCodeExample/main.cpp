//
//  main.cpp
//  xCodeExample
//
//  Created by William Meaton on 01/02/2017.
//  Copyright © 2017 William Meaton. All rights reserved.
//

#include <iostream>
#include <Axilya/AXMain.h>

int main(int argc, const char * argv[]) {
    if(!AXWindow::init(720, 480, "Basic Example", AX_DEFAULT)){
        std::cout << "AXWindow failed to initialise" << std::endl;
        return -1;
    }
    //return the window run, this is where the update and draw will be called
    return AXWindow::run();
}
