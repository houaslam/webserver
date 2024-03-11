#pragma once

#include "../webserv.hpp"
#include "locations.hpp"

using namespace std;

class servers{
    private:
        int maxBody;
        int port;
        string host;
        string serverName;
        string root;
        // vector<locations> location;
    public:
    // C FORM
    	servers();
		servers(const servers& src);
		servers& operator=(const servers& src);
		~servers();

	// SETERS
		void setMaxBody(int maxBody);
		void setPort(int port);
		void setHost(string host);
		void setServerName(string serverName);
		void setRoot(string root);
		// void setLocation(vector<locations>& location);

	// GETERS
		int getMaxBody();
		int getPort();
		string getHost();
		string getServerName();
		string getRoot();
		// vector<locations>&  getLocations();
};