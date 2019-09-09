#include "isxao_main.h"

namespace isxao_commands
{
	
	bool IsISXAOCommand(PCHAR text)
	{
		//char command[MAX_STRING];
		//strcpy_s(command, sizeof(command), text);
		//_strlwr_s(command);
		//if (!strcmp(command, "/activate"))
		//	return true;
		//if (!strcmp(command, "/aoecho"))
		//	return true;
		//if (!strcmp(command, "/aoexecute"))
		//	return true;
		//if (!strcmp(command, "/cast"))
		//	return true;
		//if (!strcmp(command, "/face"))
		//	return true;
		//if (!strcmp(command, "/target"))
		//	return true;
		return false;
	}

	DWORD Activate(int begin_inclusive, int argc, char *argv[])
	{
		//if (argc < (1 + begin_inclusive)) // No arguments provided
		//	return 0;
		//if (argc == (1 + begin_inclusive)) // Slot name provided
		//{
		//	if (IsNumber(argv[(0 + begin_inclusive)]))
		//		return 0;
		//	identity_t inv_slot_identity;
		//	if (GetInvSlotIdentity(argv[(0 + begin_inclusive)], inv_slot_identity))
		//	{
		//		P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//		return 1;
		//	}
		//	return 0;
		//}
		//if (argc > (1 + begin_inclusive)) // Slot name and target provided
		//{
		//	if (IsNumber(argv[(0 + begin_inclusive)])) // Make sure the first argument is a string, not a number
		//		return 0;
		//	identity_t inv_slot_identity;
		//	auto valid_slot = isxao_utilities::GetInvSlotIdentity(argv[(0 + begin_inclusive)], inv_slot_identity);
		//	if (!valid_slot)
		//		return 0;
		//	if(IsNumber(argv[(1 + begin_inclusive)])) // Second argument is an identity
		//	{
		//		identity_t previous_target;
		//		DWORD64 target_id = atoui64(argv[(1 + begin_inclusive)]);
		//		identity_t target_identity = identity_t::get_identity_from_combined(target_id);
		//		dynel* pDynel = isxao_utilities::GetDynel(target_identity);
		//		if(pDynel)
		//		{
		//			if(!pSelectionIndicator) // No Current Target
		//			{
		//				pTargetingModule->SetTarget(target_identity, false);
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//				pTargetingModule->RemoveTarget(pSelectionIndicator->Identity);
		//				return 1;
		//			}
		//			if(pSelectionIndicator->Identity == target_identity)// Current Target Is Desired Target
		//			{
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//				return 1;
		//			}
		//			// Current Target Is NOT Desired Target
		//			pTargetingModule->RemoveTarget(pSelectionIndicator->Identity); // Saves the current target to pLastTarget
		//			pTargetingModule->SetTarget(target_identity, false);
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//			pTargetingModule->SetTarget(*pLastTarget, false); // Switches the target back to the previous target
		//			return 1;
		//		}
		//		return 0;
		//	}
		//	char second_arg[MAX_STRING]; // Second argument is a string
		//	strcpy_s(second_arg, sizeof(second_arg), argv[(1 + begin_inclusive)]);
		//	_strlwr_s(second_arg);
		//	if(!strcmp(second_arg, "me")) // Check to see it the target is "me"
		//	{
		//		if(!pSelectionIndicator) // No current target
		//		{
		//			pTargetingModule->SetTarget(P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetIdentity(), false);
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//			pTargetingModule->RemoveTarget(pSelectionIndicator->Identity);
		//			return 1;
		//		}
		//		if(pSelectionIndicator->Identity == P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetIdentity()) // Current target is deisred target
		//		{
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//			return 1;
		//		}
		//		// Current target is NOT the desired target
		//		pTargetingModule->RemoveTarget(pSelectionIndicator->Identity);
		//		pTargetingModule->SetTarget(P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetIdentity(), false);
		//		P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//		pTargetingModule->SetTarget(*pLastTarget, false);
		//		return 1;
		//	}
		//	identity_t target_identity; // Find the actor identity that matches the name provided
		//	string name(argv[(1 + begin_inclusive)]);
		//	bool valid_target = P_ENGINE_CLIENT_ANARCHY->N3Msg_NameToID(name, target_identity);
		//	if (valid_target)
		//	{
		//		if (!pSelectionIndicator) // No Current Target
		//		{
		//			pTargetingModule->SetTarget(target_identity, false);
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//			pTargetingModule->RemoveTarget(pSelectionIndicator->Identity);
		//			return 1;
		//		}
		//		if (pSelectionIndicator->Identity == target_identity)// Current Target Is Desired Target
		//		{
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//			return 1;
		//		}
		//		// Current Target Is NOT Desired Target
		//		pTargetingModule->RemoveTarget(pSelectionIndicator->Identity); // Saves the current target to pLastTarget
		//		pTargetingModule->SetTarget(target_identity, false);
		//		P_ENGINE_CLIENT_ANARCHY->N3Msg_UseItem(inv_slot_identity, false);
		//		pTargetingModule->SetTarget(*pLastTarget, false); // Switches the target back to the previous target
		//		return 1;
		//	}
		//	return 0;
		//}
		return 0;		
	}

