#pragma once

#include "webserv.hpp"
#include "Request.hpp"


class Response{
    private:
        int status;
    public:
        Response();
        Response(Response& src);
        Response& operator=(Response& src);
        ~Response();

        void Post(Request& request);
        void Delete(Request& request);
        void Get(Request& request);
        
};