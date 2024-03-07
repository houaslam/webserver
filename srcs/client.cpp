#include "../includes/Client.hpp" 
  
Client::Client(Server &server): WebServer(AF_INET, SOCK_STREAM, 0, 0, 0){
    this->_socket = accept(server.get_socket(), NULL, NULL);
    // std::cout << "here--->" << server.get_socket() << std::endl;
    if (this->_socket < 0)
        throw std::runtime_error("socket creation failed!");
}

Client::Client(Client& src) : WebServer(src){
    *this = src;
}

// Client& Client::operator=(Client& src){
//     // if (this != &src){
//     //     this->status = src.status;
//     // }
    
//     return *this;
// }

Client::~Client(){
    close(this->_socket);
}


int Client::setup(){
    return 0;
}
