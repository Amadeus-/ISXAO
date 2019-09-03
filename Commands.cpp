#include "isxao_main.h"

#pragma region Testing and Debugging

int CMD_AO(int argc, char *argv[])
{
	printf("%" PRIX32, n3_engine_client_anarchy_t__get_current_movement_mode);
	return 0;
}

int CMD_TESTINTERFACE(int argc, char *argv[])
{
	printf("0x%.8X", sizeof(string));
	return 0;
}

int CMD_DUMPSPECIALACTIONS(int argc, char *argv[])
{
	
	return 0;
}

int CMD_DUMPSTATS(int argc, char *argv[])
{
	identity_t id;
	identity_t dummy;
	if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->GetTarget(id))
	{
		FILE * pFILE;
		fopen_s(&pFILE, "stats.txt", "a");
		std::map<DWORD, const char *> m;
		GetStatNameMap(m);
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			char buffer[MAX_STRING];
			LONG stat = P_ENGINE_CLIENT_ANARCHY->N3Msg_GetSkill(id, static_cast<AOData::Stat_e>((*it).first), 2, dummy);
			sprintf_s(buffer, "ST_%s = %d,\n", (*it).second, /*(*it).first*/stat);
			for (auto i = 0; i < (int)strlen(buffer); i++)
				buffer[i] = toupper(buffer[i]);
			fputs(buffer, pFILE);

		}
		fclose(pFILE);
	}
	//if (P_ENGINE_CLIENT_ANARCHY->GetWeaponTarget(id))
	//{
	//	FILE * pFILE;
	//	pFILE = fopen("stats.txt", "a");
	//	std::map<DWORD, const char *> m;
	//	P_ENGINE_CLIENT_ANARCHY->GetStatNameMap(m);
	//	for (auto it = m.begin(); it != m.end(); ++it)
	//	{
	//		char buffer[MAX_STRING];
	//		LONG stat = P_ENGINE_CLIENT_ANARCHY->GetSkill(id, static_cast<AOData::Stat_e>((*it).first));
	//		if (stat != 1234567890)
	//		{
	//			sprintf_s(buffer, "PS_%s = %d,\n", (*it).second, (*it).first);
	//			for (auto i = 0; i < strlen(buffer); i++)
	//				buffer[i] = toupper(buffer[i]);
	//			fputs(buffer, pFILE);
	//		}

	//	}
	//	fclose(pFILE);
	//}
	return 0;
}

int CMD_ATTACK(int argc, char *argv[])
{
	identity_t p1;
	identity_t p2;
	P_ENGINE_CLIENT_ANARCHY->N3Msg_GetClientPetID(p1, 0);
	printf("%d", p1.id);
	P_ENGINE_CLIENT_ANARCHY->N3Msg_GetClientPetID(p2, 1);
	printf("%d", p2.id);
	return 0;
}

