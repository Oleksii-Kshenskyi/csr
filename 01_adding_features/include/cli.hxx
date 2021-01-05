#ifndef CLI_HXX
#define CLI_HXX

#include <string>
#include <vector>

#include "util.hxx"

class CommandLine {
    public:
        CommandLine(int argc, char** argv);
        CommandLine& validate();
        CommandLine& parse();
        CLMode get_mode();
        std::string get_file_name();
        std::vector<ReadWriteAction> get_read_write_list();
    private:
        CLMode mode;
        std::string file_name;
        std::vector<ReadWriteAction> read_write_list;
        std::vector<std::string> raw_command_line;
};

#endif
