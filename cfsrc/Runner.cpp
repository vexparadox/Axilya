//
//  Runner.cpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Runner.hpp"
float Runner::r = 1;
float Runner::g = 1;
float Runner::b = 1;
float Runner::a = 1;
int Runner::keysPressed =0;
std::vector<Scene*> Runner::scenes;
int Runner::mbsPressed = 0;
BaseCore* Runner::c = 0;
Runner::Runner(float windowWidth, float windowHeight, int frameRate, const char* title, BaseCore* c){
    //assign the core to the pointer
    Runner::c = c;
    //sets the event call back method in basecore
    //set the error method in basecore
    glfwSetErrorCallback(errorCallback);
    //if it fails then exit
    if (!glfwInit()){
        exit(EXIT_FAILURE);
    }
    //stop the window from being resizeable
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    //create the window using the height and stuff
    c->getWindow() = glfwCreateWindow(windowWidth, windowHeight, title, NULL, NULL);
    GLFWwindow* window = c->getWindow();
    //set a userpointer for the window to this version of Runner
    glfwSetWindowUserPointer(window, this);
    //set the key_callback method
    glfwSetKeyCallback(window, keyCallback);
    //set mousepressed callback
    glfwSetMouseButtonCallback(window, mouseCallback);
    //set cursor call back
    glfwSetCursorPosCallback(window, cursorCallback);
    //set the window height/width in the BaseCore
    c->windowHeight = windowHeight;
    c->windowWidth = windowWidth;
    //if the window is dead, stop the program
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    //sets the context to the window
    glfwMakeContextCurrent(window);
    //sets the intervals of buffer swaps
    glfwSwapInterval(1);
    //set a base colour of black, makes it easier for beginners
    glColor4f(1, 1, 1, 1);
    //call setup for first time run
    c->setup();
    //the game loop
    while (!glfwWindowShouldClose(window))
    {
        int iconified = glfwGetWindowAttrib(window, GLFW_ICONIFIED);
        int focused = glfwGetWindowAttrib(window, GLFW_FOCUSED);
        
        //this stops the window running in the background and if it's been minimised
        if(iconified || !focused){
            glfwWaitEvents();
        }
        if(fps(frameRate)){
            continue;
        }
        glClearColor(r, g, b, a);
        int width, height;
        //this allows GLtransparancy
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //set view port, allows pixeltopixel things
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        //clear the buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //set the ortho to pixels so it can be used like processing
        glOrtho(0.f, windowWidth, windowHeight, 0.f, -1.f, 1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //call update and then draw if the window isn't iconified
        if(!iconified && focused){
            //draw
            Runner::draw();
        }
        //swap the buffers
        glfwSwapBuffers(window);
        if(!iconified && focused){
            //update
            Runner::update();
        }
        glfwPollEvents();
    }
    //end the program
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void Runner::update(){
    //calls the Core update and update on all scenes
    Runner::c->update();
    for(auto s : scenes){
        if(s->isActive()){
            s->update();
        }
    }
}

void Runner::draw(){
    //calls the Core draw and draw on all scenes
    Runner::c->draw();
    for(auto s : scenes){
        if(s->isActive()){
            s->draw();
        }
    }
}

void Runner::addScene(Scene* s){
    if(s){
        Runner::scenes.push_back(s);
    }
}

std::vector<Scene*>& Runner::getScenes(){
    return Runner::scenes;
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
    void* data = glfwGetWindowUserPointer(window);
    Runner* r = static_cast<Runner*>(data);
    r->c->mouseX = xpos;
    r->c->mouseY = ypos;
}

void Runner::mouseCallback(GLFWwindow *window, int button, int action, int mods){
    void* data = glfwGetWindowUserPointer(window);
    Runner* r = static_cast<Runner*>(data);
    if(action == GLFW_PRESS){
        mbsPressed++;
        r->c->mousePressed(button);
        r->c->mouseIsPressed = true;
        r->c->mouseButton = button;
        return;
    }
    if(action == GLFW_RELEASE){
        mbsPressed--;
        if(mbsPressed < 1){
            r->c->mouseIsPressed = false;
            r->c->mouseButton = -1;
        }
        r->c->mouseReleased(button);
        return;
    }
}

void Runner::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        void* data = glfwGetWindowUserPointer(window);
        Runner* r = static_cast<Runner*>(data);
        r->c->exitCalled();
        return;
    }
    void* data = glfwGetWindowUserPointer(window);
    Runner* r = static_cast<Runner*>(data);
    if(action == GLFW_PRESS){
        r->c->keyIsPressed = true;
        r->c->keyCode = key;
        r->c->keyPressed(key);
        keysPressed++;
        return;
    }
    if(action == GLFW_RELEASE){
        keysPressed--;
        if(keysPressed <1){
            r->c->keyCode = 0;
            r->c->keyIsPressed = false;
        }
        r->c->keyReleased(key);
        return;
    }
}
