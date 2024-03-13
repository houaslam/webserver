#include "../includes/Server.hpp"
#include "../includes/configIncludes/config.hpp"

// string getContent(string name, string line, size_t pos){
//     string content = "";
//     content = strtrim(line.substr(pos, line.length()));
//     if ((name != "server" && name != "{" && name != "}" && name != "location" \
//     && name[0] != '#' && !line.empty()) && content[content.size() - 1] != ';') {
//         std::cout << "[" << content << "]" << "\n";
//         perror("Error in config file\n");
// 		exit(1);
//     }
//     size_t semicolonPos = content.find(';');
//     if (semicolonPos != string::npos) {
//         content.erase(semicolonPos, 1);
//     }
//     return content;
// }

void parse_line(string line, config &config){
    size_t pos;
    string name;
    string content;

    line = strtrim(line);
    pos = line.find_first_of(" \t");

    if (line.empty() || line[0] == '#')
        return;
    
    name = line.substr(0, pos);

    if (pos != string::npos || line.empty())
        content = getContent(name, line, pos);

    if (name == "server"){
        servers server;
        server.i = config.size++;
        config.serverIsOpen = true;
        config.serverParse(server.flags, content);
        config.setServer(server);
    }

    if (name == "location")
    {
        if (config.serverIsOpen == false)
            ft_error("Config file invalid\n");
        locations location;
        config.locationIsOpen = true;
        location.i = config.getServers()[config.size - 1].locSize++;
        //parse func
        config.getServers()[config.size - 1].setLocation(location);

    }
        // config.portParse(content, config);

    if (name == "listen")
        config.portParse(content, config);
    if (name == "host" && content != "127.0.0.1"){
        ft_error("invalid host");
    }
    if (name == "server_name")
        config.serverNameParse(content, config);
    if (name == "root")
        config.rootParse(content, config);
    if (name == "client_max_body_size")
        config.maxBodyParse(content, config);
    // if (name == "index")
    //     config.indexParse(content, config);

}//RSBRACKET IN THE END: CHECK IF THE IMPORTANT 5 ELEMENTS ARE THERE

void config::configParse(config &config){
    string filename = "/nfs/homes/fadermou/Desktop/webserver/confFile/files/default";
    ifstream ifs(filename.c_str());

    if (!ifs.is_open())
            return ; //add error cases

    string line;
    serverIsOpen = 0;
    locationIsOpen = 0;

    while (getline(ifs, line)){
        parse_line(line, config);
    }
    for (int i = 0; i < config.size; i++)
    {
        std::cout << "Port = [" << config.getServers()[i].getPort() << "]" << std::endl; 
        std::cout << "Host = [" << config.getServers()[i].getHost() << "]" << std::endl; 
        std::cout << "ServerName = [" << config.getServers()[i].getServerName() << "]" << std::endl; 
        std::cout << "root = [" << config.getServers()[i].getRoot() << "]" << std::endl; 
        std::cout << "maxBodySize = [" << config.getServers()[i].getMaxBody() << "]" << std::endl; 
    }
    
}
