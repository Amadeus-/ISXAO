#pragma once

class isxao_log
{
	std::string base_directory_, log_file_;
	HMODULE module_handle;

	void add_line_internal(const std::string& line) const;
public:
	isxao_log(HMODULE module_handle, const std::string& log_file = "Log.txt");

	void add_line(const char * format, ...) const;

	void set_base_dir(std::string path);
	std::string get_base_dir_file(const std::string& file_name) const;
	HMODULE get_h_module() const;
};

#define DEBUG_LOG gp_isxao_log->AddLine