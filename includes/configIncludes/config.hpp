#pragma once

#include "../webserv.hpp"
#include "servers.hpp"

# define BRACKET 0

using namespace std;

class config{
    private:
        vector<servers> server;
    public:
    // C FORM
    	config();
		config(const config& src);
		config(vector<servers> &server);
		config& operator=(const config& src);
		~config();

	// SETERS
		void setServers(vector<servers>& obj);

	// GETERS
		vector<servers>& getConfig();
		
	//Others
		void configParse(config &config);
		void serverParse(int &flag, string name, string content, config &config);
};