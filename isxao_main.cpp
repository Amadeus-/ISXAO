#include "isxao_main.h"
#include "playfield_anarchy.h"

namespace isxao
{

	void InitializeLogging()
	{
		SYSTEMTIME system_time;
		GetLocalTime(&system_time);
		char date[64] = { 0 };
		GetDateFormatA(LOCALE_USER_DEFAULT, 0, &system_time, "yyyy'_'MM'_'dd", date, 64);
		const auto ms = system_time.wMilliseconds;
		char time[32] = { 0 };
		GetTimeFormatA(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, &system_time, "hh'_'mm'_'ss", time, 32);
		char time_ms[32] = { 0 };
		sprintf_s(time_ms, sizeof(time_ms), "%s_%d", time, ms);
		char log_file_name[MAX_PATH] = { 0 };
		sprintf_s(log_file_name, sizeof(log_file_name), "ISXAO_%s_%s.txt", date, time_ms);
		ao::gp_isxao_log = new isxao_log(GetModuleHandle("ISXAO.dll"), log_file_name);
	}

	void ShutdownLogging()
	{
		delete ao::gp_isxao_log;
		ao::gp_isxao_log = nullptr;
	}

	void InitializeISXAO()
	{
		ao::g_isxao_initialized = true;

		// Initialize logging
		InitializeLogging();
		ao::gp_isxao_log->add_line("Logging initialized");

		// Initialize offsets
		ao::gp_isxao_log->add_line("Initializing offsets...");
		ao::g_offsets_initialized = ao::initialize_offsets();
		if (ao::g_offsets_initialized)
			ao::gp_isxao_log->add_line("Offsets initialized.");
		else
		{
			ao::g_isxao_initialized = ao::g_offsets_initialized;
			ao::gp_isxao_log->add_line("Offsets failed to initialize.");
		}	

		// Initialize globals
		

		// Determine GAMESTATE
		ao::g_game_state = get_game_state();
		char game_state[MAX_VARSTRING];
		if (ao::g_game_state == GAMESTATE_NOT_IN_GAME)
			sprintf_s(game_state, sizeof(game_state), "GAMESTATE_NOT_IN_GAME");
		else if (ao::g_game_state == GAMESTATE_WAITING_FOR_PLAYFIELD)
			sprintf_s(game_state, sizeof(game_state), "GAMESTATE_WAITING_FOR_PLAYFIELD");
		else if (ao::g_game_state == GAMESTATE_WAITING_FOR_CLIENT_CHAR)
			sprintf_s(game_state, sizeof(game_state), "GAMESTATE_WAITING_FOR_CLIENT_CHAR");
		else
			sprintf_s(game_state, sizeof(game_state), "GAMESTATE_IN_GAME");
		ao::gp_isxao_log->add_line("Gamestate is %s.", game_state);

		detours::initialize();

		// Register events
		ao::gp_isxao_log->add_line("Registering events.");
		ao::g_events_registered = events::RegisterEvents();
		if (ao::g_events_registered)
			ao::gp_isxao_log->add_line("Events registered.");
		else
		{
			ao::g_isxao_initialized = ao::g_events_registered;
			ao::gp_isxao_log->add_line("Events failed to register.");
		}
			
	}

	void ShutdownISXAO()
	{

		detours::shutdown();

		printf("ISXAO unloaded.");
		ao::gp_isxao_log->add_line("Shutting down logging");
		ShutdownLogging();
	}

	DWORD GetActorIndexFromActorVector(LSIndex *index)
	{
		std::vector<ao::actor*> v;
		P_PLAYFIELD_DIR->get_playfield()->get_playfield_actors(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			index->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		return index->GetContainerUsed();
	}


}