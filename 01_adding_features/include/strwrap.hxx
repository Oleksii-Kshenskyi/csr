#ifndef STRWRAP_HXX
#define STRWRAP_HXX

#include <iostream>
#include <vector>
#include <string>

#include "vecwrap.hxx"

class StringWrapper {
    public:
        StringWrapper(std::string new_value);
        std::string to_std_str();
        StringWrapper& operator=(const std::string& std_str);
        VectorWrapper split(const std::string& delim);
        StringWrapper& append(const std::string& tail);
        StringWrapper& append(const size_t& tail);
        StringWrapper& trim();
        StringWrapper& ltrim();
        StringWrapper& rtrim();
    private:
        std::string buffer;
};

#endif
