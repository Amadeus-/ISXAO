#pragma once
#include <windows.h>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "psapi.h"
#define _USE_MATH_DEFINES
#define _USE_MATH_CONSTANTS
#include <cmath>
#include <cinttypes>
#include <math.h>
#include <cassert>
#include <functional>
#include <concurrent_queue.h>

using namespace std;

#include "isxao_game.h"

#ifdef AOLIB_EXPORTS
#define AOLIB_API extern "C" __declspec(dllexport)
#define AOLIB_VAR extern "C" __declspec(dllexport)
#define AOLIB_OBJECT __declspec(dllexport)
#else
#define AOLIB_API extern "C" __declspec(dllimport)
#define AOLIB_VAR extern "C" __declspec(dllimport)
#define AOLIB_OBJECT __declspec(dllimport)
#endif

#define ISINDEX() (argc>0)
#define ISNUMBER() (IsNumber(argv[0]))
#define GETNUMBER() (atoi(argv[0]))
#define GETFIRST()    argv[0]

#define MAX_STRING 2048
#define MAX_LEVEL 300

#include "isxao_find_pattern.h"
#include "register_events.h"
#include "ISXAO.h"
#include "isxao_data.h"
#include "isxao_internal.h"
#include "isxao_classes.h"
#include "isxao_log.h"
#include "isxao_globals.h"
#include "isxao_inlines.h"
#include "isxao_utilities.h"
#include "isxao_detours.h"
#include "isxao_commands.h"

namespace isxao
{
	AOLIB_API void InitializeLogging();
	AOLIB_API void ShutdownLogging();


	AOLIB_API void InitializeISXAO();
	AOLIB_API void ShutdownISXAO();

	AOLIB_API DWORD GetActorIndexFromActorVector(LSIndex *index);

}
using namespace isxao;
