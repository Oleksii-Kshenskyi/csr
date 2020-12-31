#include "parse.hxx"
#include "util.hxx"


ConfigParam::ConfigParam(std::string line) {
    VectorWrapper parsed_param { StringWrapper(line).split("=") };
    this->name = StringWrapper(parsed_param[0]).trim().to_std_str();
    this->value = StringWrapper(parsed_param[1]).trim().to_std_str();
}

bool ConfigParam::is_valid(const std::string& alleged_param) {
    VectorWrapper parsed_param { StringWrapper(alleged_param).split("=") };
    return (parsed_param.size() == 2) &&
           (!StringWrapper(parsed_param[0]).trim().to_std_str().empty()) &&
           (!StringWrapper(parsed_param[1]).trim().to_std_str().empty());
}

std::string ConfigParam::get_name() {
    return this->name;
}

std::string ConfigParam::get_value() {
    return this->value;
}


ConfigSection& ConfigSection::set_name(std::string line) {
    if(ConfigSection::is_valid(line)) {
        this->name = line.substr(1, line.size() - 2);
    }
    return *this;
}

ConfigSection& ConfigSection::reset() {
    this->name = "";
    this->params.clear();

    return *this;
}

ConfigSection& ConfigSection::add_param(ConfigParam&& param) {
    this->params.emplace_back(param);

    return *this;
}

bool ConfigSection::is_valid(const std::string& alleged_section_name) {
    return alleged_section_name[0] == '[' && alleged_section_name[alleged_section_name.size() - 1] == ']';
}

std::string ConfigSection::to_std_str(const std::string& padding) {
    StringWrapper result(padding);
    result.append("Section [").append(this->name).append("] {\n");

    for(size_t index = 0; index < this->params.size(); index++) {
        result.append(padding).append("\t \'").append(this->params[index].get_name()).append("\' = \'").append(this->params[index].get_value()).append("\',\n");
    }

    result.append(padding).append("}\n");
    return result.to_std_str();
}


ConfigFile::ConfigFile(const std::string& file_name): lines(FileReader(file_name).lines().trim_empty()), sections() {}

VectorWrapper ConfigFile::raw_lines() {
    return this->lines;
}

ConfigFile& ConfigFile::try_parse_or_throw() {
    this->sections.clear();
    ConfigSection current_section;
    for(size_t index = 0; index < this->lines.size(); index++) {
        std::string trimmed_line { StringWrapper(this->lines[index]).trim().to_std_str() };
        if(ConfigSection::is_valid(trimmed_line)) {
            if(index != 0)
                this->sections.push_back(current_section);
            current_section.reset().set_name(trimmed_line);
        } else if(ConfigParam::is_valid(trimmed_line)) {
            current_section.add_param(ConfigParam(trimmed_line));
        }
        else {
            throw Exception(StringWrapper("Line ").append(index + 1).append(": \'").append(trimmed_line).append("\' is not a valid section or parameter definition.").to_std_str());
        }
    }
    this->sections.push_back(current_section);

    return *this;
}

std::string ConfigFile::to_std_str() {
    StringWrapper converted("Config {\n");
    for(ConfigSection section : this->sections) {
        converted.append(section.to_std_str("\t"));
    }
    converted.append("}\n");

    return converted.to_std_str();
}
