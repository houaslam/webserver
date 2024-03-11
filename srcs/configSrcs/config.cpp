#include "../../includes/configIncludes/config.hpp"

// C FORM
config::config(){}

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

// GETERS
vector<servers>& config::getConfig(){
	return this->server;
}
