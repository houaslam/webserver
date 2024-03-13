#pragma once

#include "../webserv.hpp"
#include "locations.hpp"
#include "servers.hpp"

# define LSBRACKET 0
# define RSBRACKET 1
# define SERVER 2
# define ELEMENTS 3

using namespace std;

class config{
    private:
        vector<servers> server;
    public:
		int size; //how many servers we have
		bool serverIsOpen;
		bool locationIsOpen;
		
    // C FORM
    	config();
		config(const config& src);
		config(vector<servers> &server);
		config& operator=(const config& src);
		~config();

	// SETERS
		void setServers(vector<servers>& obj);
		void setServer(servers &obj);

	// GETERS
		vector<servers>& getServers();
		
	//Others
		void configParse(config &config);
		void serverParse(vector<int> &flags, string content);
		void portParse(string content, config &config);
		void serverNameParse(string content, config &config);
		void rootParse(string content, config &config);
		void maxBodyParse(string content, config &config);
		void indexParse(string content, config &config);
		
};

string getContent(string name, string line, size_t pos);
int isLBrackets(string str);