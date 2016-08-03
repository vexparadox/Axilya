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
    enet_host_flush (client);    
    if (!peer){ std::cout << "No available peers for initiating an ENet connection." << std::endl; }
    if (enet_host_service (client, &event, timeout) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        connected = true;
        return true;
    }else{
        enet_peer_reset (peer);
        std::cout << "Connection to " << address << ":" << port << " failed" << std::endl;
        connected = false;
        return false;
    }
}

void Client::disconnect(){
    ENetEvent event;
    enet_peer_disconnect (peer, 0);
    /* Allow up to 3 seconds for the disconnect to succeed
    * and drop any packets received packets.
    */
    while (enet_host_service (client, & event, 3000) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_RECEIVE:
            enet_packet_destroy (event.packet);
        break;
        case ENET_EVENT_TYPE_DISCONNECT:
            std::cout << "Disconnection succeeded." << std::endl;
        return;
        }
    }
    //reset if we reach here, this is a forcefull disconnect
    enet_peer_reset (peer);
}

void Client::sendPacket(){
    ENetPacket* packet = enet_packet_create ("10", strlen ("10") + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_host_broadcast (client, 0, packet);         
    enet_host_flush (client);
}

Client* Client::getInstance(){
    if(!instance){
        instance = new Client();
    }
    return instance;
}

bool Client::isConnected(){
    return connected;
}

Client::~Client(){
    enet_deinitialize();
}