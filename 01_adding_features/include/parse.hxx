#ifndef PARSE_HXX
#define PARSE_HXX

#include "vecwrap.hxx"
#include "util.hxx"

class ConfigParam {
    public:
        ConfigParam(std::string line);
        ConfigParam(std::string new_name, std::string new_value);
        static bool is_valid(const std::string& alleged_param);
        std::string get_name();
        std::string get_value();
        ConfigParam& set_value(std::string new_value);
    private:
        std::string name;
        std::string value;
};

class ConfigSection {
    public:
        ConfigSection() = default;
        std::string get_name();
        ConfigSection& set_name(std::string line);
        ConfigSection& reset();
        ConfigSection& add_param(ConfigParam&& param);
        ConfigSection& update_param(std::string param_name, std::string param_value);
        ConfigParam* get_param_by_name(std::string param_name);
        static bool is_valid(const std::string& alleged_section_name);
        std::string to_std_str(const std::string& padding = "");
        std::string to_config_section_str();
        std::string to_config_file_str();
    private:
        std::vector<ConfigParam> params;
        std::string name;
};

class ConfigFile {
    public:
        ConfigFile(const std::string& file_name);
        VectorWrapper raw_lines();
        ConfigFile& try_parse_or_throw();
        VectorWrapper try_read_write_params_or_throw(std::vector<ReadWriteAction> actions);
        std::string to_std_str();
        std::string to_config_file_str();
        ConfigSection* get_section_by_name(std::string section_name);
        ConfigSection* create_section(std::string new_section_name);
        ConfigFile& write_state_to_config_file();
    private:
        VectorWrapper lines;
        std::vector<ConfigSection> sections;
        std::string filename;
};

#endif
