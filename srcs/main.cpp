#include "../includes/webserv.hpp"
#include "../includes/Server.hpp"
#include "../includes/Client.hpp"

int main(){
	Server server(AF_INET, SOCK_STREAM, 0, 8080, inet_addr("127.0.0.1"));
	char request[1024];
    
	server.get_response().set_response("HTTP/1.1 200\r\nContent-Type: text/html\r\n\r\n");

	while (true) {

		std::cout << "\nWAITING\n";
		Client client(server);
		std::cout << server.get_response().get_response() << std::endl;

		if (read(client.get_socket(), request, sizeof(request)) <= 0)
			break;

		std::cout << "\nCLIENT REQUEST:\n" << request << std::endl;

		server.parseRequest(request);

		server.generateResponse(server.get_request());

		send(client.get_socket(), server.get_response().get_response().c_str(),\
		server.get_response().get_response().length(), 0);
		std::cerr << "\nRESPONSE SENT\n";
		close(client.get_socket());
    }
}
