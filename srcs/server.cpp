#include "../includes/Server.hpp"

void Server::handle_request(std::string request){
    
}

Server::Server(int domain, int type, int protocol, int port, u_long interface) : WebServer(domain, type, protocol, port, interface){
}

Server::~Server(){
    close(this->_socket);
    std::cout << "socket closed!\n";
}

int Server::setup(){
    if (bind(_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) < 0){
        std::cerr << "bind failed!" << std::endl;
        return 1;
    }

    if (listen(_socket, 5) < 0){
        std::cerr << "listen failed!" << std::endl;
        return 1;
    }
    std::cout << "setup done!\n";
    return 0;
}

