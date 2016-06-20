#include "isxao_main.h"

#define _USE_MATH_CONSTANTS
#include <math.h>

#pragma region Testing and Debugging

int CMD_AO(int argc, char *argv[])
{
	IDENTITY dummy;
	std::vector<SpecialAction*> v;
	pEngineClientAnarchy->GetClientChar()->GetSpecialActionHolder()->GetSpecialActions(v);

	FILE * pFILE;
	fopen_s(&pFILE, "stats.txt", "a");
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		IDENTITY id = (*it)->GetIdentity();
		char buffer[MAX_STRING];
		sprintf_s(buffer, sizeof(buffer), "%s\n", pEngineClientAnarchy->N3Msg_GetName(id, dummy));
		fputs(buffer, pFILE);

		for (DWORD i = 0; i < 1003; i++)
		{
			LONG stat = pEngineClientAnarchy->N3Msg_GetSkill(id, i, 2, dummy);
			if(stat != 1234567890)
			{
				sprintf_s(buffer, "\tST_%s (%d) = %d,\n", isxao_utilities::StatToString(i), i, stat);
				for (auto i = 0; i < (int)strlen(buffer); i++)
					buffer[i] = toupper(buffer[i]);
				fputs(buffer, pFILE);
			}			
		}		
	}
	fclose(pFILE);

	return 1;
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
	IDENTITY id;
	IDENTITY dummy;
	if (pEngineClientAnarchy->GetClientChar()->GetTarget(id))
	{
		FILE * pFILE;
		fopen_s(&pFILE, "stats.txt", "a");
		std::map<DWORD, const char *> m;
		GetStatNameMap(m);
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			char buffer[MAX_STRING];
			LONG stat = pEngineClientAnarchy->N3Msg_GetSkill(id, static_cast<AOData::Stat_e>((*it).first), 2, dummy);
			sprintf_s(buffer, "ST_%s = %d,\n", (*it).second, /*(*it).first*/stat);
			for (auto i = 0; i < (int)strlen(buffer); i++)
				buffer[i] = toupper(buffer[i]);
			fputs(buffer, pFILE);

		}
		fclose(pFILE);
	}
	//if (pEngineClientAnarchy->GetWeaponTarget(id))
	//{
	//	FILE * pFILE;
	//	pFILE = fopen("stats.txt", "a");
	//	std::map<DWORD, const char *> m;
	//	pEngineClientAnarchy->GetStatNameMap(m);
	//	for (auto it = m.begin(); it != m.end(); ++it)
	//	{
	//		char buffer[MAX_STRING];
	//		LONG stat = pEngineClientAnarchy->GetSkill(id, static_cast<AOData::Stat_e>((*it).first));
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
	IDENTITY p1;
	IDENTITY p2;
	pEngineClientAnarchy->N3Msg_GetClientPetID(p1, 0);
	printf("%d", p1.Id);
	pEngineClientAnarchy->N3Msg_GetClientPetID(p2, 1);
	printf("%d", p2.Id);
	return 0;
}

int CMD_TESTSTRUCTS(int argc, char *argv[])
{	
	printf("Testing struct sizes...");

	DWORD r = sizeof(BANKENTRY);
	DWORD a = 0x38;
	printf("BANKENTRY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(BINARYSTREAM);
	a = 0x44;
	printf("BINARYSTREAM: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(CAMERAVEHICLE);
	a = 0x1EC;
	printf("CAMERAVEHICLE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(CHARMOVEMENTSTATUS);
	a = 0x34;
	printf("CHARMOVEMENTSTATUS: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(CHARVEHICLE);
	a = 0x3AC;
	printf("CHARVEHICLE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(CHEST);
	a = 0x1E8;
	printf("CHEST: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(COLLINFO);
	a = 0x14;
	printf("COLLINFO: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(COLLPRIM);
	a = 0x18;
	printf("COLLPRIM: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(COLLSPHERE);
	a = 0x1C;
	printf("COLLSPHERE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(DBOBJECT);
	a = 0x18;
	printf("DBOBJECT: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(DUMMYITEMBASE);
	a = 0xA4;
	printf("DUMMYITEMBASE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(DUMMYVEHICLE);
	a = 0x160;
	printf("DUMMYVEHICLE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");	

	r = sizeof(EVENTCASTER);
	a = 0x18;
	printf("EVENTCASTER: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(FLOWCONTROL);
	a = 0x58;
	printf("FLOWCONTROL: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(GAMETIME);
	a = 0xC8;
	printf("GAMETIME: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(HOTSPOT);
	a = 0x54;
	printf("HOTSPOT: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(IDENTITY);
	a = 0x8;
	printf("IDENTITY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(INPUTCONFIG);
	a = 0x8;
	printf("INPUTCONFIG: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(INVENTORYDATA);
	a = 0x2C;
	printf("INVENTORYDATA: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(INVENTORYHOLDER);
	a = 0x1B8;
	printf("INVENTORYHOLDER: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(IPOINT);
	a = 0x8;
	printf("IPOINT: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(MESHCOLLSPHERE);
	a = 0x1C;
	printf("MESHCOLLSPHERE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3CAMERA);
	a = 0x258;
	printf("N3CAMERA: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3CELLMONITOR);
	a = 0x38;
	printf("N3CELLMONITOR: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3DYNEL);
	a = 0xA0;
	printf("N3DYNEL: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3DYNELEVENTSOURCE);
	a = 0x8;
	printf("N3DYNELEVENTSOURCE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3DYNAMESHCOLLSPHERE);
	a = 0x30;
	printf("N3DYNAMESHCOLLSPHERE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3ENGINECLIENTANARCHY);
	a = 0x130;
	printf("N3ENGINECLIENTANARCHY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3FOBJ);
	a = 0x18;
	printf("N3FOBJ: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3FSM);
	a = 0x1C;
	printf("N3FSM: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3OBJECTFACTORY);
	a = 0x8;
	printf("N3OBJECTFACTORY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3ROOT);
	a = 0x3C;
	printf("N3ROOT: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3SFBASE);
	a = 0x8;
	printf("N3SFBASE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3TILEMAP);
	a = 0x424;
	printf("N3TILEMAP: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(N3VISUALDYNEL);
	a = 0xE0;
	printf("N3VISUALDYNEL: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(NANOITEM);
	a = 0xC0;
	printf("NANOITEM: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(NANOTEMPLATE);
	a = 0x1C;
	printf("NANOTEMPLATE: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(NEWINVENTORY);
	a = 0x2C;
	printf("NEWINVENTORY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(PLAYFIELDANARCHY);
	a = 0x110;
	printf("PLAYFIELDANARCHY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(QUATERNION);
	a = 0x10;
	printf("QUATERNION: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

	r = sizeof(RDBIDENTITY);
	a = 0xC;
	printf("RDBIDENTITY: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

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

	r = sizeof(VECTOR3);
	a = 0xC;
	printf("VECTOR3: 0x%.8X. Should be 0x%.8X - %s", r, a, r == a ? "Passed" : "FAILED!");

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
		return Activate(argc, argv);
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