#pragma once

namespace isxao
{
	class ao_detours
	{
	public:
#pragma region gamestate_service

		void n3_engine_client_t__set_main_dynel__trampoline(ao::dynel*);
		void n3_engine_client_t__set_main_dynel__detour(ao::dynel*);



		ao::playfield_anarchy* playfield_anarchy_t__playfield_anarchy_t__trampoline(PVOID);
		ao::playfield_anarchy* playfield_anarchy_t__playfield_anarchy_t__detour(PVOID);

		void playfield_anarchy_t__d_playfield_anarchy_t__trampoline();
		void playfield_anarchy_t__d_playfield_anarchy_t__detour();

		ao::engine_client_anarchy* n3_engine_client_anarchy_t__n3_engine_client_anarchy_t__trampoline();
		PVOID n3_engine_client_anarchy_t__n3_engine_client_anarchy_t__detour();

		PVOID n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t__trampoline();
		PVOID n3_engine_client_anarchy_t__d_n3_engine_client_anarchy_t__detour();

#pragma endregion

#pragma region actor_service

		void n3_playfield_t__add_child_dynel__trampoline(ao::dynel*, const ao::vector3_t&, const ao::quaternion_t&);
		void n3_playfield_t__add_child_dynel__detour(ao::dynel*, const ao::vector3_t&, const ao::quaternion_t&);

		void n3_dynel_t__set_playfield__trampoline(DWORD);
		void n3_dynel_t__set_playfield__detour(DWORD);

#pragma endregion

		void n3_engine_client_anarchy_t__n3_msg_movement_changed__trampoline(DWORD, float, float, bool);
		void n3_engine_client_anarchy_t__n3_msg_movement_changed__detour(DWORD, float, float, bool);

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

		static void initialize();
		static void shutdown();
	};

}