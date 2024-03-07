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
    std::cout << "DELETE method called!" << request.get_httpv() << std::endl;
}

void Response::Get(Request& request){
    std::cout << "GET method called!" << request.get_httpv() << std::endl;
}

