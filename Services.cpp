#include "isxao_main.h"
#include "ISXAOServices.h"

#define SERVICE(_name_,_callback_,_variable_) HISXSERVICE _variable_=0;
#include "Services.h"
#undef SERVICE

bool AOFooFunction(const char *Name, unsigned int Age, float Height)
{
	printf("Foo: %s. Age %d. Height: %fcm", Name, Age, Height);
	return true;
}

void __cdecl AOService(ISXInterface *pClient, unsigned int MSG, void *lpData)
{
	switch (MSG)
	{
	case ISXSERVICE_CLIENTADDED:
		// This ao_message indicates that a new client has been added to the service
		// P_ENGINE_CLIENT_ANARCHY is 0, because this ao_message is a system ao_message from Inner Space
		// lpData is an ISXInterface* that is the pointer to the new client
	{
		// use lpData as the actual type, not as void *.  We can make a new
		// variable to do this:
		ISXInterface *pNewClient = (ISXInterface *)lpData;

		printf("AOService client added: %X", pNewClient);
		// You may use the client pointer (pNewClient here) as an ID to track client-specific
		// information.  Some services such as the memory service do this to automatically
		// remove memory modifications made by an extension when that extension is unloaded.
	}
	break;
	case ISXSERVICE_CLIENTREMOVED:
		// This ao_message indicates that a client has been removed from the service
		// P_ENGINE_CLIENT_ANARCHY is 0, because this ao_message is a system ao_message from Inner Space
		// lpData is an ISXInterface* that is the pointer to the removed client
	{
		// use lpData as the actual type, not as void *.  We can make a new
		// variable to do this:
		ISXInterface *pRemovedClient = (ISXInterface *)lpData;

		printf("AOService client removed: %X", pRemovedClient);
	}
	break;
	case AO_FOO:
		// This is a custom service request defined in ISXAOServices.h
		// P_ENGINE_CLIENT_ANARCHY is a valid pointer to the client that sent this request
		// lpData is a AORequest_Foo* as sent by the client
	{
		AORequest_Foo *pFoo = (AORequest_Foo*)lpData;

		/*
		* As described in ISXAOServices.h, pFoo is simply a remote call
		* to AOFooFunction, and has all of the parameters and the outgoing
		* return value ready to go.
		*/
		pFoo->Success = AOFooFunction(pFoo->Name, pFoo->Age, pFoo->Height);

		/*
		* That's it!  In many cases, the functionality provided by the service will
		* be something that should be per-client to automatically handle cleanup.
		* In such cases, it would be prudent to pass the P_ENGINE_CLIENT_ANARCHY to the function call
		* for proper handling.
		*/
	}
	break;
	}
}


/*
* How to broadcast an outgoing service ao_message (called a notification):
AONotification_Bar Bar;
Bar.Text="Some text to pass as part of the notification";
pFoo->Success=pISInterface->ServiceBroadcast(pExtension,hAOService,AO_BAR,&Bar);
*/

void __cdecl ActorService(ISXInterface *pClient, unsigned int MSG, void *lpData)
{
	switch (MSG)
	{
	case AddActor:
	{
		if (lpData)
		{
			ao::actor* p_actor = static_cast<ao::actor*>(lpData);
			if (p_actor->get_identity().type == 50000)
			{
				char name[MAX_VARSTRING];
				char identity[MAX_VARSTRING];
				strcpy_s(name, MAX_VARSTRING, reinterpret_cast<ao::actor*>(p_actor)->get_name());
				sprintf_s(identity, MAX_VARSTRING, "%I64d", reinterpret_cast<ao::actor*>(p_actor)->get_identity().get_combined_identity());
				char *argv[] = { name, identity };
				pISInterface->ExecuteEvent(GetEventId("AO_onActorSpawned"), 0, 2, argv);
				pISInterface->ServiceBroadcast(pExtension, hActorService, AddActor, p_actor);
			}
		}
		break;
	}
	case RemoveActor:
	{
		if(lpData)
		{
			ao::actor* p_actor = static_cast<ao::actor*>(lpData);
			if (p_actor->get_identity().type == 50000)
			{
				char name[MAX_VARSTRING];
				char identity[MAX_VARSTRING];
				strcpy_s(name, MAX_VARSTRING, reinterpret_cast<ao::actor*>(p_actor)->get_name());
				sprintf_s(identity, MAX_VARSTRING, "%I64d", reinterpret_cast<ao::actor*>(p_actor)->get_identity().get_combined_identity());
				char *argv[] = { name, identity };
				pISInterface->ExecuteEvent(GetEventId("AO_onActorDespawned"), 0, 2, argv);
				pISInterface->ServiceBroadcast(pExtension, hActorService, RemoveActor, p_actor);
			}
		}
		break;
	}
	}
}

