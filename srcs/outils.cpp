#include "../includes/webserv.hpp"

std::string nb_to_string(int nb){
    std::ostringstream test;
    test << nb;
    return test.str();
}

int string_to_number(string str){
    int nb = 0;
    stringstream ss(str);

    ss >> nb;

    return nb;
}

bool isInteger(const string& str){
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

std::vector<std::string> split(std::string src, std::string s) {
    std::vector<std::string> ret;
    std::string str;

    size_t i = 0;
    size_t len = src.length();

    while (i < len) {
        size_t found = src.find(s, i);
        if (found > len) {
            str = src.substr(i); 
            i = len;
        }
        else {
            str = src.substr(i, found - i);
            i = found + s.length();
        }

        if (!str.empty()) {
            ret.push_back(str);
        }
    }

    return ret;
}

template <typename T>
T split(std::string src, std::string s) {
    T ret;
    std::string str;

    size_t i = 0;
    size_t len = src.length();

    while (i < len) {
        size_t found = src.find(s, i);
        if (found > len) {
            str = src.substr(i); 
            i = len;
        }
        else {
            str = src.substr(i, found - i);
            i = found + s.length();
        }

        if (!str.empty()) {
            ret.push_back(str);
        }
    }

    return ret;
}


std::string strtrim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start])) {
        start++;
    }

    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1])) {
        end--;
    }

    return str.substr(start, end - start);
}

void ft_error(string msg){
    perror(msg.c_str());
    exit(1);
}