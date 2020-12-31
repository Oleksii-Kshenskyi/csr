#include "util.hxx"

Exception::Exception(std::string&& new_message): message(new_message) {}

const std::string& Exception::what() {
    return this->message;
}

FileReader::FileReader(const std::string& file_name): file(std::ifstream(file_name)) {}

VectorWrapper FileReader::lines() {
    std::vector<std::string> lines_vec{};
    for(std::string line; std::getline(this->file, line, '\n'); ) {
        lines_vec.push_back(line);
    }

    this->reset();
    return VectorWrapper { lines_vec };
}

FileReader::~FileReader() {
    file.close();
}

FileReader& FileReader::reset() {
    this->file.clear();
    this->file.seekg(0);

    return *this;
}
