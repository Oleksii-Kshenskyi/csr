#ifndef VECWRAP_HXX
#define VECWRAP_HXX

#include <vector>
#include <string>
#include <algorithm>

class VectorWrapper {
    public:
        VectorWrapper(std::vector<std::string> other);
        size_t size();
        std::string& operator[](size_t pos);
        std::string join(std::string delim);
        std::string to_std_str();
        VectorWrapper& trim_empty();
    private:
        std::vector<std::string> buffer;
};

#endif
