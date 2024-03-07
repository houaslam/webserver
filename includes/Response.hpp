#pragma once

#include "webserv.hpp"
#include "Request.hpp"


class Response{
    private:
        int status;
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

        // GETERS 
        int get_status() const;
        
};