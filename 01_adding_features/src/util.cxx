#include "util.hxx"

Exception::Exception(std::string&& new_message): message(new_message) {}

const std::string& Exception::what() {
    return this->message;
}


ReadWriteAction::ReadWriteAction(RWMode new_mode, std::string new_section_name, std::string new_name, std::string new_value): mode(new_mode), section_name(new_section_name), parameter_name(new_name), parameter_value(new_value) {}


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

FileWriter::FileWriter(const std::string& file_name): file(std::ofstream(file_name)), name(file_name) {}

FileWriter& FileWriter::trunc_mode() {
    if(this->file.is_open()) {
        file.close();
    }
    file.open(this->name, std::ios::trunc);

    return *this;
}

FileWriter& FileWriter::write_line(std::string write_me) {
    this->file << write_me;

    return *this;
}

FileWriter& FileWriter::close() {
    this->file.close();

    return *this;
}

