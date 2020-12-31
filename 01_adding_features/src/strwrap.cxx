#include "strwrap.hxx"

#include <cctype>

StringWrapper::StringWrapper(std::string new_value): buffer(new_value) {}

std::string StringWrapper::to_std_str() {
    return this->buffer;
}

StringWrapper& StringWrapper::operator=(const std::string& std_str) {
    this->buffer = std_str;
    return *this;
}

VectorWrapper StringWrapper::split(const std::string& delim) {
    std::vector<std::string> result {};
    size_t prev_index = this->buffer.find(delim);
    size_t curr_index = prev_index;
    if(curr_index == std::string::npos) {
        result.push_back(this->buffer);
        return VectorWrapper { result };
    }

    result.push_back(this->buffer.substr(0, prev_index));
    while((curr_index = this->buffer.find(delim, prev_index + delim.size())) != std::string::npos) {
        result.push_back(this->buffer.substr(prev_index + delim.size(), curr_index - (prev_index + delim.size())));

        prev_index = curr_index;
    }
    result.push_back(this->buffer.substr(prev_index + delim.size(), std::string::npos));

    return VectorWrapper { result };
}

StringWrapper& StringWrapper::append(const std::string& tail) {
    this->buffer += tail;

    return *this;
}

StringWrapper& StringWrapper::append(const size_t& tail) {
    this->buffer += std::to_string(tail);

    return *this;
}

StringWrapper& StringWrapper::ltrim() {
    this->buffer.erase(this->buffer.begin(), std::find_if(this->buffer.begin(), this->buffer.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    return *this;
}

StringWrapper& StringWrapper::rtrim() {
    this->buffer.erase(std::find_if(this->buffer.rbegin(), this->buffer.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), this->buffer.end());

    return *this;
}

StringWrapper& StringWrapper::trim() {
    return this->ltrim().rtrim();
}
