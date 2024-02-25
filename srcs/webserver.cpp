#include "../includes/webserv.hpp"

WebServer::WebServer(int domaine, int type, int protocol, int port, u_long interface){
    s_addr.sin_port = htons(port);
    s_addr.sin_addr.s_addr = interface;
    s_addr.sin_family = domaine;

    _socket = socket(domaine, type, protocol);

    if (_socket < 0){
        std::cerr << "socket creation problem!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

WebServer::~WebServer(){
    close(this->_socket);
}

int WebServer::get_socket(){
    return this->_socket;
}