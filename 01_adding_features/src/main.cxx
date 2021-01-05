#include <iostream>
#include <cstdlib>
#include <string>
#include <filesystem>

#include "util.hxx"
#include "parse.hxx"
#include "cli.hxx"

static void usage(std::string message) {
    std::cout << "usage: ./csr1.exe <config_file_name>" << std::endl;
    std::cout << (message.empty() ? "" : message) << std::endl;
}

int main(int argc, char** argv) {
    // command line checks
    CommandLine command_line(argc, argv);
    try {
        command_line.validate().parse();
    }
    catch(Exception& e) {
        std::cout << "COMMAND LINE PARSING ERROR: " << e.what() << std::endl;
        exit(1);
    }
    
    // actual logic
    if(command_line.get_mode() == CLMode::WholeFile) {
        try {
            std::cout << ConfigFile(command_line.get_file_name()).try_parse_or_throw().to_std_str() << std::endl;
        }
        catch(Exception& e) {
            usage("");
            std::cout << "CONFIG FILE ERROR: " << e.what() << std::endl;
            exit(1);
        }
    }
    else if (command_line.get_mode() == CLMode::Params) {
        try {
            std::cout << ConfigFile(command_line.get_file_name()).try_parse_or_throw().try_read_write_params_or_throw(command_line.get_read_write_list()).to_std_str() << std::endl;
        }
        catch(Exception& e) {
            usage("");
            std::cout << "READ/WRITE PARAMS ERROR: " << e.what() << std::endl;
            exit(1);
        }
    }

    return 0;
}
