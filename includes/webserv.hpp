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
#include <cctype>
#include "configIncludes/config.hpp"

using namespace std;

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
		socklen_t  get_addr_len();
		virtual int  setup() = 0;
};


string nb_to_string(int nb);
vector<string> split(string src, string s);
string strtrim(const string& str);