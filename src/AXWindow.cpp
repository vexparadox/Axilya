//
//  AXWindow.cpp
//  Axilya
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "headers/AXWindow.hpp"
//render colours
AXGraphics::Colour AXWindow::backgroundColour;
AXGraphics::Colour AXWindow::renderColour;
//store the display and window sizes
int AXWindow::windowWidth = 0;
int AXWindow::windowHeight = 0;
int AXWindow::displayWidth = 0;
int AXWindow::displayHeight = 0;
//the active scene
Scene* AXWindow::activeScene = 0;
//store the SDL window and renderer
SDL_Renderer* AXWindow::renderer = 0;
SDL_Window* AXWindow::window = 0;
//the running variable
int AXWindow::go = 1;
std::string AXWindow::runPath = "";

//if it's already been initated
bool AXWindow::initiated = false;

//the update and draw methods
UDFunction AXWindow::draw = 0;
UDFunction AXWindow::update = 0;

int AXWindow::init(float wWidth, float wHeight, int windowStyle, const char* title){
    return AXWindow::init(wWidth, wHeight, windowStyle, title, nullptr, nullptr);
}


int AXWindow::init(float wWidth, float wHeight, int windowStyle, const char* title, UDFunction update, UDFunction draw){
    if(initiated){
        return -1;
    }
    AXWindow::update = update;
    AXWindow::draw = draw;
    //The window we'll be rendering to
    runPath = SDL_GetBasePath();
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return -1;
    }

    if (TTF_Init() < 0) {
        printf("SDLTTF could not initialise! SDL_Error: %s\n", TTF_GetError());
        return -1;
    }

    //get the display size
    SDL_DisplayMode mode;
    if(SDL_GetCurrentDisplayMode(0, &mode) == 0){
        displayWidth = mode.w;
        displayHeight = mode.h;
    }else{
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }
    //if it's <0 default to the display size
    if(wWidth < 0){
        wWidth = displayWidth;
    }
    if(wHeight < 0){
        wHeight = displayHeight;
    }
    //Create a window
    AXWindow::window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(window == NULL ){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return -1;
    }

    //set the window based on it
    switch(windowStyle){
        case AX_WINDOWED:
           SDL_SetWindowFullscreen(window, 0);
            break;
        case AX_FULLSCREEN:
           SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
           break;
        default:
           SDL_SetWindowFullscreen(window, 0);
            break;
    }
    //save the window width and height
    AXWindow::windowWidth = wWidth;
    AXWindow::windowHeight = wHeight;
    
    //make a renderer
    AXWindow::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    backgroundColour.set(255, 255, 255, 255);
    renderColour.set(0, 0, 0, 255);
    //set blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    Input::init();
    initiated = true;
    return 1;
}

int AXWindow::run(){
    if(activeScene){
        activeScene->start();
    }
    SDL_Event event;
    bool inFocus = true;
    while(go == 1){
        while(SDL_PollEvent(&event) != 0 ){
            //User requests quit
            if(event.type == SDL_QUIT){
                go = 0;
            }else if( event.type == SDL_KEYDOWN){
                Input::setKeyDown(event.key.keysym.scancode);
            }else if(event.type == SDL_KEYUP){
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    go = 0;
                    break;
                }
                Input::setKeyUp(event.key.keysym.scancode);
            }else if(event.type == SDL_MOUSEMOTION){
                Input::mouseX = event.motion.x;
                Input::mouseY = event.motion.y;
            }else if(event.type == SDL_MOUSEBUTTONDOWN){
                Input::mousePressed(event.button.button);
            }else if(event.type == SDL_MOUSEBUTTONUP){
                Input::mouseReleased(event.button.button);
            }else if(event.type == SDL_CONTROLLERBUTTONDOWN){
                Input::setKeyDown((SDL_GameControllerButton)event.cbutton.button+(AX_INPUT_CONTROLLER_OFFSET*(event.cdevice.which+1)));
            }else if(event.type == SDL_CONTROLLERBUTTONUP){
                Input::setKeyUp((SDL_GameControllerButton)event.cbutton.button+(AX_INPUT_CONTROLLER_OFFSET*(event.cdevice.which+1)));
            }else if(event.type == SDL_CONTROLLERDEVICEADDED){
                Input::controllers[event.cdevice.which] = SDL_GameControllerOpen(event.cdevice.which);
                std::cout << "Controller connected: " << event.cdevice.which << std::endl;
            }else if(event.type == SDL_CONTROLLERDEVICEREMOVED){
                std::cout << "Controller disconnected: " << event.cdevice.which << std::endl;
                SDL_GameControllerClose(Input::controllers[event.cdevice.which]);
                Input::controllers[event.cdevice.which] = 0;
            }else if(event.type == SDL_CONTROLLERAXISMOTION){
                Input::setAxisValue(AX_INPUT_CONTROLLER_AXIS_OFFSET+event.caxis.axis+AX_INPUT_CONTROLLER_OFFSET*(event.caxis.which+1), event.caxis.value);
            }else if(event.type == SDL_WINDOWEVENT){
                if(event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED){
                    inFocus = true;
                }else if(event.window.event == SDL_WINDOWEVENT_FOCUS_LOST){
                    inFocus = false;
                }
            }
        }
        if(inFocus){
            if(update){
                update();
            }
            if(activeScene) {
                activeScene->update();
            }
        }
        //Fill the surface wshite
        SDL_SetRenderDrawColor(AXWindow::renderer, backgroundColour.getR(), backgroundColour.getG(), backgroundColour.getB(), backgroundColour.getA());
        SDL_RenderClear(AXWindow::renderer);
        if(inFocus){
            SDL_SetRenderDrawColor(AXWindow::renderer, renderColour.getR(), renderColour.getG(), renderColour.getB(), renderColour.getA());
            if(draw){
                draw();
            }
            if(activeScene) {
                activeScene->draw();
            }
        }
        SDL_RenderPresent(AXWindow::renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}

void AXWindow::setCurrentScene(Scene *s) {
    if(s) {
        activeScene = s;
    }
}

int AXWindow::getHeight(){
    return windowHeight;
}

void AXWindow::hideCursor(bool value){
    if(!value){
        SDL_ShowCursor(SDL_ENABLE);
    }else{
        SDL_ShowCursor(SDL_DISABLE);
    }
}

void AXWindow::lockCursor(bool value){
    if(value){
        SDL_SetRelativeMouseMode(SDL_TRUE);
    }else{
        SDL_SetRelativeMouseMode(SDL_FALSE);
    }
}

SDL_Window* AXWindow::getWindow(){
    return window;
}

int AXWindow::getWidth(){
    return windowWidth;
}

int AXWindow::getDisplayWidth(){
    return displayWidth;
}

int AXWindow::getDisplayHeight(){
    return displayHeight;
}

void AXWindow::shutdown(){
    AXWindow::go = 0;
}
