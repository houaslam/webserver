#include "../includes/webserv.hpp"

WebServer::WebServer(int domaine, int type, int protocol, int port, u_long interface){
    s_addr.sin_port = htons(port);
    s_addr.sin_addr.s_addr = interface;
    s_addr.sin_family = domaine;

    _socket = socket(domaine, type, protocol);

    if (_socket < 0){
        perror("socket creation problem!");
        exit(1);
    }
}

WebServer::~WebServer(){
    close(this->_socket);
}

int WebServer::get_socket(){
    return this->_socket;
}

struct sockaddr_in& WebServer::get_addr(){
    return this->s_addr;
}

socklen_t  WebServer::get_addr_len(){
    return sizeof(this->s_addr);
}

// socklen_t WebServer::get_addr_len() {
//     return sizeof(this->s_addr);
// }


WebServer::WebServer(WebServer& src){
    if (this != &src){
        this->_socket = src._socket;
        this->s_addr = src.s_addr;
    }
}

// socklen_t& WebServer::get_addr_len(){
//     return this->s_addr;
// }
