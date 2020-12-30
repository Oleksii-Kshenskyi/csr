#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class StringWrapper {
    public:
        StringWrapper(std::string new_value): buffer(new_value) {}
        std::string clone_to_std_str() {
            return this->buffer;
        }
        StringWrapper& operator=(const std::string& std_str) {
            this->buffer = std_str;
            return *this;
        }
    private:
        std::string buffer;
};

class VectorWrapper {
    public:
        VectorWrapper(std::vector<std::string> other): buffer(other) {}
        size_t size() {
            return this->buffer.size();
        }
        std::string& operator[](size_t pos) {
            return this->buffer[pos];
        }
        std::string join(std::string delim) {
            std::string strified_vec { "" };
            for(size_t index = 0; index < buffer.size(); index++) {
                strified_vec += buffer[index];
                if(index != buffer.size() - 1) {
                    strified_vec += delim;
                }
            }
            return strified_vec;
        }
        std::string to_std_str() {
            return this->join("\n");
        }

    private:
        std::vector<std::string> buffer;
};

class FileReader {
    public:
        FileReader(std::string&& file_name): file(std::ifstream(file_name)) {}
        VectorWrapper lines() {
            std::vector<std::string> lines_vec{};
            for(std::string line; std::getline(this->file, line, '\n'); ) {
                lines_vec.push_back(line);
            }

            this->reset();
            return VectorWrapper { lines_vec };
        }
        ~FileReader() {
            file.close();
        }
        FileReader& reset() {
            this->file.clear();
            this->file.seekg(0);

            return *this;
        }
    private:
        std::ifstream file;
};