#include "../includes/Server.hpp"

void Server::parseRequest(std::string request){
	std::vector<std::string> res = split(request, "\r\n");
	std::vector<std::string> header;

	for(std::vector<std::string>::iterator i = res.begin() + 1; i != res.end(); i++){
		header = split(*i, ": ");
		if (header.size() >= 2)
			this->request.set_header(header[0], header[1]);
	}

	std::string methods[3] = {"POST", "GET", "DELETE"};
	res = split(res[0], " ");
	for (int i = 0;i < 3; i++){
		if (!methods[i].compare(res[0])){
			this->request.set_method(res[0]);
			break;
		}
	}
	this->request.set_path(res[1]);
	this->request.set_httpv(res[2]);
}

int Server::setup(){
	int reuse = 1;

	if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
		perror("set op failed!");
		exit(1);
	}
	if (bind(_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) < 0){
		perror("bind failed!");
		exit(1);
	}

	if (listen(_socket, 5) < 0){
		perror("listen failed!");
		exit(1);
	}
	std::cout << "setup done!\n";
	return 0;
}


void Server::generateResponse(Request& request){
	if (!request.get_method().compare("POST"))
		response.Post(request);
	else if (!request.get_method().compare("GET"))
		response.Get(request);
	else if (!request.get_method().compare("DELETE"))
		response.Delete(request);
	else{
		perror("INVALID METHOD");
		exit(EXIT_FAILURE);
	}
}


// CANONICAL FORM
Server::Server(int domain, int type, int protocol, int port, u_long interface) \
: WebServer(domain, type, protocol, port, interface){
	if (setup() == 1){
		perror("Setup failed");
		exit(1);
	}
}

Server::~Server(){
	close(this->_socket);
	std::cout << "socket closed!\n";
}

Server::Server(Server& src) : WebServer(src){
	*this = src;
}

Server& Server::operator=(Server& src){
	if (this != &src){
		this->request = src.request;
		this->response = src.response;
	}
	return *this;
}


Response& Server::get_response(){
	return this->response;
}

void Server::set_response(Response& response){
	this->response = response;
}

void Server::set_request(Request& request){
	this->request = request;
}

// GETERS
Request& Server::get_request(){
	return this->request;
}