	DWORD AOEcho(int argc, char *argv[])
	{
		//if (argc > 1)
		//{
		//	bool chat_type_used = false;
		//	char chat_color_name[MAX_STRING] = "ct_system";
		//	char chat_type[MAX_STRING];
		//	char first_arg[MAX_STRING];
		//	if (argv[1][0] == '-' && argc > 2) // check for chat config type
		//	{
		//		strcpy_s(first_arg, MAX_STRING, argv[1]);
		//		_strlwr_s(first_arg);
		//		if (!strcmp(first_arg, "-chattype"))
		//		{
		//			strcpy_s(chat_type, MAX_STRING, argv[2]);
		//			_strlwr_s(chat_type);
		//			if (!strcmp(chat_type, "black"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "black");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "green"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "green");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "silver"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "silver");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "lime"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "lime");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "gray"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "gray");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "olive"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "olive");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "white"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "white");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "yellow"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "yellow");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "maroon"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "maroon");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "navy"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "navy");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "red"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "red");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "blue"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "blue");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "purple"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "purple");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "teal"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "teal");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "fuchsia"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "fuchsia");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "aqua"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "aqua");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "error"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ct_error");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "system"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ct_system");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "cmdfeedback"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ct_cmd_feedback");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "otell"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ct_otell");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "itell"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ct_itell");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "admin"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_admin");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "clan"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_clan");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "emote"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_emote");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "gm"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_gm");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "misc"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_misc");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "newbie"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_newbie");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "news"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_news");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "pgroup"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_pgroup");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "seekingteam"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_seekingteam");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "shout"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_shout");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "team"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_team");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "raid"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_raid");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "tell"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_tell");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "vicinity"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_vicinity");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "whisper"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_whisper");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "tower"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_tower");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "mypet"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_mypet");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "otherpet"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_otherpet");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "research"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "ctch_research");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "none"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNoneColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "comm"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCCommColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "mehitbynano"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCMeHitByNanoColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "otherhitbynano"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCOtherHitByNanoColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "monsterhitme"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCMonsterHitMeColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "playerhitme"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCPlayerHitMeColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "mehitother"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCMeHitOtherColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "otherhitothermypet"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCOtherHitOtherMyPetColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "mehealed"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCMeHealedColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "megotxp"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCMeGotXpColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "mecastnano"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCMeCastNano");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "skill"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCSkillColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "showfullname"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCShowFullNameColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "link"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCLinkColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "tooltip"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCToolTipColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "cash"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCCashColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "infoheadline"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCInfoHeadline");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "infoheader"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCInfoHeader");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "infotext"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCInfoText");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "infotextbold"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCInfoTextBold");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "text"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCCCTextColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "header"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCCCHeaderColor");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "npcchat"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNPCChatText");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "npcooc"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNPCOOCText");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "npcemote"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNPCChatEmote");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "npcsystem"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNPCChatSystem");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "npcquestion"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNPCChatQuestion");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "npcdescription"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNPCChatDescription");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "npctrade"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCNPCChatTrade");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "itemunknown"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCItemUnknown");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "itemtrash"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCItemTrash");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "itemnormal"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCItemNormal");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "itemexotic"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCItemExotic");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "itemquest"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCItemQuest");
		//				chat_type_used = true;
		//			}
		//			else if (!strcmp(chat_type, "itemsocial"))
		//			{
		//				strcpy_s(chat_color_name, MAX_STRING, "CCItemSocial");
		//				chat_type_used = true;
		//			}
		//		}
		//	}
		//	string s;
		//	string message;
		//	int i;
		//	if (chat_type_used)
		//		i = 3;
		//	else
		//		i = 1;
		//	for (i; i < argc; i++)
		//	{
		//		if (i == argc - 1)
		//		{
		//			s += string(argv[i]);
		//		}
		//		else
		//		{
		//			s += string(argv[i]) + ' ';
		//		}
		//	}
		//	message = "<font color=\"" + string(chat_color_name) + "\">" + s + "</font>";
		//	pCommandInterpreter->ParseText(message);
		//	return 1;
		//}
		return 0;
	}

