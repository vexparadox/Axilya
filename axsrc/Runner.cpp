//
//  Runner.cpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Runner.hpp"
float Runner::r;
float Runner::g;
float Runner::b;
float Runner::a;
BaseCore* Runner::c = 0;
Scene* Runner::activeScene = 0;
std::string Runner::runPath = "";
int Runner::go = 1;
Runner::Runner(float windowWidth, float windowHeight, int frameRate, const char* title, BaseCore* c){
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    //Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    //make a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Runner::c = c;
    //set blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    c->setWindow(window);
    c->windowHeight = windowHeight;
    c->windowWidth = windowWidth;
    Input::init();
    c->setup();

    if(activeScene){
       activeScene->start();
    }

    SDL_Event event;
    // glColor4f(1, 1, 1, 1);
    while(go == 1){
        while( SDL_PollEvent( &event ) != 0 ){
            //User requests quit
            if(event.type == SDL_QUIT){
                c->exitCalled();
            }else if( event.type == SDL_KEYDOWN){
                Input::setKeyDown(event.key.keysym.sym);
            }else if(event.type == SDL_KEYUP){
                Input::setKeyUp(event.key.keysym.sym);
            }
        }
        if(activeScene) {
            activeScene->update();
        }
        //Fill the surface white
        // std::cout << Runner::r << " " << std::cout << g << std::endl;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        if(activeScene) {
            activeScene->draw();
        }
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    //Quit SDL subsystems
    SDL_Quit();

    // //assign the core to the pointer
    // Runner::c = c;
    // //sets the event call back method in basecore
    // //set the error method in basecore
    // glfwSetErrorCallback(errorCallback);
    // //if it fails then exit
    // if (!glfwInit()){
    //     exit(EXIT_FAILURE);
    // }
    // //stop the window from being resizeable
    // glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    // //create the window using the height and stuff
    // c->getWindow() = glfwCreateWindow(windowWidth, windowHeight, title, NULL, NULL);
    // GLFWwindow* window = c->getWindow();
    // //set the key_callback method
    // glfwSetKeyCallback(window, keyCallback);
    // //set mousepressed callback
    // glfwSetMouseButtonCallback(window, mouseCallback);
    // //set cursor call back
    // glfwSetCursorPosCallback(window, cursorCallback);
    // //set the window height/width in the BaseCore
    // c->windowHeight = windowHeight;
    // c->windowWidth = windowWidth;
    // //if the window is dead, stop the program
    // if (!window)
    // {
    //     glfwTerminate();
    //     exit(EXIT_FAILURE);
    // }
    // //sets the context to the window
    // glfwMakeContextCurrent(window);
    // //sets the intervals of buffer swaps
    // glfwSwapInterval(1);
    // //set a base colour of black, makes it easier for beginners
    // //initialise the Input class
    // Input::init();
    // //call setup for first time run
    // c->setup();
    // if(activeScene){
    //    activeScene->start();
    // }
    // //the game loop
    // while (!glfwWindowShouldClose(window))
    // {
    //     int iconified = glfwGetWindowAttrib(window, GLFW_ICONIFIED);
    //     int focused = glfwGetWindowAttrib(window, GLFW_FOCUSED);
        
    //     //this stops the window running in the background and if it's been minimised
    //     if(iconified || !focused){
    //         glfwWaitEvents();
    //     }
    //     if(fps(frameRate)){
    //         continue;
    //     }
    //     glClearColor(r, g, b, a);
    //     int width, height;
    //     //this allows GLtransparancy
    //     glEnable (GL_BLEND);
    //     glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //     //set view port, allows pixeltopixel things
    //     glfwGetFramebufferSize(window, &width, &height);
    //     //clear the buffer
    //     glLoadIdentity();
    //     //set the ortho to pixels so it can be used like processing
    //     if(!iconified && focused){
    //         //update
    //         c->update();
    //         if(activeScene) {
    //             activeScene->update();
    //         }
    //     }
    //     //call update and then draw if the window isn't iconified
    //     if(!iconified && focused){
    //         //draw
    //         c->draw();
    //         if(activeScene) {
    //             activeScene->draw();
    //         }
    //     }
    //     //swap the buffers
    //     glfwSwapBuffers(window);
    //     glfwPollEvents();
    // }
    // //end the program
    // delete activeScene;
    // activeScene = 0;
    // glfwDestroyWindow(window);
    // glfwTerminate();
    exit(EXIT_SUCCESS);
}

bool Runner::fps(int framerate)
{
    currentTime = glfwGetTime();
    
    if(currentTime - lastTime >= 1.0 / framerate)
    {
        lastTime = currentTime;
        return true;
    }
    return false;
}


void Runner::errorCallback(int error, const char* description){
    fputs(description, stderr);
}

void Runner::cursorCallback(GLFWwindow* window, double xpos, double ypos){
    Input::mouseX = xpos;
    Input::mouseY = ypos;
}

void Runner::mouseCallback(GLFWwindow *window, int button, int action, int mods){
    if(action == GLFW_PRESS){
        Input::mousePressed(button);
        return;
    }
    if(action == GLFW_RELEASE){
        Input::mouseReleased(button);
        return;
    }
}

void Runner::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        Runner::c->exitCalled();
        return;
    }
    if(action == GLFW_PRESS){
        Input::setKeyDown(key);
        return;
    }
    if(action == GLFW_RELEASE){
        Input::setKeyUp(key);
        return;
    }
}

void Runner::setCurrentScene(Scene *s) {
    if(s) {
        activeScene = s;
    }
}

int Runner::getHeight(){
    return Runner::c->windowHeight;
}

int Runner::getWidth(){
    return Runner::c->windowWidth;
}

void Runner::shutdown(){
    Runner::go = 0;
}
