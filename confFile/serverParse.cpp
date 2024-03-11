#include "../includes/Server.hpp"

void config::serverParse(int &flags, string name, string content, config &config){
    vector<string> line;

    line = split(content, " ");
    if (line.size() == 1)
}
