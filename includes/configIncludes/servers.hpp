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
		string index;
        vector<class locations> location;
    public:
		int locSize; //how many locations we have
    
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
		void setIndex(string index);
		void setLocations(vector<locations>& location);
		void setLocation(locations &obj);
	
	// GETERS
		int getMaxBody();
		int getPort();
		string getHost();
		string getServerName();
		string getRoot();
		string getIndex();
		vector<locations>&  getLocations();
	//OTHERS
		vector<int> flags;
		int i;

};