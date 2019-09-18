#include "isxao_main.h"

namespace isxao
{

	void InitializeLogging()
	{
		SYSTEMTIME system_time;
		GetLocalTime(&system_time);
		const auto ms = system_time.wMilliseconds;
		char time[32] = { 0 };
		GetTimeFormatA(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, &system_time, "hh'_'mm'_'ss", time, 32);
		char time_ms[32] = { 0 };
		sprintf_s(time_ms, sizeof(time_ms), "%s_%d", time, ms);
		char log_file_name[MAX_PATH] = { 0 };
		sprintf_s(log_file_name, sizeof(log_file_name), "ISXAO_%s.txt", time_ms);
		gp_isxao_log = new isxao_log(GetModuleHandle("ISXAO.dll"), log_file_name);
	}

	void ShutdownLogging()
	{
		delete gp_isxao_log;
		gp_isxao_log = nullptr;
	}

	void InitializeISXAO()
	{
		g_isxao_initialized = true;

		// Initialize logging
		InitializeLogging();
		gp_isxao_log->add_line("Logging initialized");

		// Initialize offsets
		gp_isxao_log->add_line("Initializing offsets...");
		g_offsets_initialized = initialize_offsets();
		if (g_offsets_initialized)
			gp_isxao_log->add_line("Offsets initialized.");
		else
		{
			g_isxao_initialized = g_offsets_initialized;
			gp_isxao_log->add_line("Offsets failed to initialize.");
		}	

		// Initialize globals
		

		// Determine GAMESTATE
		// g_game_state = GetGameState();
		// gp_isxao_log->AddLine("GAMESTATE = %d\n", g_game_state);



		// Apply function hooks
		//InitializePlayfieldHook();
		//InitializeSetMainDynelHook();
		//InitializeSetTeleportStatusHook();
		//InitializePlayfieldChildrenHook();
		//InitializeAOMessageHook();
		//InitializeSimpleCharHook();
		// AODetours::Initialize();

		// Register events
		// gp_isxao_log->AddLine("Registering events.\n");
		// g_events_registered = RegisterEvents();
		/*if (g_events_registered)
			gp_isxao_log->AddLine("Events registered.\n");
		else
		{
			g_isxao_initialized = g_events_registered;
			gp_isxao_log->AddLine("Events failed to register.\n");
		}*/
			
	}

	void ShutdownISXAO()
	{
		// Remove function hooks
		//ShutdownSimpleCharHook();
		//ShutdownAOMessageHook();
		//ShutdownPlayfieldChildrenHook();
		//ShutdownSetTeleportStatusHook();
		//ShutdownSetMainDynelHook();
		//ShutdownPlayfieldHook();
		//AODetours::Shutdown();

		printf("ISXAO unloaded.");
		gp_isxao_log->add_line("Shutting down logging");
		ShutdownLogging();
	}

	DWORD GetActorIndexFromActorVector(LSIndex *index)
	{
		std::vector<ao::actor*> v;
		P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			index->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		return index->GetContainerUsed();
	}


}