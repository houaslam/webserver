#include "../../includes/configIncludes/locations.hpp"

// C FORM
locations::locations(){}

locations::~locations(){}

locations::locations(const locations& src){
	*this = src;
}

locations& locations::operator=(const locations& src){
	if (this != &src)
		this->root = src.root;
	return *this;
}

// SETTER
void locations::setRoot(string root){
	this->root = root;
}

// GETERS
string locations::getRoot(){
	return this->root;
}
