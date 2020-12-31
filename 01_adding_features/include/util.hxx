#ifndef UTIL_HXX
#define UTIL_HXX

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "strwrap.hxx"
#include "vecwrap.hxx"

class Exception {
    public:
        Exception(std::string&& new_message);
        const std::string& what();
    private:
        const std::string message;
};

class FileReader {
    public:
        FileReader(const std::string& file_name);
        VectorWrapper lines();
        ~FileReader();
        FileReader& reset();
    private:
        std::ifstream file;
};

#endif
