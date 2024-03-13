#include "../../includes/configIncludes/locations.hpp"
#include "../../includes/configIncludes/config.hpp"
#include "../../includes/Server.hpp"

// C FORM
locations::locations():root(""), index(""){
	i = 0;
}

locations::~locations(){}

locations::locations(const locations& src){
	*this = src;
}

locations& locations::operator=(const locations& src){
	if (this != &src){
		this->root = src.root;
		this->index = src.index;
		this->i = src.i;
	}

	return *this;
}
// SETTERS
void locations::setRoot(string root){
	this->root = root;
}
void locations::setIndex(string index){
	this->index = index;
}

// GETERS
string locations::getRoot(){
	return this->root;
}
string locations::getIndex(){
	return this->index;
}