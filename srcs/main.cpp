#include "../includes/webserv.hpp"
#include "../includes/Server.hpp"
#include "../includes/Client.hpp"

int main(){
    Server server(AF_INET, SOCK_STREAM, 0, 8080, inet_addr("127.0.0.1"));
    std::string response;
    char request[1024];
    int reuse = 1;

    if (setsockopt(server.get_socket(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        std::cerr << "Error setting SO_REUSEADDR option\n";
        close(server.get_socket());
        return -1;
    }

    if (server.setup() == 1){
        perror("Setup failed");
        exit(1);
    }
    
    std::cout << "Server listening on port 8080...\n";

    response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
    Client client(server);
    std::cout << client.get_socket() << std::endl;
    // if (connect(client.get_socket(), (struct sockaddr*)&server.get_addr(), sizeof(server.get_addr())) < 0 ){
    //     perror("connect problem!");
    //     exit(1);
    // }
    while (true) {
		    read(client.get_socket(), request, sizeof(request));
		    server.parseRequest(request);
		    std::cout << "\nCLIENT REQUEST:\n" << request << std::endl;
            server.generateResponse(server.get_request());
		    send(client.get_socket(), response.c_str(),response.length(), 0);
		    // close(client.get_socket());
    }

}
