#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <cstdlib>  
#include <unistd.h>  
#include <sys/socket.h>
#include <netinet/in.h> 

class WebServer{
    protected:
        int _socket;
        struct sockaddr_in s_addr;
    public:
        WebServer(int domaine, int type, int protocol, int port, u_long interface);
        ~WebServer();
        int get_socket();
        virtual int  setup() = 0;
};