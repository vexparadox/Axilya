//
//  Client.hpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#ifndef Client_hpp
#define Client_hpp
#include "enet/enet.h"
#include <iostream>
class Client{
    Client();
    ~Client();
    static Client* instance;
    ENetHost* client;
    ENetPeer *peer;
    ENetAddress clientAddress;
    int incBandwidth = 0;
    int outBandwidth = 0;
    int numChannels = 2;
    bool isConnected = false;
    public:
    void setup(std::string address, int port, int numChannels, int incBandwidth, int outBandwidth);
    bool connect(int timeout);
    static Client* getInstance();
};
#endif