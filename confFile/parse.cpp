#include "../includes/Server.hpp"

// bool open_file(std::string filename){
//     std::ofstream ifs(filename.c_str());
//     if (!ifs.is_open()){
//         // std::cerr << filename << " : No such a file or directory\n";
//         return false;
//     }
// }


void read_file(std::ifstream ifs){
    std::string line;

    while (getline(ifs, line)){
        std::cout << line << "\n";
    }
}


bool parse_line(std::string line){
    
}
int main(){
    std::string filename = "files/default";
    std::ifstream ifs(filename.c_str());
    
    if (!ifs.is_open()){
        // std::cerr << filename << " : No such a file or directory\n";
        return 1;
    }

    // read_file(ifs);
    std::string line;

    while (getline(ifs, line)){
        parse_line(line);
    }
}
