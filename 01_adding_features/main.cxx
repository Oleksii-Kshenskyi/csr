#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>

#include "util.cxx"

void usage(std::string message) {
    std::cout << "usage: ./csr1.exe <config_file_name>" << std::endl;
    std::cout << (message.empty() ? "" : message) << std::endl;
}

int main(int argc, char** argv) {
    VectorWrapper vec { std::vector<std::string>(argv, argv + argc) };
    StringWrapper program_name { std::string() };
    StringWrapper file_name { std::string() };
    if(vec.size() != 2) {
        usage("ERROR: wrong number of arguments, expected config file name and nohting more/less.");
        exit(1);
    }
    else {
        program_name = vec[0];
        file_name = vec[1];
    }
    if(!std::filesystem::exists(file_name.clone_to_std_str())) {
        usage("ERROR: file provided in argument doesn't exist.");
        exit(1);
    }

    std::cout << FileReader(file_name.clone_to_std_str()).lines().to_std_str() << std::endl;
}