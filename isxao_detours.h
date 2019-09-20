#pragma once

namespace isxao
{
	class ao_detours
	{
	public:
		void n3_engine_client_anarchy_t__set_main_dynel__trampoline(ao::dynel*);
		void n3_engine_client_anarchy_t__set_main_dynel__detour(ao::dynel*);

		PVOID playfield_anarchy_t__playfield_anarchy_t__trampoline(PVOID);
		PVOID playfield_anarchy_t__playfield_anarchy_t__detour(PVOID);

		void PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Trampoline();
		void PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Detour();

		PVOID n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Trampoline();
		PVOID n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Detour();

		PVOID n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Trampoline();
		PVOID n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Detour();

		void Playfield_t__AddChildDynel_Trampoline(ao::dynel*, const ao::vector3_t&, const ao::quaternion_t&);
		void Playfield_t__AddChildDynel_Detour(ao::dynel*, const ao::vector3_t&, const ao::quaternion_t&);

		void n3Dynel_t__SetPlayfield_Trampoline(DWORD);
		void n3Dynel_t__SetPlayfield_Detour(DWORD);

		DWORD client_t__process_message_trampoline(ao::message*);
		DWORD client_t__process_message_detour(ao::message*);

		void n3Engine_t__SetTeleportStatus_Trampoline(bool);
		void n3Engine_t__SetTeleportStatus_Detour(bool);

		void ChatGUIModule_c__HandleGroupAction_Trampoline(ao::p_ppj_client_group_action_t);
		void ChatGUIModule_c__HandleGroupAction_Detour(ao::p_ppj_client_group_action_t);
		void ChatGUIModule_c__HandleGroupMessage_Trampoline(ao::p_ppj_group_message_t);
		void ChatGUIModule_c__HandleGroupMessage_Detour(ao::p_ppj_group_message_t);
		void ChatGUIModule_c__HandlePrivateGroupAction_Trampoline(ao::p_ppj_client_private_group_action_t);
		void ChatGUIModule_c__HandlePrivateGroupAction_Detour(ao::p_ppj_client_private_group_action_t);
		void ChatGUIModule_c__HandlePrivateMessage_Trampoline(ao::p_ppj_client_private_message_t);
		void ChatGUIModule_c__HandlePrivateMessage_Detour(ao::p_ppj_client_private_message_t);
		static void ChatGUIModule_c__HandleSystemMessage_Trampoline(ao::p_ppj_client_system_message_t);
		static void ChatGUIModule_c__HandleSystemMessage_Detour(ao::p_ppj_client_system_message_t);
		void ChatGUIModule_c__HandleVicinityMessage_Trampoline(ao::p_ppj_client_vicinity_message_t);
		void ChatGUIModule_c__HandleVicinityMessage_Detour(ao::p_ppj_client_vicinity_message_t);

		void ChatGroupController_c__sub_10083D9C_Trampoline(int, string*, int);
		void ChatGroupController_c__sub_10083D9C_Detour(int, string*, int);

		PVOID FriendListController_c__sub_100A68E6_Trampoline(string*, int, string*, int);
		PVOID FriendListController_c__sub_100A68E6_Detour(string*, int, string*, int);

		PVOID ChatWindowNode_c__sub_1009BB79_Trampoline(int, int, string*, string*, int, int, char);
		PVOID ChatWindowNode_c__sub_1009BB79_Detour(int, int, string*, string*, int, int, char);

		bool CommandInterpreter_c__ParseTextCommand_Trampoline(ao::chat_window_node*, string*);
		bool CommandInterpreter_c__ParseTextCommand_Detour(ao::chat_window_node*, string*);

		static void Initialize();
		static void Shutdown();
	};

}