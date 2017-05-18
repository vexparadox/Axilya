//
//  AXWindow.cpp
//  Axilya
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "headers/AXWindow.hpp"
//render colours
AXColour AXWindow::backgroundColour;
AXColour AXWindow::renderColour;
//store the display and window sizes
int AXWindow::windowWidth = 0;
int AXWindow::windowHeight = 0;
int AXWindow::displayWidth = 0;
int AXWindow::displayHeight = 0;
//the active scene
AXScene* AXWindow::activeScene = 0;
//store the SDL window and renderer
SDL_Renderer* AXWindow::renderer = 0;
SDL_Window* AXWindow::window = 0;
//the running variable
int AXWindow::go = 1;
//the run path
std::string AXWindow::runPath = "";
//the start time
std::time_t AXWindow::startTime;

//if it's already been initated
bool AXWindow::initiated = false;
bool AXWindow::audioStatus = false;

//delta time value
Uint64 AXWindow::deltaTime = 0;
Uint64 AXWindow::previousDeltaTime = 0;


//the setup, update and draw methods
AXFunction AXWindow::draw = 0;
AXFunction AXWindow::update = 0;
AXFunction AXWindow::setup = 0;

int AXWindow::init(float wWidth, float wHeight, const char* title, unsigned int flags){
    return AXWindow::init(wWidth, wHeight, title, flags, nullptr, nullptr, nullptr);
}


int AXWindow::init(float wWidth, float wHeight, const char* title, unsigned int flags, AXFunction setup, AXFunction update, AXFunction draw){
    if(initiated){
        return -1;
    }
    startTime = std::time(0);
    AXWindow::setup = setup;
    AXWindow::update = update;
    AXWindow::draw = draw;
    //The window we'll be rendering to
    runPath = SDL_GetBasePath();
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        AXLog::log("SDL could not initialize!", SDL_GetError(), AX_LOG_ERROR);
        return -1;
    }
    if(TTF_Init() < 0){
        AXLog::log("SDL_TTF could not initialise!", TTF_GetError(), AX_LOG_ERROR);
        return -1;
    }
    //get the display size
    SDL_DisplayMode mode;
    if(SDL_GetCurrentDisplayMode(0, &mode) == 0){
        displayWidth = mode.w;
        displayHeight = mode.h;
    }else{
        AXLog::log("Display data failed to load", "displayWidth and displayHeight will be inaccurate", AX_LOG_WARNING);
        std::cout << SDL_GetError() << std::endl;
    }
    //if it's <0 default to the display size
    if(wWidth < 0){
        wWidth = displayWidth;
    }
    if(wHeight < 0){
        wHeight = displayHeight;
    }
    //Create a window
    AXWindow::window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_SHOWN);
    if(window == NULL ){
        AXLog::log("Window could not be created!", SDL_GetError(), AX_LOG_ERROR);
        return -1;
    }

    //check the window flags
    if(flags & AX_WINDOWED){
       SDL_SetWindowFullscreen(window, 0);
    }else if(flags & AX_FULLSCREEN){
       SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    }else{
       SDL_SetWindowFullscreen(window, 0);
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
    //check the flags for noaudio
    audioStatus = !(flags & AX_NOAUDIO);
    if(audioStatus){
        //open the aduio channel
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) != 0){
            AXLog::log("Audio failed to initialise.", Mix_GetError(), AX_LOG_ERROR);
            audioStatus = false;
        }
    }

    AXInput::init();
    AXNetwork::init();
    if(!(flags&AX_NOANALYTICS)){
        std::vector<AXNetworkPair> pairs;
        pairs.push_back(AXNetworkPair("v", std::to_string(AX_VERSION)));
        pairs.push_back(AXNetworkPair("t", std::to_string(startTime)));
        AXNetwork::MTPOSTRequestSimple("http://axilya.com/analytics.php", pairs, false);
    }
    initiated = true;
    return 1;
}

int AXWindow::run(){
    if(setup){
        setup();
    }
    if(activeScene){
        activeScene->start();
    }
    SDL_Event event;
    bool inFocus = true;
    while(go == 1){
        AXWindow::deltaTime = SDL_GetPerformanceCounter() - AXWindow::previousDeltaTime;
        AXWindow::previousDeltaTime = SDL_GetPerformanceCounter();
        while(SDL_PollEvent(&event) != 0 ){
            //User requests quit
            if(event.type == SDL_QUIT){
                go = 0;
            }else if( event.type == SDL_KEYDOWN){
                const std::string& temp = AXInput::setKeyDown(event.key.keysym.scancode);
                if(activeScene){
                    activeScene->inputChange(temp, 1);
                }
            }else if(event.type == SDL_KEYUP){
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    go = 0;
                    break;
                }
                const std::string& temp = AXInput::setKeyUp(event.key.keysym.scancode);
                if(activeScene){
                    activeScene->inputChange(temp, 0);
                }
            }else if(event.type == SDL_MOUSEMOTION){
                AXInput::mouseX = event.motion.x;
                AXInput::mouseY = event.motion.y;
            }else if(event.type == SDL_MOUSEBUTTONDOWN){
                const std::string& temp = AXInput::mousePressed(event.button.button);
                if(activeScene){
                    activeScene->inputChange(temp, 1);
                }
            }else if(event.type == SDL_MOUSEBUTTONUP){
                const std::string& temp = AXInput::mouseReleased(event.button.button);
                if(activeScene){
                    activeScene->inputChange(temp, 0);
                }
            }else if(event.type == SDL_CONTROLLERBUTTONDOWN){
                const std::string& temp = AXInput::setKeyDown((SDL_GameControllerButton)event.cbutton.button+(AX_INPUT_CONTROLLER_OFFSET*(event.cdevice.which+1)));
                if(activeScene){
                    activeScene->inputChange(temp, 1);
                }

            }else if(event.type == SDL_CONTROLLERBUTTONUP){
                const std::string& temp = AXInput::setKeyUp((SDL_GameControllerButton)event.cbutton.button+(AX_INPUT_CONTROLLER_OFFSET*(event.cdevice.which+1)));
                if(activeScene){
                    activeScene->inputChange(temp, 0);
                }
            }else if(event.type == SDL_CONTROLLERDEVICEADDED){
                AXInput::controllers[event.cdevice.which] = SDL_GameControllerOpen(event.cdevice.which);
            }else if(event.type == SDL_CONTROLLERDEVICEREMOVED){
                SDL_GameControllerClose(AXInput::controllers[event.cdevice.which]);
                AXInput::controllers[event.cdevice.which] = 0;
            }else if(event.type == SDL_CONTROLLERAXISMOTION){
                AXInput::setAxisValue(AX_INPUT_CONTROLLER_AXIS_OFFSET+event.caxis.axis+AX_INPUT_CONTROLLER_OFFSET*(event.caxis.which+1), event.caxis.value);
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
    //quit the SDLMix
    if(audioStatus){
        while(Mix_Init(0)){
            Mix_Quit();
        }
        Mix_CloseAudio();
    }
    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

void AXWindow::setCurrentScene(AXScene *s) {
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

double AXWindow::getDeltaTime(){
    return (double)((double)(deltaTime)/(double)SDL_GetPerformanceFrequency());
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
