#pragma once

#include <sstream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <map>
#include <vector>  
#include <sys/socket.h>  
#include <string>

class WebServer{
    protected:
        int _socket;
        struct sockaddr_in s_addr;
    public:
        WebServer(int domaine, int type, int protocol, int port, u_long interface);
        ~WebServer();
        WebServer(WebServer& src);
        int get_socket();
        struct sockaddr_in& get_addr();
        virtual int  setup() = 0;
};


std::string nb_to_string(int nb);
std::vector<std::string> split(std::string src, std::string s);