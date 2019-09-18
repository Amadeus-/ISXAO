#include "isxao_main.h"
#include <fstream>
#include <streambuf>
#include <utility>
#include <vector>

isxao_log::isxao_log(const HMODULE module_handle, const std::string& log_file)
{
	this->module_handle = module_handle;
	char base_directory[MAX_PATH] = { 0 };
	GetModuleFileNameA(module_handle, base_directory, MAX_PATH);

	base_directory_ = base_directory;
	base_directory_ = base_directory_.substr(0, base_directory_.rfind('\\') + 1);

	DeleteFileA(get_base_dir_file(log_file).c_str());
	this->log_file_ = log_file;

	SYSTEMTIME system_time;
	GetLocalTime(&system_time);
	const auto ms = system_time.wMilliseconds;
	char date[64] = { 0 };
	GetDateFormatA(LOCALE_USER_DEFAULT, 0, &system_time, "yyyy'-'MM'-'dd", date, 64);
	char time[32] = { 0 };
	GetTimeFormatA(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, &system_time, "hh':'mm':'ss", time, 32);
	char time_ms[32] = { 0 };
	sprintf_s(time_ms, sizeof(time_ms), "%s.%d", time, ms);
	this->add_line("Logging started at %s on %s\n", time, date);
}

std::string isxao_log::get_base_dir_file(const std::string& file_name) const
{
	return base_directory_ + file_name;
}

void isxao_log::add_line_internal(const std::string& line) const
{
	if (!line.length())
		return;

	std::ofstream output_file_stream(get_base_dir_file(log_file_).c_str(), std::ios_base::out | std::ios_base::app);

	if (output_file_stream.is_open())
	{
		SYSTEMTIME system_time;
		GetLocalTime(&system_time);
		const auto ms = system_time.wMilliseconds;
		char time[32] = { 0 };
		GetTimeFormatA(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, &system_time, "hh':'mm':'ss", time, 32);
		char time_ms[32] = { 0 };
		sprintf_s(time_ms, sizeof(time_ms), "%s.%d", time, ms);
		output_file_stream << "[" << time_ms << "]: " << line << "\n";

		output_file_stream.close();
	}
}

void isxao_log::add_line(const char * format, ...) const
{
	char buffer[MAX_VARSTRING] = { 0 };

	va_list arg_list;
	va_start(arg_list, format);
	vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, format, arg_list);
	va_end(arg_list);

	add_line_internal(buffer);
}

void isxao_log::set_base_dir(const std::string path)
{
	base_directory_ = std::move(path);
}

HMODULE isxao_log::get_h_module() const
{
	return module_handle;
}
