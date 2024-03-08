#pragma once

#include "webserv.hpp"


class Request{
	private:
		std::map< std::string , std::string > headers;
		std::string method;
		std::string path;
		std::string httpv;
	public:
		Request();
		Request(Request& src);
		Request& operator=(Request& src);
		~Request();

		void set_header(std::string& key, std::string& value);
		void set_headers(std::map< std::string , std::string > headers);
		void set_method(std::string method);
		void set_path(std::string path);
		void set_httpv(std::string httpv);

		std::string& get_header(std::string& key);
		std::map< std::string , std::string >& get_headers();
		std::string& get_method();
		std::string& get_path();
		std::string& get_httpv();
};