void __cdecl TeleportService(ISXInterface *pClient, unsigned int MSG, void *lpData)
{
	switch (MSG)
	{
	case StartTeleport:
	{
		if(!g_zoning)
		{
			g_zoning = true;
			pISInterface->ExecuteEvent(GetEventId("AO_onZoneBegin"), 0, 0);
			pISInterface->ServiceBroadcast(pExtension, hTeleportService, StartTeleport, nullptr);
		}		
		break;
	}
	case StopTeleport:
	{
		if(g_zoning)
		{
			g_zoning = false;
			pISInterface->ExecuteEvent(GetEventId("AO_onZoneEnd"), 0, 0);
			pISInterface->ServiceBroadcast(pExtension, hTeleportService, StopTeleport, nullptr);
		}		
		break;
	}
	}
}

void __cdecl PlayfieldService(ISXInterface *pClient, unsigned int MSG, void *lpData)
{
	switch (MSG)
	{
	case CreatePlayfield:
	{
		GamestateService(pExtension, GamestateInGame, nullptr);
		break;
	}
	case DestroyPlayfield:
	{
		GamestateService(pExtension, GamestateWaitingForPlayfield, nullptr);
		break;
	}
	}
}

void __cdecl GamestateService(ISXInterface *pClient, unsigned int MSG, void *lpData)
{
	switch (MSG)
	{
	case GamestateNotInGame:
	{
		if(g_game_state != GAMESTATE_NOT_IN_GAME)
		{
			g_game_state = GAMESTATE_NOT_IN_GAME;
			gp_isxao_log->add_line("Gamestate Changed to GAMESTATE_NOT_IN_GAME\n");
			char new_state[MAX_VARSTRING];
			sprintf_s(new_state, MAX_VARSTRING, "GAMESTATE_NOT_IN_GAME");
			char *argv[] = { new_state };
			pISInterface->ExecuteEvent(GetEventId("AO_onGamestateChanged"), 0, 1, argv);
			pISInterface->ServiceBroadcast(pExtension, hGamestateService, GamestateNotInGame, nullptr);
		}
		break;
	}
	case GamestateWaitingForPlayfield:
	{
		if(g_game_state != GAMESTATE_WAITING_FOR_PLAYFIELD)
		{
			g_game_state = GAMESTATE_WAITING_FOR_PLAYFIELD;
			gp_isxao_log->add_line("Gamestate Changed to GAMESTATE_WAITING_FOR_PLAYFIELD\n");
			char new_state[MAX_VARSTRING];
			sprintf_s(new_state, MAX_VARSTRING, "GAMESTATE_WAITING_FOR_PLAYFIELD");
			char *argv[] = { new_state };
			pISInterface->ExecuteEvent(GetEventId("AO_onGamestateChanged"), 0, 1, argv);
			pISInterface->ServiceBroadcast(pExtension, hGamestateService, GamestateWaitingForPlayfield, nullptr);
		}
		break;
	}
	case GamestateWaitingForCharacter:
	{
		if (g_game_state != GAMESTATE_WAITING_FOR_CLIENT_CHAR)
		{
			g_game_state = GAMESTATE_WAITING_FOR_CLIENT_CHAR;
			gp_isxao_log->add_line("Gamestate Changed to GAMESTATE_WAITING_FOR_CLIENT_CHAR\n");
			char new_state[MAX_VARSTRING];
			sprintf_s(new_state, MAX_VARSTRING, "GAMESTATE_WAITING_FOR_CLIENT_CHAR");
			char *argv[] = { new_state };
			pISInterface->ExecuteEvent(GetEventId("AO_onGamestateChanged"), 0, 1, argv);
			pISInterface->ServiceBroadcast(pExtension, hGamestateService, GamestateWaitingForCharacter, nullptr);
		}
		break;
	}
	case GamestateInGame:
	{
		if (g_game_state != GAMESTATE_IN_GAME)
		{
			g_game_state = GAMESTATE_IN_GAME;
			gp_isxao_log->add_line("Gamestate Changed to GAMESTATE_IN_GAME\n");
			char new_state[MAX_VARSTRING];
			sprintf_s(new_state, MAX_VARSTRING, "GAMESTATE_IN_GAME");
			char *argv[] = { new_state };
			pISInterface->ExecuteEvent(GetEventId("AO_onGamestateChanged"), 0, 1, argv);
			pISInterface->ServiceBroadcast(pExtension, hGamestateService, GamestateInGame, nullptr);
		}
		break;
	}
	}
}