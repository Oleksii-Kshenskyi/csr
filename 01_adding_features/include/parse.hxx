#ifndef PARSE_HXX
#define PARSE_HXX

#include "vecwrap.hxx"

class ConfigParam {
    public:
        ConfigParam(std::string line);
        static bool is_valid(const std::string& alleged_param);
        std::string get_name();
        std::string get_value();
    private:
        std::string name;
        std::string value;
};

class ConfigSection {
    public:
        ConfigSection() = default;
        ConfigSection& set_name(std::string line);
        ConfigSection& reset();
        ConfigSection& add_param(ConfigParam&& param);
        static bool is_valid(const std::string& alleged_section_name);
        std::string to_std_str(const std::string& padding = "");
    private:
        std::vector<ConfigParam> params;
        std::string name;
};

class ConfigFile {
    public:
        ConfigFile(const std::string& file_name);
        VectorWrapper raw_lines();
        ConfigFile& try_parse_or_throw();
        std::string to_std_str();
    private:
        VectorWrapper lines;
        std::vector<ConfigSection> sections;
};

#endif
