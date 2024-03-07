#include "includes/webserv.hpp"
#include "includes/Server.hpp"
#include "includes/Client.hpp"

int main(){
    Server server(AF_INET, SOCK_STREAM, 0, 8080, inet_addr("127.0.0.1"));
    std::string response;
    std::string file;
    char request[1024];

    if (server.setup() == 1)
        std::cout << "Setup failed\n";
    
    std::cout << "Server listening on port 8080...\n";

    response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
    while (true) {
        try{
            Client client(server);
		    read(client.get_socket(), request, sizeof(request));
		    server.parseRequest(request);
		    std::cout << "\nCLIENT REQUEST:\n" << request << std::endl;
            server.generateResponse(server.get_request());
		    send(client.get_socket(), response.c_str(),response.length(), 0);
		    close(client.get_socket());
        }
        catch(std::exception& e){
            std::cout << e.what() << std::endl;
            continue;
        }

    }
}
