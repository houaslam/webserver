#include "includes/webserv.hpp"
#include "includes/Server.hpp"
#include "includes/Client.hpp"

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// int main() {
//     // Create a socket
//     int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//     if (serverSocket == -1) {
//         std::cerr << "Error creating socket\n";
//         return -1;
//     }

//     // Set up the server address struct
//     sockaddr_in serverAddress;
//     std::memset(&serverAddress, 0, sizeof(serverAddress));
//     serverAddress.sin_family = AF_INET;
//     serverAddress.sin_addr.s_addr = INADDR_ANY;
//     serverAddress.sin_port = htons(8080);  // Use any available port you prefer

//     // Bind the socket to the specified address and port
//     if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
//         std::cerr << "Error binding socket\n";
//         close(serverSocket);
//         return -1;
//     }

//     // Listen for incoming connections
//     if (listen(serverSocket, 10) == -1) {
//         std::cerr << "Error listening on socket\n";
//         close(serverSocket);
//         return -1;
//     }

//     std::cout << "Server listening on port 8080...\n";

//     while (true) {
//         // Accept a connection
//         int clientSocket = accept(serverSocket, NULL, NULL);
//         if (clientSocket == -1) {
//             std::cerr << "Error accepting connection\n";
//             continue;
//         }

//         // Send a simple HTTP response to the web browser
//         const char* httpResponse = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
//         send(clientSocket, httpResponse, strlen(httpResponse), 0);

//         // Close the client socket
//         close(clientSocket);
//     }

//     // Close the server socket
//     close(serverSocket);

//     return 0;
// }


// // void *client(void *arg){
// //     struct sockaddr_in c_addr;
// //     c_addr.sin_port = htons(8080);
// //     c_addr.sin_family = AF_INET;
// //     socklen_t c_len = sizeof(c_addr);
// // 	char *msg;
// // 	std::string buff;

// // 	int c_socket = socket(AF_INET, SOCK_STREAM, 0);
// // 	if (c_socket < 0){
// //         std::cerr << "socket creation problem!" << std::endl;
// //         return NULL;
// //     }

// // 	if (inet_pton(AF_INET, "127.0.0.1", &c_addr.sin_addr)  
// //                <= 0) {  
// //                printf(  
// //                        "\nInvalid address/ Address not supported \n");  
// //                return NULL;  
// //     }

// // 	int fd = connect(c_socket, (struct sockaddr*)&c_addr, c_len);
// // 	if (fd < 0){
// // 		std::cerr << "socket connection problem!\n";
// // 		return NULL;
// // 	}

// // 		strcpy(msg, "hello from client side\n");
// //         std::cout << "client sent" << msg;
// //         send(c_socket, NULL, sizeof(msg), 0);
// // 	close(c_socket);
// // 	close(fd);
// // }

  
// void* client_rout(void *arg) 
// {
//     (void)arg;
// 	struct sockaddr_in c_addr;
//     c_addr.sin_port = htons(8080);
//     c_addr.sin_family = AF_INET;
//     socklen_t c_len = sizeof(c_addr);
// 	char msg[1024];
// 	std::string buff;

// 	int c_socket = socket(AF_INET, SOCK_STREAM, 0);
// 	if (c_socket < 0){
//         std::cerr << "socket creation problem!" << std::endl;
//         return NULL;
//     }

// 	if (inet_pton(AF_INET, "127.0.0.1", &c_addr.sin_addr)  
//                <= 0) {  
//                printf(  
//                        "\nInvalid address/ Address not supported \n");  
//                return NULL;  
//     }

// 	int fd = connect(c_socket, (struct sockaddr*)&c_addr, c_len);
// 	if (fd < 0){
// 		std::cerr << "socket connection problem!\n";
// 		return NULL;
// 	}
// 	strcpy(msg, "hello from client side\n");
//     std::cout << "client sent -> " << msg;
//     send(c_socket, msg, strlen(msg) + 1, 0);
// 	close(c_socket);
// 	close(fd);
//     return NULL;
// }  

int main(){
    Server web(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);
    // Server client(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);

    if (web.setup() == 1)
        std::cout << "Setup failed\n";
    
    std::cout << "Server listening on port 8080...\n";

    while (true) {
        int clientSocket = accept(web.get_socket(), NULL, NULL);
        if (clientSocket == -1) {
            std::cerr << "Error accepting connection\n";
            continue;
        }

        const char* httpResponse = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
        send(clientSocket, httpResponse, strlen(httpResponse), 0);

        close(clientSocket);
    }
}
