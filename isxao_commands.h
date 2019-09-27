#pragma once

namespace isxao
{
	namespace commands
	{
		AOLIB_API bool IsISXAOCommand(PCHAR);
		AOLIB_API DWORD Activate(int begin_inclusive, int argc, char *argv[]);
		AOLIB_API DWORD AOEcho(int argc, char *argv[]);
		AOLIB_API DWORD AOExecute(int argc, char *argv[]);
		AOLIB_API DWORD Attack(int begin_inclusive, int argc, char *argv[]);
		AOLIB_API DWORD Cast(int begin_inclusive, int argc, char *argv[]);
		AOLIB_API DWORD DoAction(int argc, char *argv[]);
		AOLIB_API DWORD Face(int argc, char *argv[]);
		AOLIB_API DWORD Target(int argc, char *argv[]);
	}
}
using namespace isxao::commands;