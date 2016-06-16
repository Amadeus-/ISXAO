#include "isxao_main.h"
#include <fstream>
#include <streambuf>
#include <vector>

ISXAOLog::ISXAOLog(HMODULE module_handle, std::string log_file)
{
	module_handle = module_handle;

	char base_directory[MAX_PATH] = { 0 };
	GetModuleFileNameA(module_handle, base_directory, MAX_PATH);

	base_directory_ = base_directory;
	base_directory_ = base_directory_.substr(0, base_directory_.rfind("\\") + 1);

	DeleteFileA(GetBaseDirFile(log_file).c_str());
	log_file_ = log_file;

	SYSTEMTIME system_time;
	GetLocalTime(&system_time);

	char date[64] = { 0 };
	GetDateFormatA(LOCALE_USER_DEFAULT, 0, &system_time, "yyyy'-'MM'-'dd", date, 64);

	AddLine("Logging started at %s\n", date);
}

std::string ISXAOLog::GetBaseDirFile(std::string file_name) const
{
	return base_directory_ + file_name;
}

void ISXAOLog::addLine(std::string line) const
{
	if (!line.length())
		return;

	std::ofstream output_file_stream(GetBaseDirFile(log_file_).c_str(), std::ios_base::out | std::ios_base::app);

	if (output_file_stream.is_open())
	{
		SYSTEMTIME system_time;
		GetLocalTime(&system_time);

		char time[32] = { 0 };
		GetTimeFormatA(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, &system_time, "hh':'mm':'ss", time, 32);

		output_file_stream << "[" << time << "]: " << line;

		output_file_stream.close();
	}
}

void ISXAOLog::AddLine(const char * format, ...) const
{
	char buffer[1024] = { 0 };

	va_list arg_list;
	va_start(arg_list, format);
	vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, format, arg_list);
	va_end(arg_list);

	addLine(buffer);
}

void ISXAOLog::SetBaseDir(std::string path)
{
	base_directory_ = path;
}

HMODULE ISXAOLog::GetHModule() const
{
	return module_handle;
}
