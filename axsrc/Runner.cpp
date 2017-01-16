//
//  Runner.cpp
//  Axilya
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Runner.hpp"
//render colours
Graphics::Colour Runner::backgroundColour;
Graphics::Colour Runner::renderColour;
//store the display and window sizes
int Runner::windowWidth = 0;
int Runner::windowHeight = 0;
int Runner::displayWidth = 0;
int Runner::displayHeight = 0;
//store the core
BaseCore* Runner::c = 0;
//the active scene
Scene* Runner::activeScene = 0;
//the run path
std::string Runner::runPath = "";
//store the SDL window and renderer
SDL_Renderer* Runner::renderer = 0;
SDL_Window* Runner::window = 0;
//the running variable
int Runner::go = 1;
Runner::Runner(float wWidth, float wHeight, int windowStyle, const char* title, BaseCore* c){
    //The window we'll be rendering to
    runPath = SDL_GetBasePath();
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    //get the display size
    SDL_DisplayMode mode;
    if(SDL_GetCurrentDisplayMode(0, &mode) == 0){
        displayWidth = mode.w;
        displayHeight = mode.h;
    }else{
        std::cout << SDL_GetError() << std::endl;
    }

    //Create window
    Runner::window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
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
    Runner::windowWidth = wWidth;
    Runner::windowHeight = wHeight;
    
    //make a renderer
    Runner::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Runner::c = c;
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    backgroundColour.set(255, 255, 255, 255);
    renderColour.set(0, 0, 0, 255);
    //set blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    Input::init();
    c->setup();
    if(activeScene){    
       activeScene->start();
    }
    SDL_Event event;
    bool inFocus = true;
    // glColor4f(1, 1, 1, 1);
    while(go == 1){
        while( SDL_PollEvent( &event ) != 0 ){
            //User requests quit
            if(event.type == SDL_QUIT){
                c->exitCalled();
            }else if( event.type == SDL_KEYDOWN){
                Input::setKeyDown(event.key.keysym.scancode);
            }else if(event.type == SDL_KEYUP){
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    c->exitCalled();
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
            }else if(event.window.event == SDL_WINDOWEVENT_FOCUS_LOST){
                inFocus = false;
            }else if(event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED){
                inFocus = true;
            }
        }
        if(inFocus){
            c->update();
            if(activeScene) {
                activeScene->update();
            }
        }
        //Fill the surface wshite
        SDL_SetRenderDrawColor(Runner::renderer, backgroundColour.getR(), backgroundColour.getG(), backgroundColour.getB(), backgroundColour.getA());
        SDL_RenderClear(Runner::renderer);
        if(inFocus){
            SDL_SetRenderDrawColor(Runner::renderer, renderColour.getR(), renderColour.getG(), renderColour.getB(), renderColour.getA());
            c->draw();
            if(activeScene) {
                activeScene->draw();
            }
        }
        SDL_RenderPresent(Runner::renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    //Quit SDL subsystems
    SDL_Quit();
    exit(EXIT_SUCCESS);
}

void Runner::setCurrentScene(Scene *s) {
    if(s) {
        activeScene = s;
    }
}

int Runner::getHeight(){
    return windowHeight;
}

SDL_Window* Runner::getWindow(){
    return window;
}

int Runner::getWidth(){
    return windowWidth;
}

int Runner::getDisplayWidth(){
    return displayWidth;
}

int Runner::getDisplayHeight(){
    return displayHeight;
}

void Runner::shutdown(){
    Runner::go = 0;
}
