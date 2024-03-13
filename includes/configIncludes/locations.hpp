#pragma once

#include "../webserv.hpp"
using namespace std;

class locations{
    private:
		string root;
		string index;
    public:
    // C FORM
    	locations();
		locations(const locations& src);
		locations& operator=(const locations& src);
		~locations();

	// SETERS
		void setRoot(string root);
		void setIndex(string index);

	// GETERS
		string getRoot();
		string getIndex();

	// OTHERS
		int i;
};
