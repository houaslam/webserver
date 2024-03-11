#pragma once

#include "../webserv.hpp"
using namespace std;

class locations{
    private:
		string root;
    public:
    // C FORM
    	locations();
		locations(const locations& src);
		locations& operator=(const locations& src);
		~locations();

	// SETERS
		void setRoot(string root);
		// void setServers(vector<servers>& obj);//do the same to all of them

	// GETERS
		string getRoot();
		// vector<servers>& getLocations();
};