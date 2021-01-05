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

enum class CLMode {
    WholeFile,
    Params
};

enum class RWMode {
    Read,
    Write
};

struct ReadWriteAction {
        ReadWriteAction(RWMode new_mode, std::string new_section_name, std::string new_name, std::string new_value);
        RWMode mode;
        std::string section_name;
        std::string parameter_name;
        std::string parameter_value;
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
