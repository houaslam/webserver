#pragma once

#include "webserv.hpp"
#include "Server.hpp"
#include "Request.hpp"
#include "Response.hpp"

class Client : public WebServer{
    public:
    // CANONICAL FORM
        Client(Server &server);
        Client(Client& src);
        // Client& operator=(Client& src);
        ~Client();

        virtual int setup();
};
