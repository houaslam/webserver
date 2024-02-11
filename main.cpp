#include "webserv.hpp"

int main(int ac, char **av){
    std::ifstream file;
    std::string line;
    if (ac == 2){
        file.open(av[1]);
        getline(file, line) ;
        std::cout << line << std::endl;
        file.close();
    }
}

