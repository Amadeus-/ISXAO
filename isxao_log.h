#pragma once

class ISXAOLog
{
	std::string base_directory_, log_file_;
	HMODULE module_handle;

	void addLine(std::string line) const;
public:
	ISXAOLog(HMODULE module_handle, std::string log_file = "Log.txt");

	void AddLine(const char * format_, ...) const;

	void SetBaseDir(std::string path_);
	std::string GetBaseDirFile(std::string file_name_) const;
	HMODULE GetHModule() const;
};

#define DBGLOG gp_isxao_log->AddLine