	DWORD AOExecute(int argc, char *argv[])
	{
		//if (argc > 1)
		//{
		//	if (argv[1][0] != '/')
		//		return 0;
		//	string s;
		//	// Build the command string from argv
		//	for (auto i = 1; i < argc; i++)
		//	{
		//		// Check to see it is the last element. If it is, do not include a space at the end.
		//		if (i == argc - 1)
		//			s += string(argv[i]);
		//		else
		//			s += string(argv[i]) + ' ';
		//	}
		//	pCommandInterpreter->ParseText(s);
		//	return 1;
		//}
		return 0;
	}

	DWORD Attack(int begin_inclusive, int argc, char *argv[])
	{
		//if(argc >= (1 + begin_inclusive))
		//{
		//	if(argc == (1 + begin_inclusive)) // exactly 1 argument provided
		//	{
		//		if (IsNumber(argv[0 + begin_inclusive]))
		//			return 0;
		//		char first_arg[MAX_STRING];
		//		strcpy_s(first_arg, sizeof(first_arg), argv[0 + begin_inclusive]);
		//		_strlwr_s(first_arg);
		//		if(!strcmp(first_arg, "off"))
		//		{
		//			if(P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetWeaponHolder()->IsAttacking())
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_StopAttack();
		//			return 1;
		//		}
		//		if(!strcmp(first_arg, "on"))
		//		{
		//			if (!P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetWeaponHolder()->IsAttacking() && pSelectionIndicator) // not already attacking something and has a selection target
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_DefaultAttack(pSelectionIndicator->Identity, true);
		//			return 1;
		//		}
		//		return 0;
		//	}
		//	if(argc > (1 + begin_inclusive))
		//	{
		//		
		//	}
		//}
		return 0;
	}

