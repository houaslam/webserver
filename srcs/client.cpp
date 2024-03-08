#include "../includes/Client.hpp" 
  
Client::Client(Server& server): WebServer(AF_INET, SOCK_STREAM, 0, 0, 0){

	socklen_t add_len  = sizeof(server.get_addr());
	this->_socket  = accept(server.get_socket(), (struct sockaddr*)&server.get_addr(), &add_len);

	if (this->_socket < 0){
		perror("socket creation failed!");
		exit(1);
	}
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

// int Client::setup_(Server& server){
//     if (accept(this->_socket, (struct sockaddr*)&server.get_addr(), (socklen_t *)sizeof(server.get_addr())));
// }


int Client::setup(){
	return 0;
}
