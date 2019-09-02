#include "isxao_main.h"

namespace isxao
{

	void InitializeLogging()
	{
		gp_isxao_log = new ISXAOLog(GetModuleHandle("ISXAO.dll"));
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
		gp_isxao_log->AddLine("Logging initialized\n");

		// Initialize offsets
		gp_isxao_log->AddLine("Initializing offsets...\n");
		g_offsets_initialized = InitializeOffsets();
		if (g_offsets_initialized)
			gp_isxao_log->AddLine("Offsets initialized.\n");
		else
		{
			g_isxao_initialized = g_offsets_initialized;
			gp_isxao_log->AddLine("Offsets failed to initialize.\n");
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
		gp_isxao_log->AddLine("Shutting down logging\n");
		ShutdownLogging();
	}

	DWORD GetActorIndexFromActorVector(LSIndex *index)
	{
		std::vector<Actor*> v;
		P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			index->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		return index->GetContainerUsed();
	}


}