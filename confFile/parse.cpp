#include "../includes/Server.hpp"

// void fill_map(std::string name, std::string content, config &config){
//     // checkBasicErrors
//     // if (name == "error_page"){
//     // }
//     if (name == "listen")
//         name = "port";
//     //check if ';' in the end later
//     size_t semicolonPos = content.find(';');
//     if (semicolonPos != std::string::npos) {
//         content.erase(semicolonPos, 1);
//     }
//     // server.conf.insert((std::make_pair(name, content)));
//     // std::cout << " | " << name << " | \n" << content << std::endl; 
// }

void parse_line(std::string line, config &config){
    size_t pos;
    std::string name;
    std::string content;
    // int flag[5];

    config.getConfig();

    line = strtrim(line);
    pos = line.find_first_of(" \t");
    if (pos == std::string::npos || line.empty())
        return;
    name = line.substr(0, pos);
    content = strtrim(line.substr(pos, line.length()));

    // if (name == "server")
    //     config.serverParse(flag, name, content, config);
    // fill_map(name, content, config);
}

void config::configParse(config &config){
    std::string filename = "/nfs/homes/fadermou/Desktop/webserver/confFile/files/default";
    std::ifstream ifs(filename.c_str());

    if (!ifs.is_open())
            return ; //add error cases

    std::string line;

    while (getline(ifs, line)){
        parse_line(line, config);
    }
}
