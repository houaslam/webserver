#include "../../includes/configIncludes/config.hpp"

// C FORM
servers::servers(){}

servers::~servers(){}

servers::servers(const servers& src){
	*this = src;}

servers& servers::operator=(const servers& src){
	if (this != &src){
		this->maxBody = src.maxBody;
		this->port = src.port;
		this->host = src.host;
		this->serverName = src.serverName;
		this->root = src.root;
		// this->location = src.location;
    }
	return *this;
}

// SETTER
void servers::setMaxBody(int maxBody){
	this->maxBody = maxBody;
}
void servers::setPort(int port){
	this->port = port;
}
void servers::setHost(string host){
	this->host = host;
}
void servers::setServerName(string serverName){
	this->serverName = serverName;
}
void servers::setRoot(string root){
	this->root = root;
}
// void servers::setLocation(vector<locations>& location){
// 	this->location = location;
// }

// GETERS
int servers::getMaxBody(){
	return this->maxBody;
}
int servers::getPort(){
	return this->port;
}
string servers::getHost(){
	return this->host;
}
string servers::getServerName(){
	return this->serverName;
}
string servers::getRoot(){
	return this->root;
}
// vector<locations>& servers::getLocations(){
// 	return this->location;
// }
