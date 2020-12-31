#include "vecwrap.hxx"

VectorWrapper::VectorWrapper(std::vector<std::string> other): buffer(other) {}

size_t VectorWrapper::size() {
    return this->buffer.size();
}

std::string& VectorWrapper::operator[](size_t pos) {
    return this->buffer[pos];
}

std::string VectorWrapper::join(std::string delim) {
    std::string strified_vec { "" };
    for(size_t index = 0; index < buffer.size(); index++) {
        strified_vec += buffer[index];
        if(index != buffer.size() - 1) {
            strified_vec += delim;
        }
    }
    return strified_vec;
}

std::string VectorWrapper::to_std_str() {
    return this->join("\n");
}

VectorWrapper& VectorWrapper::trim_empty() {
    this->buffer.erase(std::remove(this->buffer.begin(), this->buffer.end(), ""), this->buffer.end());

    return *this;
}
