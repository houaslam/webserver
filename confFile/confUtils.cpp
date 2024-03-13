#include "../includes/configIncludes/config.hpp"
#include "../includes/Server.hpp"

int isLBrackets(string str){
    if (str != "{")
        return 0;
    return 1;
}

string getContent(string name, string line, size_t pos){
    string content = "";
    content = strtrim(line.substr(pos, line.length()));

    if ((name != "server" && name != "{" && name != "}" && name != "location" \
    && name[0] != '#' && !line.empty()) && content[content.size() - 1] != ';') {
        std::cout << "[" << content << "]" << "\n";
        perror("Error in config file\n");
		exit(1);
    }

    size_t semicolonPos = content.find(';');

    if (semicolonPos != string::npos) {
        content.erase(semicolonPos, 1);
    }

    return content;
}