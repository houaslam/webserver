#pragma once

#include "webserv.hpp"
#include "Request.hpp"


class Response{
	private:
		int status;
		std::string httpv;
		std::string body;
		std::string response;
		std::map<int, std::string> all_status;
	public:
		// CANONICAL FORM
		Response();
		Response(Response& src);
		Response& operator=(Response& src);
		~Response();

		// METHODS
		void Post(Request& request);
		void Delete(Request& request);
		void Get(Request& request);

		// SETERS
		void set_status(int status);
		void set_response(std::string response);
		void set_httpv(std::string httpv);
		void set_all_status(std::string httpv);

		// GETERS 
		int get_status() const;
		std::string get_httpv() const;
		std::string get_response() const;
		void get_all_status(std::string httpv);

		
};