#include "../includes/Client.hpp" 
  
// int main()  
// {
// 	struct sockaddr_in c_addr;
//     c_addr.sin_port = htons(8080);
//     c_addr.sin_family = AF_INET;
//     socklen_t c_len = sizeof(c_addr);
// 	char msg[1024];
// 	std::string buff;

// 	int c_socket = socket(AF_INET, SOCK_STREAM, 0);
// 	if (c_socket < 0){
//         std::cerr << "socket creation problem!" << std::endl;
//         return 1;
//     }

// 	if (inet_pton(AF_INET, "127.0.0.1", &c_addr.sin_addr)  
//                <= 0) {  
//                printf(  
//                        "\nInvalid address/ Address not supported \n");  
//                return -1;  
//     }

// 	int fd = connect(c_socket, (struct sockaddr*)&c_addr, c_len);
// 	if (fd < 0){
// 		std::cerr << "socket connection problem!\n";
// 		return 1;
// 	}
// 	strcpy(msg, "hello from client side\n");
//     std::cout << "client sent -> " << msg;
//     send(c_socket, msg, strlen(msg) + 1, 0);
// 	close(c_socket);
// 	close(fd);
// }  
  