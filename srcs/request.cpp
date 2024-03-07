#include "../includes/Request.hpp"

Request::Request(){
}

Request::Request(Request& src){
    *this = src;
}

Request& Request::operator=(Request& src){
    if (this != &src){
        this->headers = src.headers;
        this->path = src.path;
        this->method = src.method;
        this->httpv = src.httpv;
    }
    return *this;
}

Request::~Request(){

}

void Request::set_header(std::string& key, std::string& value){
    this->headers[key] = value;
}
void Request::set_headers(std::map< std::string , std::string > headers){
    this->headers = headers;
}
void Request::set_method(std::string method){
    this->method = method;
}
void Request::set_path(std::string path){
    this->path = path;
}
void Request::set_httpv(std::string httpv){
    this->httpv = httpv;
}




std::string& Request::get_header(std::string& key){
    return this->headers[key];
}
std::map< std::string , std::string >& Request::get_headers(){
    return headers;
}
std::string& Request::get_method(){
    return this->method;
}
std::string& Request::get_path(){
    return this->path;
}
std::string& Request::get_httpv(){
    return this->httpv;
}