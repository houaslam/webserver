#include "../../includes/configIncludes/config.hpp"

// C FORM
servers::servers():  maxBody(0),port(0), host("127.0.0.1"), serverName(""), \
root(""), index(""){
	i = 0;
	locSize = 0;
	for (size_t i = 0; i < 5; i++)
	{
		flags.push_back(0);
	}
}

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
		this->flags = src.flags;
		this->index = src.index;
		this->i = src.i;
		this->location = src.location;
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
void servers::setLocations(vector<locations>& location){
	this->location = location;
}

void servers::setLocation(locations &obj){
	this->location.push_back(obj);
}

void servers::setIndex(string index){
	this->index = index;
}

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
string servers::getIndex(){
	return this->index;
}
vector<locations>& servers::getLocations(){
	return this->location;
}