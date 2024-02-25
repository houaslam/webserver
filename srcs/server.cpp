#include "../includes/Server.hpp"

// int main(){
    // struct sockaddr_in s_addr;
    // s_addr.sin_port = htons(8080);
    // s_addr.sin_addr.s_addr = INADDR_ANY;
    // s_addr.sin_family = AF_INET;
    // socklen_t s_len = sizeof(s_addr);
    // char* test = "connection established\n waiting.......\n";

    // int s_socket, c_socket, done;
    // char buff[1024];
    // s_socket = socket(AF_INET, SOCK_STREAM, 0);

    // if (s_socket < 0){
    //     std::cerr << "socket creation problem!" << std::endl;
    //     return 1;
    // }

    // if (bind(s_socket, (struct sockaddr*)&s_addr, s_len) < 0){
    //     std::cerr << "socket bind problem!" << std::endl;
    //     return 1;
    // }

    // if (listen(s_socket, 5) < 0){
    //     std::cerr << "socket listen problem!" << std::endl;
    //     return 1;
    // }

//     struct sockaddr_in c_addr;
//     socklen_t c_len = sizeof(c_addr);

//     c_socket = accept(s_socket, (struct sockaddr*)&c_addr, &c_len);
//     if (c_socket < 0){
//         std::cerr << "Socket accept problem!" << std::endl;
//         return 1;
//     }
//     send(c_socket, test, strlen(test), 0);
//     while(true){
//         int k = recv(c_socket, buff, sizeof(buff), 0);
//         if (!buff)
//             break;
//         buff[k] = '\0';
//         std::cout << "client:" << buff << std::endl;
//     }
//     close(c_socket);
//     close(s_socket);
// }

Server::Server(int domain, int type, int protocol, int port, u_long interface) : WebServer(domain, type, protocol, port, interface){
    // std::cout << this->_socket << std::endl;
}

Server::~Server(){
    close(this->_socket);
    std::cout << "socket closed!\n";
}

int Server::setup(){
    if (bind(_socket, (struct sockaddr*)&s_addr, sizeof(s_addr)) < 0){
        std::cerr << "bind failed!" << std::endl;
        return 1;
    }

    if (listen(_socket, 5) < 0){
        std::cerr << "listen failed!" << std::endl;
        return 1;
    }
    std::cout << "setup done!\n";
    return 0;
}