	DWORD Cast(int begin_inclusive, int argc, char *argv[])
	{
		//if(argc >= (1 + begin_inclusive))
		//{
		//	if(argc == (1 + begin_inclusive) && IsNumber(argv[(0 + begin_inclusive)]))
		//	{
		//		auto nano_id = atoi(argv[(0 + begin_inclusive)]);
		//		NanoItem* pNanoSpell;
		//		if((pNanoSpell = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(nano_id))))
		//		{
		//			pNanoSpell->Cast();
		//			return 1;
		//		}
		//		return 0;					
		//	}
		//	if (argc == (1 + begin_inclusive) && !IsNumber(argv[(0 + begin_inclusive)]))
		//	{
		//		char name[MAX_STRING];
		//		char search_name[MAX_STRING];
		//		strcpy_s(search_name, sizeof(search_name), argv[(0 + begin_inclusive)]);
		//		_strlwr_s(search_name);
		//		std::vector<DWORD> v;
		//		P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetSpellTemplateData()->GetNanoSpellList(v);
		//		for (auto it = v.begin(); it != v.end(); ++it)
		//		{
		//			NanoItem* pNanoSpell = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(*it));
		//			strcpy_s(name, sizeof(name), pNanoSpell->GetName());
		//			_strlwr_s(name);
		//			if (strstr(name, search_name))
		//			{
		//				pNanoSpell->Cast();
		//				return 1;
		//			}						
		//		}
		//		return 0;
		//	}
		//	if(argc >= (2 + begin_inclusive) && IsNumber(argv[(0 + begin_inclusive)]) && IsNumber(argv[(1 + begin_inclusive)])) // nanoid, targetid
		//	{
		//		DWORD nano_id = atoi(argv[(0 + begin_inclusive)]);
		//		identity_t nano_identity;
		//		nano_identity.Type = 53019;
		//		nano_identity.Id = nano_id;
		//		DWORD64 target_id = atoui64(argv[(1 + begin_inclusive)]);
		//		identity_t target_identity = identity_t::get_identity_from_combined(target_id);
		//		NanoItem* pNanoItem = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(nano_id));
		//		dynel* pTarget = isxao_utilities::GetDynel(target_identity);
		//		if(pNanoItem && pTarget)
		//		{
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_CastNanoSpell(nano_identity, target_identity);
		//			return 1;
		//		}
		//		return 0;
		//	}
		//	if(argc >= (2 + begin_inclusive) && IsNumber(argv[(0 + begin_inclusive)]) && !IsNumber(argv[(1 + begin_inclusive)])) // nanoid, targetname
		//	{				
		//		DWORD nano_id = atoi(argv[(0 + begin_inclusive)]);
		//		identity_t nano_identity;
		//		nano_identity.Type = 53019;
		//		nano_identity.Id = nano_id;
		//		NanoItem* pNanoItem = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(nano_id));		
		//		bool valid_target = false;
		//		char second_arg[MAX_STRING];
		//		strcpy_s(second_arg, sizeof(second_arg), argv[(1 + begin_inclusive)]);
		//		_strlwr_s(second_arg);
		//		identity_t target_identity;
		//		if (!strcmp(second_arg, "me"))
		//		{
		//			P_ENGINE_CLIENT_ANARCHY->GetClientDynelId(target_identity);
		//			valid_target = true;
		//		}
		//		else
		//		{
		//			std::string name(argv[(1 + begin_inclusive)]);
		//			valid_target = P_ENGINE_CLIENT_ANARCHY->N3Msg_NameToID(name, target_identity);
		//		}
		//		if (pNanoItem && valid_target)
		//		{
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_CastNanoSpell(nano_identity, target_identity);
		//			return 1;
		//		}
		//		return 0;
		//	}
		//	if (argc >= (2 + begin_inclusive) && !IsNumber(argv[(0 + begin_inclusive)]) && IsNumber(argv[(1 + begin_inclusive)])) // nanoname, targetid
		//	{
		//		identity_t nano_identity;
		//		ZeroMemory(&nano_identity, sizeof(identity_t));
		//		char name[MAX_STRING];
		//		char search_name[MAX_STRING];
		//		strcpy_s(search_name, sizeof(search_name), argv[(0 + begin_inclusive)]);
		//		_strlwr_s(search_name);
		//		std::vector<DWORD> v;
		//		P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetSpellTemplateData()->GetNanoSpellList(v);
		//		for (auto it = v.begin(); it != v.end(); ++it)
		//		{
		//			NanoItem* pNanoSpell = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(*it));
		//			strcpy_s(name, sizeof(name), pNanoSpell->GetName());
		//			_strlwr_s(name);
		//			if (strstr(name, search_name))
		//			{
		//				nano_identity = pNanoSpell->GetNanoIdentity();
		//				break;
		//			}
		//		}
		//		if (nano_identity.Id == 0)
		//			return 0;
		//		DWORD64 target_id = atoui64(argv[(1 + begin_inclusive)]);
		//		identity_t target_identity = identity_t::get_identity_from_combined(target_id);
		//		dynel* pTarget = isxao_utilities::GetDynel(target_identity);
		//		if (!pTarget)
		//			return 0;
		//		P_ENGINE_CLIENT_ANARCHY->N3Msg_CastNanoSpell(nano_identity, target_identity);
		//		return 1;
		//	}
		//	if (argc >= (2 + begin_inclusive) && !IsNumber(argv[(0 + begin_inclusive)]) && !IsNumber(argv[(1 + begin_inclusive)])) // nanoname, targetname
		//	{
		//		identity_t nano_identity;
		//		ZeroMemory(&nano_identity, sizeof(identity_t));
		//		char name[MAX_STRING];
		//		char search_name[MAX_STRING];
		//		strcpy_s(search_name, sizeof(search_name), argv[(0 + begin_inclusive)]);
		//		_strlwr_s(search_name);
		//		std::vector<DWORD> v;
		//		P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetSpellTemplateData()->GetNanoSpellList(v);
		//		for (auto it = v.begin(); it != v.end(); ++it)
		//		{
		//			NanoItem* pNanoSpell = reinterpret_cast<NanoItem*>(isxao_utilities::GetNanoItem(*it));
		//			strcpy_s(name, sizeof(name), pNanoSpell->GetName());
		//			_strlwr_s(name);
		//			if (strstr(name, search_name))
		//			{
		//				nano_identity = pNanoSpell->GetNanoIdentity();
		//				break;
		//			}
		//		}
		//		if (nano_identity.Id == 0)
		//			return 0;
		//		bool valid_target = false;
		//		char second_arg[MAX_STRING];
		//		strcpy_s(second_arg, sizeof(second_arg), argv[(1 + begin_inclusive)]);
		//		_strlwr_s(second_arg);
		//		identity_t target_identity;
		//		if (!strcmp(second_arg, "me"))
		//		{
		//			P_ENGINE_CLIENT_ANARCHY->GetClientDynelId(target_identity);
		//			valid_target = true;
		//		}
		//		else
		//		{
		//			std::string target_name(argv[(0 + begin_inclusive)]);
		//			valid_target = P_ENGINE_CLIENT_ANARCHY->N3Msg_NameToID(target_name, target_identity);
		//		}
		//		if (valid_target)
		//		{
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_CastNanoSpell(nano_identity, target_identity);
		//			return 1;
		//		}
		//		return 0;
		//	}
		//}
		return 0;
	}

