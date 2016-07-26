#include "Client.hpp"
Client* Client::instance = 0;
Client::Client(){
    //initlialise
	if (enet_initialize () != 0)
    { std::cout << "An error occurred while initializing ENet." << std::endl; }
}

void Client::setup(std::string address, int port, int numChannels, int incBandwidth, int outBandwidth){
    this->address = address;
    this->port = port;
    this->numChannels = numChannels;
    this->incBandwidth = incBandwidth;
    this->outBandwidth = outBandwidth;
    client = enet_host_create (0, 1, numChannels, incBandwidth, outBandwidth);
    //make sure the client has been created
    if (!client)
    { std::cout << "An error occurred while trying to create an ENet client host." << std::endl; }
    enet_address_set_host (&clientAddress, address.c_str());
    clientAddress.port = port;
}

bool Client::connect(int timeout){
    ENetEvent event;
    std::cout << "Attempting to connect with a " << timeout << "ms timeout." << std::endl;
    peer = enet_host_connect (client, & clientAddress, numChannels, 0);    
    if (!peer){ std::cout << "No available peers for initiating an ENet connection." << std::endl; }
    if (enet_host_service (client, &event, timeout) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        isConnected = true;
        return true;
    }else{
        enet_peer_reset (peer);
        std::cout << "Connection to " << address << ":" << port << " failed" << std::endl;
        isConnected = false;
        return false;
    }
}

Client* Client::getInstance(){
    if(!instance){
        instance = new Client();
    }
    return instance;
}

bool Client::isConnected(){
    return isConnected;
}

Client::~Client(){
    enet_deinitialize();
}