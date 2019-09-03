#pragma once

namespace isxao_detours
{

	class AODetours
	{
	public:
		void n3EngineClientAnarchy_t__SetMainDynel_Trampoline(PVOID);
		void n3EngineClientAnarchy_t__SetMainDynel_Detour(PVOID);

		PVOID PlayfieldAnarchy_t__PlayfieldAnarchy_t_Trampoline(PVOID);
		PVOID PlayfieldAnarchy_t__PlayfieldAnarchy_t_Detour(PVOID);

		void PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Trampoline();
		void PlayfieldAnarchy_t__dPlayfieldAnarchy_t_Detour();

		PVOID n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Trampoline();
		PVOID n3EngineClientAnarchy_t__n3EngineClientAnarchy_t_Detour();

		PVOID n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Trampoline();
		PVOID n3EngineClientAnarchy_t__dn3EngineClientAnarchy_t_Detour();

		void Playfield_t__AddChildDynel_Trampoline(Dynel*, const vector3_t&, const quaternion_t&);
		void Playfield_t__AddChildDynel_Detour(Dynel*, const vector3_t&, const quaternion_t&);

		void n3Dynel_t__SetPlayfield_Trampoline(DWORD);
		void n3Dynel_t__SetPlayfield_Detour(DWORD);

		DWORD Client_t__ProcessMessage_Trampoline(Message*);
		DWORD Client_t__ProcessMessage_Detour(Message*);

		void n3Engine_t__SetTeleportStatus_Trampoline(bool);
		void n3Engine_t__SetTeleportStatus_Detour(bool);

		void ChatGUIModule_c__HandleGroupAction_Trampoline(PPPJCLIENTGROUPACTION);
		void ChatGUIModule_c__HandleGroupAction_Detour(PPPJCLIENTGROUPACTION);
		void ChatGUIModule_c__HandleGroupMessage_Trampoline(PPPJCLIENTGROUPMESSAGE);
		void ChatGUIModule_c__HandleGroupMessage_Detour(PPPJCLIENTGROUPMESSAGE);
		void ChatGUIModule_c__HandlePrivateGroupAction_Trampoline(PPPJCLIENTPRIVATEGROUPACTION);
		void ChatGUIModule_c__HandlePrivateGroupAction_Detour(PPPJCLIENTPRIVATEGROUPACTION);
		void ChatGUIModule_c__HandlePrivateMessage_Trampoline(PPPJCLIENTPRIVATEMESSAGE);
		void ChatGUIModule_c__HandlePrivateMessage_Detour(PPPJCLIENTPRIVATEMESSAGE);
		static void ChatGUIModule_c__HandleSystemMessage_Trampoline(PPPJCLIENTSYSTEMMESSAGE);
		static void ChatGUIModule_c__HandleSystemMessage_Detour(PPPJCLIENTSYSTEMMESSAGE);
		void ChatGUIModule_c__HandleVicinityMessage_Trampoline(PPPJCLIENTVICINITYMESSAGE);
		void ChatGUIModule_c__HandleVicinityMessage_Detour(PPPJCLIENTVICINITYMESSAGE);

		void ChatGroupController_c__sub_10083D9C_Trampoline(int, string*, int);
		void ChatGroupController_c__sub_10083D9C_Detour(int, string*, int);

		PVOID FriendListController_c__sub_100A68E6_Trampoline(string*, int, string*, int);
		PVOID FriendListController_c__sub_100A68E6_Detour(string*, int, string*, int);

		PVOID ChatWindowNode_c__sub_1009BB79_Trampoline(int, int, string*, string*, int, int, char);
		PVOID ChatWindowNode_c__sub_1009BB79_Detour(int, int, string*, string*, int, int, char);

		bool CommandInterpreter_c__ParseTextCommand_Trampoline(ChatWindowNode*, string*);
		bool CommandInterpreter_c__ParseTextCommand_Detour(ChatWindowNode*, string*);

		static void Initialize();
		static void Shutdown();
	};

}
using namespace isxao_detours;