	DWORD DoAction(int argc, char* argv[])
	{
		//if(argc >= 2)
		//{
		//	if (argc == 2) // Only one argument provided
		//	{
		//		if(IsNumber(argv[1])) // ActionId 
		//		{
		//			identity_t action_identity;
		//			action_identity.Type = 57008;
		//			action_identity.Id = atoi(argv[1]);
		//			P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(action_identity);
		//			return 1;
		//		}
		//		char name[MAX_STRING]; // ActionName
		//		char search_name[MAX_STRING];
		//		strcpy_s(search_name, sizeof(search_name), argv[1]);
		//		_strlwr_s(search_name);
		//		std::vector<SpecialActionTemplate*> v;
		//		P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetSpecialActionHolder()->GetSpecialActions(v);
		//		identity_t dummy_identity;
		//		for (auto it = v.begin(); it != v.end(); ++it)
		//		{
		//			PCSTR action_name = P_ENGINE_CLIENT_ANARCHY->N3Msg_GetName((*it)->GetIdentity(), dummy_identity);
		//			strcpy_s(name, sizeof(name), action_name);
		//			_strlwr_s(name);
		//			if(strstr(name, search_name))
		//			{
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction((*it)->GetIdentity());
		//				return 1;
		//			}
		//		}
		//		return 0;
		//	}
		//	if (argc > 2) // At least two arguments provided
		//	{
		//		if(IsNumber(argv[1]) && IsNumber(argv[2])) // ActionId, TargetId
		//		{
		//			identity_t action_identity;
		//			action_identity.Type = 57008;
		//			action_identity.Id = atoi(argv[1]);
		//			DWORD64 comb_target_identity = atoui64(argv[2]);
		//			identity_t target_identity = identity_t::get_identity_from_combined(comb_target_identity);
		//			dynel* pDynel = isxao_utilities::GetDynel(target_identity);
		//			if(pDynel)
		//			{
		//				bool has_current_target = pSelectionIndicator != nullptr;
		//				bool current_target_is_desired_target = (pSelectionIndicator != nullptr) && (pSelectionIndicator->Identity == target_identity);
		//				if(!current_target_is_desired_target)
		//				{
		//					if(has_current_target)
		//						pTargetingModule->RemoveTarget(pSelectionIndicator->Identity); // Stores the old target's identity in pLastTarget
		//					pTargetingModule->SetTarget(target_identity, false);
		//				}
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(action_identity);
		//				if(!current_target_is_desired_target)
		//				{
		//					if (has_current_target)
		//						pTargetingModule->SetTarget(*pLastTarget, false);
		//				}
		//				return 1;
		//			}
		//			return 0;
		//		}
		//		if(IsNumber(argv[1]) && !IsNumber(argv[2])) // ActionId, TargetName
		//		{
		//			identity_t action_identity;
		//			action_identity.Type = 57008;
		//			action_identity.Id = atoi(argv[1]);
		//			identity_t target_identity;
		//			string target_name(argv[2]);
		//			bool valid_target = P_ENGINE_CLIENT_ANARCHY->N3Msg_NameToID(target_name, target_identity);
		//			if(valid_target)
		//			{
		//				bool has_current_target = pSelectionIndicator != nullptr;
		//				bool current_target_is_desired_target = (pSelectionIndicator != nullptr) && (pSelectionIndicator->Identity == target_identity);
		//				if (!current_target_is_desired_target)
		//				{
		//					if (has_current_target)
		//						pTargetingModule->RemoveTarget(pSelectionIndicator->Identity); // Stores the old target's identity in pLastTarget
		//					pTargetingModule->SetTarget(target_identity, false);
		//				}
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(action_identity);
		//				if (!current_target_is_desired_target)
		//				{
		//					if (has_current_target)
		//						pTargetingModule->SetTarget(*pLastTarget, false);
		//				}
		//				return 1;
		//			}
		//			return 0;
		//		}
		//		if(!IsNumber(argv[1]) && IsNumber(argv[2])) // ActionName, TargetId
		//		{
		//			char name[MAX_STRING]; // ActionName
		//			char search_name[MAX_STRING];
		//			strcpy_s(search_name, sizeof(search_name), argv[1]);
		//			_strlwr_s(search_name);
		//			std::vector<SpecialActionTemplate*> v;
		//			P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetSpecialActionHolder()->GetSpecialActions(v);
		//			identity_t dummy_identity;
		//			identity_t action_identity;
		//			bool valid_action = false;
		//			for (auto it = v.begin(); it != v.end(); ++it)
		//			{
		//				PCSTR action_name = P_ENGINE_CLIENT_ANARCHY->N3Msg_GetName((*it)->GetIdentity(), dummy_identity);
		//				strcpy_s(name, sizeof(name), action_name);
		//				_strlwr_s(name);
		//				if (strstr(name, search_name))
		//				{
		//					action_identity = (*it)->GetIdentity();
		//					valid_action = true;
		//					break;
		//				}
		//			}
		//			DWORD64 comb_target_identity = atoui64(argv[2]);
		//			identity_t target_identity = identity_t::get_identity_from_combined(comb_target_identity);
		//			dynel* pDynel = isxao_utilities::GetDynel(target_identity);
		//			if(valid_action && pDynel)
		//			{
		//				bool has_current_target = pSelectionIndicator != nullptr;
		//				bool current_target_is_desired_target = (pSelectionIndicator != nullptr) && (pSelectionIndicator->Identity == target_identity);
		//				if (!current_target_is_desired_target)
		//				{
		//					if (has_current_target)
		//						pTargetingModule->RemoveTarget(pSelectionIndicator->Identity); // Stores the old target's identity in pLastTarget
		//					pTargetingModule->SetTarget(target_identity, false);
		//				}
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(action_identity);
		//				if (!current_target_is_desired_target)
		//				{
		//					if (has_current_target)
		//						pTargetingModule->SetTarget(*pLastTarget, false);
		//				}
		//				return 1;
		//			}
		//			return 0;
		//		}
		//		if (!IsNumber(argv[1]) && !IsNumber(argv[2])) // ActionName, TargetName
		//		{
		//			char name[MAX_STRING]; // ActionName
		//			char search_name[MAX_STRING];
		//			strcpy_s(search_name, sizeof(search_name), argv[1]);
		//			_strlwr_s(search_name);
		//			std::vector<SpecialActionTemplate*> v;
		//			P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetSpecialActionHolder()->GetSpecialActions(v);
		//			identity_t dummy_identity;
		//			identity_t action_identity;
		//			bool valid_action = false;
		//			for (auto it = v.begin(); it != v.end(); ++it)
		//			{
		//				PCSTR action_name = P_ENGINE_CLIENT_ANARCHY->N3Msg_GetName((*it)->GetIdentity(), dummy_identity);
		//				strcpy_s(name, sizeof(name), action_name);
		//				_strlwr_s(name);
		//				if (strstr(name, search_name))
		//				{
		//					action_identity = (*it)->GetIdentity();
		//					valid_action = true;
		//					break;
		//				}
		//			}
		//			identity_t target_identity;
		//			string target_name(argv[2]);
		//			bool valid_target = P_ENGINE_CLIENT_ANARCHY->N3Msg_NameToID(target_name, target_identity);
		//			if(valid_action && valid_target)
		//			{
		//				bool has_current_target = pSelectionIndicator != nullptr;
		//				bool current_target_is_desired_target = (pSelectionIndicator != nullptr) && (pSelectionIndicator->Identity == target_identity);
		//				if (!current_target_is_desired_target)
		//				{
		//					if (has_current_target)
		//						pTargetingModule->RemoveTarget(pSelectionIndicator->Identity); // Stores the old target's identity in pLastTarget
		//					pTargetingModule->SetTarget(target_identity, false);
		//				}
		//				P_ENGINE_CLIENT_ANARCHY->N3Msg_PerformSpecialAction(action_identity);
		//				if (!current_target_is_desired_target)
		//				{
		//					if (has_current_target)
		//						pTargetingModule->SetTarget(*pLastTarget, false);
		//				}
		//				return 1;
		//			}
		//			return 0;
		//		}
		//	}
		//	return 0;
		//}
		return 0;
	}

