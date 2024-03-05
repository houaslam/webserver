#include "includes/webserv.hpp"
#include "includes/Server.hpp"
#include "includes/Client.hpp"

std::string nb_to_string(int nb){
    std::ostringstream test;
    test << nb;
    return test.str();
}

int main(){
    Server web(AF_INET, SOCK_STREAM, 0, 8080, inet_addr("127.0.0.1")); // <----- multiplexing part
    std::string response;
    std::string file;
    char request[1024];

    if (web.setup() == 1)
        std::cout << "Setup failed\n";
    
    std::cout << "Server listening on port 8080...\n";

    response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";;
    while (true) {
		int clientSocket = accept(web.get_socket(), NULL, NULL);
		if (clientSocket == -1) {
		    std::cerr << "Error accepting connection\n";
		    break;
		}
		read(clientSocket, request, sizeof(request)); // <<------- request part

		std::cout << "\nCLIENT REQUEST:\n" << request << std::endl;
		send(clientSocket, response.c_str(),response.length(), 0); // <----response part
		std::cout << "\nDONE\n" << request << std::endl;

		// std::cout << "server response sent!\n";
		close(clientSocket);
    }
}
