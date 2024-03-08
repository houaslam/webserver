#pragma once

#include "webserv.hpp"
#include "Request.hpp"
#include "Response.hpp"

class Server : public WebServer{
	private:
		Request request;
		Response response;
	public:
	// CANONICAL FORM
		Server(int domaine, int type, int protocol, int port, u_long interface);
		Server(Server& src);
		Server& operator=(Server& src);
		~Server();

	// SETERS
		void set_request(Request& request);
		void set_response(Response& response);

	// GETERS
		Request& get_request();
		Response& get_response();

	// REGUAL FUNCTION
		virtual int setup();
		void parseRequest(std::string request);
		void generateResponse(Request& request);
};