	DWORD Face(int argc, char *argv[])
	{
		//if (argc > 1)
		//{
		//	if (argc == 2 && !IsNumber(argv[1])) // Check to see if a name was provided
		//	{
		//		char search_name[MAX_STRING];
		//		strcpy_s(search_name, MAX_STRING, argv[1]);
		//		_strlwr_s(search_name);
		//		std::vector<Actor*> v;
		//		P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
		//		for (auto it = v.begin(); it != v.end(); ++it)
		//		{
		//			char name[MAX_STRING];
		//			strcpy_s(name, MAX_STRING, (*it)->GetName());
		//			_strlwr_s(name);
		//			if (strstr(name, search_name))
		//			{
		//				(*it)->DoFace();
		//				return 1;
		//			}
		//		}
		//		return 0;
		//	}
		//	if (argc == 2 && IsNumber(argv[1])) // Check to see if a heading was provided
		//	{
		//		auto heading = float(atof(argv[1]));
		//		if (heading < 0.0f || heading > 360.0f)
		//			return 0;
		//		if (heading > 180.0f)
		//			heading -= 360.0f;
		//		heading = float(heading * 2 * M_PI / 360.0f);
		//		P_ENGINE_CLIENT_ANARCHY->GetClientChar()->Face(heading);
		//		return 1;
		//	}
		//	if (argc == 3 && IsNumber(argv[1]) && IsNumber(argv[2])) // Check to see if X and Z coords provided
		//	{
		//		vector3_t v;
		//		v.X = float(atof(argv[1]));
		//		v.Y = 0.0f;
		//		v.Z = float(atof(argv[2]));
		//		P_ENGINE_CLIENT_ANARCHY->GetClientChar()->Face(v);
		//		return 1;
		//	}
		//	if (argc == 4 && IsNumber(argv[1]) && IsNumber(argv[2]) && IsNumber(argv[3]))
		//	{
		//		vector3_t v;
		//		v.X = float(atof(argv[1]));
		//		v.Y = 0.0f;
		//		v.Z = float(atof(argv[3]));
		//		P_ENGINE_CLIENT_ANARCHY->GetClientChar()->Face(v);
		//		return 1;
		//	}
		//	return 0;
		//}
		//// If no arguments are provided, we should try to face our current target
		//if (pSelectionIndicator)
		//{
		//	static_cast<Actor*>(isxao_utilities::GetDynel(pSelectionIndicator->Identity))->DoFace();
		//	return 1;
		//}
		return 0;
	}

