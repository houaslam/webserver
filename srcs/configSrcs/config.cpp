#include "../../includes/configIncludes/config.hpp"

// C FORM
config::config(): size(0), locSize(0){}

config::~config(){}

config::config(vector<servers> &server):server(server){}

config::config(const config& src){
	*this = src;
}

config& config::operator=(const config& src){
	if (this != &src)
		this->server = src.server;
	return *this;
}

// SETTER
void config::setServers(vector<servers>& obj){
	this->server = obj;
}
void config::setServer(servers &obj){
	this->server.push_back(obj);
}

// GETERS
vector<servers>& config::getServers(){
	return this->server;
}
