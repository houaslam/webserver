#include "../includes/Server.hpp"
#include "../includes/configIncludes/config.hpp"

void config::serverParse(vector<int> &flags, string content){

    if(flags[SERVER] != 0)//show error
    {
        perror("Error in config file\n");
		exit(1);
    }

    flags[SERVER]++;

    if (content.empty())
        return;
    if (content == "{")
        flags[LSBRACKET]++;
    else//show error
    {
        perror("Error in config file\n");
		exit(1);
    }
}

void config::portParse(string content, config &config){
    int port;

    port = atoi(content.c_str());
    if (port > 65535 || !isInteger(content))//!show error        
        ft_error("Port out of range\n");
    config.getServers()[size - 1].setPort(port);
    
}

void config::serverNameParse(string content, config &config){

    for (int i = 0; i < config.size; i++){
        if (config.getServers()[i].getServerName() == content)
            ft_error("Error name multiplied\n");
    }
    config.getServers()[size - 1].setServerName(content);
    
}

void config::rootParse(string content, config &config){
    // if (config.locationIsOpen == true)
    //     config.getServers()[size - 1].getLocations()[(config.getServers()[size - 1].locSize) - 1].setRoot(content);
    // else
        config.getServers()[size - 1].setRoot(content);
}

void config::indexParse(string content, config &config){
    if (config.locationIsOpen == true)
        config.getServers()[size - 1].getLocations()[config.getServers()[size - 1].locSize - 1].setIndex(content);
    else
        config.getServers()[size - 1].setIndex(content);

}
void config::maxBodyParse(string content, config &config){
    int max;

    max = atoi(content.c_str());
    if (max > 1048576)
        ft_error("Request Entity Too Large\n");
    config.getServers()[size - 1].setRoot(content);
}