	DWORD Target(int argc, char *argv[])
	{
		//if (argc < 2)
		//	return 0;
		//if (IsNumber(argv[1]))	// Check to see if an Id was provided
		//{
		//	auto combined_identity = atoui64(argv[1]);
		//	identity_t id = identity_t::get_identity_from_combined(combined_identity);
		//	auto pDynel = isxao_utilities::GetDynel(id);
		//	if (pDynel)
		//	{
		//		pTargetingModule->SetTarget(id, false);
		//		return 1;
		//	}
		//	return 0;
		//}
		//char arg[MAX_STRING];
		//strcpy_s(arg, MAX_STRING, argv[1]);
		//_strlwr_s(arg);		
		//if (!strcmp(arg, "me")) // Check for me
		//{
		//	pTargetingModule->SelectSelf();
		//	return 1;
		//}
		//std::vector<Actor*> v;
		//P_PLAYFIELD_DIR->GetPlayfield()->GetPlayfieldActors(v);
		//if (!strcmp(arg, "pc")) // Check for nearest pc
		//{
		//	for (auto it = v.begin(); it != v.end(); ++it)
		//	{
		//		if ((*it)->IsPlayer() && !IsClientId((*it)->GetIdentity().Id))
		//		{
		//			pTargetingModule->SetTarget((*it)->GetIdentity(), false);
		//			return 1;
		//		}
		//	}
		//}
		//if (!strcmp(arg, "npc")) // check for nearest npc
		//{
		//	for (auto it = v.begin(); it != v.end(); ++it)
		//	{
		//		if ((*it)->IsNPC() && !(*it)->IsPet())
		//		{
		//			pTargetingModule->SetTarget((*it)->GetIdentity(), false);
		//			return 1;
		//		}
		//	}
		//}
		//if (!strcmp(arg, "pet")) // check for nearest pet
		//{
		//	for (auto it = v.begin(); it != v.end(); ++it)
		//	{
		//		if ((*it)->IsPet())
		//		{
		//			pTargetingModule->SetTarget((*it)->GetIdentity(), false);
		//			return 1;
		//		}
		//	}
		//}
		//for (auto it = v.begin(); it != v.end(); ++it) // Assume it is a name
		//{
		//	char name[MAX_STRING];
		//	strcpy_s(name, MAX_STRING, (*it)->GetName());
		//	_strlwr_s(name);
		//	if (strstr(name, arg))
		//	{
		//		pTargetingModule->SetTarget((*it)->GetIdentity(), false);
		//		return 1;
		//	}
		//}
		return 0;
	}

}