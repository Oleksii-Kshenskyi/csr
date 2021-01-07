#include <filesystem>
#include <vector>
#include <string>

#include "cli.hxx"

CommandLine::CommandLine(int argc, char** argv): raw_command_line(std::vector<std::string> { argv, argv + argc}) {}

CommandLine& CommandLine::validate() {
    size_t index = 1;
    while(index < this->raw_command_line.size()) {
        if(this->raw_command_line[index] == "-r") {
            if(this->raw_command_line.size() < index + 2) {
                throw Exception("CommandLine::validate(): expected two parameters for -r flag.");
            }
            index += 3;
            continue;
        }
        else if(this->raw_command_line[index] == "-w") {
            if(this->raw_command_line.size() < index + 3) {
                throw Exception("CommandLine::validate(): expected three parameters for -w flag.");
            }
            index += 4;
            continue;
        }
        else if(!std::filesystem::exists(this->raw_command_line[index])) {
            throw Exception("CommandLine::validate(): expected -r flag with two parameters, -w flag with 3 parameters or an existing file name.");
        }
        else {
            index += 1;
            continue;
        }
    }

    return *this;
}

CommandLine& CommandLine::parse() {
    std::vector<std::string> filenames {};
    std::vector<ReadWriteAction> actions {};
    if(this->raw_command_line.size() <= 1) {
        throw Exception("CommandLine::parse(): expected at least one command line argument.");
    }

    size_t index = 1;
    while(index < this->raw_command_line.size()) {
        if(this->raw_command_line[index] == "-r") {
            actions.push_back(ReadWriteAction(RWMode::Read, this->raw_command_line[index + 1], this->raw_command_line[index + 2], ""));
            index += 3;
        }
        else if(this->raw_command_line[index] == "-w") {
            actions.push_back(ReadWriteAction(RWMode::Write, this->raw_command_line[index + 1], this->raw_command_line[index + 2], this->raw_command_line[index + 3]));
            index += 4;
        }
        else {
            filenames.push_back(this->raw_command_line[index]);
            index += 1;
        }
    }

    if(filenames.size() != 1) {
        throw Exception(StringWrapper("Expected exactly one positional argument. Encountered ").append(filenames.size()).append(" of them.").to_std_str());
    }
    else {
        this->file_name = filenames[0];
    }

    if(actions.size() == 0) {
        this->mode = CLMode::WholeFile;
    }
    else {
        this->mode = CLMode::Params;
    }

    this->read_write_list = actions;
    return *this;
}

CLMode CommandLine::get_mode() {
    return this->mode;
}

std::string CommandLine::get_file_name() {
    return this->file_name;
}

std::vector<ReadWriteAction> CommandLine::get_read_write_list() {
    return this->read_write_list;
}
