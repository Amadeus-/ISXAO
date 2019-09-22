#pragma once
#include <Windows.h>
#include "Psapi.h"
#include <algorithm>
#include <functional>
#include <cassert>

#include <cctype>
#include <cinttypes>

#include <string>
#include <vector>
#include <list>
#include <map>
#include <concurrent_queue.h>

#define _USE_MATH_DEFINES
#define _USE_MATH_CONSTANTS
#include <cmath>

#include "isxao_game.h"

#ifdef AOLIB_EXPORTS
#define AOLIB_API extern "C" __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#define AOLIB_VAR extern "C" __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#define AOLIB_OBJECT __declspec(dllexport)  // NOLINT(cppcoreguidelines-macro-usage)
#else
#define AOLIB_API extern "C" __declspec(dllimport)  // NOLINT(cppcoreguidelines-macro-usage)
#define AOLIB_VAR extern "C" __declspec(dllimport)  // NOLINT(cppcoreguidelines-macro-usage)
#define AOLIB_OBJECT __declspec(dllimport)  // NOLINT(cppcoreguidelines-macro-usage)
#endif

#define IS_INDEX() (argc>0)  // NOLINT(cppcoreguidelines-macro-usage)
#define IS_NUMBER() (IsNumber(argv[0]))  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_NUMBER() (atoi(argv[0]))  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_FIRST()    argv[0]  // NOLINT(cppcoreguidelines-macro-usage)
#define GET_VARIABLE_NAME(Variable) (#Variable)  // NOLINT(cppcoreguidelines-macro-usage)

#define MAX_LEVEL 300  // NOLINT(cppcoreguidelines-macro-usage)

#include "isxao_find_pattern.h"
#include "register_events.h"
#include "ISXAO.h"
#include "ao_structs.h"
#include "isxao_internal.h"
#include "ao_classes.h"
#include "isxao_classes.h"
#include "isxao_log.h"
#include "isxao_native_defines.h"
#include "isxao_globals.h"
#include "isxao_inlines.h"
#include "isxao_utilities.h"
#include "isxao_detours.h"
#include "isxao_commands.h"
#include "move.h"

namespace isxao
{
	AOLIB_API void InitializeLogging();
	AOLIB_API void ShutdownLogging();


	AOLIB_API void InitializeISXAO();
	AOLIB_API void ShutdownISXAO();

	AOLIB_API DWORD GetActorIndexFromActorVector(LSIndex *index);

}
using namespace isxao;
