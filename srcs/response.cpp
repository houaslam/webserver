#include "../includes/Response.hpp"

Response::Response(){

}

Response::Response(Response& src){
	*this = src;
}

Response& Response::operator=(Response& src){
	if (this != &src){
		this->status = src.status;
	}
	return *this;
}

Response::~Response(){

}

void Response::Post(Request& request){
	std::cout << "POST method called!" << request.get_httpv() << std::endl;
}

void Response::Delete(Request& request){
	std::string file = "htmlFile" + request.get_path();
	std::ifstream req;
	httpv = request.get_httpv();

	std::cout << "DELETE method called!" << request.get_httpv() << std::endl;

	if (access( file.c_str(), F_OK ) < 0){
		this->status = 404;
		perror("File not found");
		return ;
	}

	file = "htmlFile" + request.get_path();
	remove(file.c_str());
	// response = httpv + " " + nb_to_string(status) + "\r\n";
}

void Response::Get(Request& request){
	std::cout << "GET method called! " << request.get_httpv() << std::endl;
	// std::string file = "htmlFile" + request.get_path();
	// std::ifstream req;
	// std::string tmp;

	// if (access( file.c_str(), F_OK ) < 0){
	// 	request.set_path("/404.html");
	// 	file = "htmlFile" + request.get_path();
	// 	std::cout << "file not found\n";
	// }
	// std::cout << "\nfile = " + file + "\n";
	// req.open(file.c_str());
	// std::getline(req, tmp);
	// while(!tmp.empty()){
	// 	response += tmp;
	// 	std::getline(req, tmp);
	// }

}

// SETERS
void Response::set_status(int status){
	this->status = status;
}

void Response::set_response(std::string response){
	this->response = response;
}

void Response::set_httpv(std::string httpv){
    this->httpv = httpv;
}

// GETERS 
int Response::get_status() const{
	return this->status;
}

std::string Response::get_response() const{
	return this->response;
}

std::string Response::get_httpv() const{
	return this->httpv;
}