int CMD_TESTSTRUCTS(int argc, char *argv[])
{	
	printf("Testing struct sizes...");

	DWORD r = sizeof(bank_entry_t);
	DWORD a = 0x38;
	printf("bank_entry_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(binary_stream_t);
	a = 0x44;
	printf("binary_stream_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(camera_vehicle_t);
	a = 0x1EC;
	printf("camera_vehicle_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(char_movement_status_t);
	a = 0x34;
	printf("char_movement_status_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(char_vehicle_t);
	a = 0x3AC;
	printf("char_vehicle_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(chest_t);
	a = 0x1E8;
	printf("chest_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(coll_info_t);
	a = 0x14;
	printf("coll_info_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(coll_prim_t);
	a = 0x18;
	printf("coll_prim_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(coll_sphere_t);
	a = 0x1C;
	printf("coll_sphere_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(DBOBJECT);
	a = 0x18;
	printf("DBOBJECT: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(dummy_item_base_t);
	a = 0xA4;
	printf("dummy_item_base_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(dummy_vehicle_t);
	a = 0x160;
	printf("dummy_vehicle_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");	

	r = sizeof(event_caster_t);
	a = 0x18;
	printf("event_caster_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(FLOWCONTROL);
	a = 0x58;
	printf("FLOWCONTROL: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(GAMETIME);
	a = 0xC8;
	printf("GAMETIME: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(HOTSPOT);
	a = 0x54;
	printf("HOTSPOT: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(identity_t);
	a = 0x8;
	printf("identity_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(INPUTCONFIG);
	a = 0x8;
	printf("INPUTCONFIG: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(inventory_data_t);
	a = 0x2C;
	printf("inventory_data_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(INVENTORYHOLDER);
	a = 0x1B8;
	printf("INVENTORYHOLDER: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(i_point_t);
	a = 0x8;
	printf("i_point_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(mesh_coll_sphere_t);
	a = 0x1C;
	printf("mesh_coll_sphere_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3CAMERA);
	a = 0x258;
	printf("N3CAMERA: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3CELLMONITOR);
	a = 0x38;
	printf("N3CELLMONITOR: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(n3_dynel_t);
	a = 0xA0;
	printf("n3_dynel_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3DYNELEVENTSOURCE);
	a = 0x8;
	printf("N3DYNELEVENTSOURCE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(n3_dyna_mesh_coll_sphere_t);
	a = 0x30;
	printf("n3_dyna_mesh_coll_sphere_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(n3_engine_client_anarchy_t);
	a = 0x130;
	printf("n3_engine_client_anarchy_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3FOBJ);
	a = 0x18;
	printf("N3FOBJ: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(n3_fsm_t);
	a = 0x1C;
	printf("n3_fsm_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3OBJECTFACTORY);
	a = 0x8;
	printf("N3OBJECTFACTORY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3ROOT);
	a = 0x3C;
	printf("N3ROOT: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(n3_sf_base_t);
	a = 0x8;
	printf("n3_sf_base_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(n3_tile_map_t);
	a = 0x424;
	printf("n3_tile_map_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3VISUALDYNEL);
	a = 0xE0;
	printf("N3VISUALDYNEL: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(NANOITEM);
	a = 0xC0;
	printf("NANOITEM: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(NANOTEMPLATE);
	a = 0x1C;
	printf("NANOTEMPLATE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(new_inventory_t);
	a = 0x2C;
	printf("new_inventory_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(PLAYFIELDANARCHY);
	a = 0x110;
	printf("PLAYFIELDANARCHY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(quaternion_t);
	a = 0x10;
	printf("quaternion_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(rdb_identity_t);
	a = 0xC;
	printf("rdb_identity_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(RDBPLAYFIELD);
	a = 0x6C;
	printf("RDBPLAYFIELD: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(RDBTILEMAP);
	a = 0x8270;
	printf("RDBTILEMAP: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(REFERENCECOUNTED);
	a = 0x8;
	printf("REFERENCECOUNTED: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(SIMPLECHAR);
	a = 0x2D8;
	printf("SIMPLECHAR: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(SPELLTEMPLATEDATA);
	a = 0x50;
	printf("SPELLANDTEMPLATEDATA: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(vector3_t);
	a = 0xC;
	printf("vector3_t: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(WEAPONHOLDER);
	a = 0xA4;
	printf("WEAPONHOLDER: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(WEAPONITEM);
	a = 0x204;
	printf("WEAPONITEM: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");
	
	r = sizeof(Character);
	a = sizeof(Player);
	printf("LocalPlayer: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	return 0;
}

#pragma endregion

#pragma region Game Commands

int CMD_ACTIVATE(int argc, char *argv[])
{
	if(isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		return Activate(1, argc, argv);
	return 0;
}

int CMD_AOECHO(int argc, char *argv[])
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		return AOEcho(argc, argv);
	return 0;
}

int CMD_AOEXECUTE(int argc, char *argv[])
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		return AOExecute(argc, argv);
	return 0;
}

int CMD_CAST(int argc, char *argv[])
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		return Cast(1, argc, argv);
	return 0;
}

int CMD_FACE(int argc, char *argv[])
{ 
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		return Face(argc, argv);
	return 0;
}

int CMD_TARGET(int argc, char *argv[])
{
	if (isxao_utilities::GetGameState() == GAMESTATE_IN_GAME)
		return Target(argc, argv);
	return 0;
}

#pragma endregion