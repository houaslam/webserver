#pragma once

#include "webserv.hpp"

class Server : public WebServer{
    public:
        Server(int domaine, int type, int protocol, int port, u_long interface);
        ~Server();
        virtual int setup();
        // void handle_request(std::string request);
};