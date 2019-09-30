#include "isxao_main.h"
#include "command_interpreter.h"
#include "dynel.h"
#include "engine_client_anarchy.h"
#include "inventory_holder.h"
#include "nano_item.h"
#include "playfield_anarchy.h"
#include "special_action_holder.h"
#include "special_action_template.h"
#include "spell_template_data.h"
#include "targeting_module.h"
#include "weapon_holder.h"

namespace isxao
{
	namespace commands
	{	
		bool IsISXAOCommand(PCHAR text)
		{
			char command[MAX_VARSTRING];
			strcpy_s(command, sizeof(command), text);
			_strlwr_s(command);
			if (!strcmp(command, "/activate"))
				return true;
			if (!strcmp(command, "/aoecho"))
				return true;
			if (!strcmp(command, "/aoexecute"))
				return true;
			if (!strcmp(command, "/cast"))
				return true;
			if (!strcmp(command, "/face"))
				return true;
			if (!strcmp(command, "/target"))
				return true;
			return false;
		}

		DWORD Activate(int begin_inclusive, int argc, char *argv[])
		{
			if (argc < (1 + begin_inclusive)) // No arguments provided
				return 0;
			if (argc == (1 + begin_inclusive)) // Slot name provided
			{
				if (IsNumber(argv[(0 + begin_inclusive)]))
					return 0;
				ao::identity_t inv_slot_identity;
				if (ao::inventory_holder::get_inv_slot_identity(argv[(0 + begin_inclusive)], inv_slot_identity))
				{
					P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
					return 1;
				}
				return 0;
			}
			if (argc > (1 + begin_inclusive)) // Slot name and target provided
			{
				if (IsNumber(argv[(0 + begin_inclusive)])) // Make sure the first argument is a string, not a number
					return 0;
				ao::identity_t inv_slot_identity;
				const auto valid_slot = ao::inventory_holder::get_inv_slot_identity(argv[(0 + begin_inclusive)], inv_slot_identity);
				if (!valid_slot)
					return 0;
				if(IsNumber(argv[(1 + begin_inclusive)])) // Second argument is an identity
				{
					ao::identity_t previous_target;
					const auto target_id = atoui64(argv[(1 + begin_inclusive)]);
					const auto target_identity = ao::identity_t::get_identity_from_combined(target_id);
					const auto p_dynel = ao::dynel::get_dynel(target_identity);
					if(p_dynel)
					{
						if(!P_SELECTION_INDICATOR) // No Current Target
						{
							P_TARGETING_MODULE->set_target(target_identity, false);
							P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
							P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity);
							return 1;
						}
						if(P_SELECTION_INDICATOR->identity == target_identity)// Current Target Is Desired Target
						{
							P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
							return 1;
						}
						// Current Target Is NOT Desired Target
						P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity); // Saves the current target to pLastTarget
						P_TARGETING_MODULE->set_target(target_identity, false);
						P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
						P_TARGETING_MODULE->set_target(*P_LAST_TARGET, false); // Switches the target back to the previous target
						return 1;
					}
					return 0;
				}
				char second_arg[MAX_VARSTRING]; // Second argument is a string
				strcpy_s(second_arg, sizeof(second_arg), argv[(1 + begin_inclusive)]);
				_strlwr_s(second_arg);
				if(!strcmp(second_arg, "me")) // Check to see it the target is "me"
				{
					if(!P_SELECTION_INDICATOR) // No current target
					{
						P_TARGETING_MODULE->set_target(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_identity(), false);
						P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
						P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity);
						return 1;
					}
					if(P_SELECTION_INDICATOR->identity == P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_identity()) // Current target is desired target
					{
						P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
						return 1;
					}
					// Current target is NOT the desired target
					P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity);
					P_TARGETING_MODULE->set_target(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_identity(), false);
					P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
					P_TARGETING_MODULE->set_target(*P_LAST_TARGET, false);
					return 1;
				}
				ao::identity_t target_identity; // Find the actor identity that matches the name provided
				const string name(argv[(1 + begin_inclusive)]);
				const auto valid_target = P_ENGINE_CLIENT_ANARCHY->n3_msg_name_to_id(name, target_identity);
				if (valid_target)
				{
					if (!P_SELECTION_INDICATOR) // No Current Target
					{
						P_TARGETING_MODULE->set_target(target_identity, false);
						P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
						P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity);
						return 1;
					}
					if (P_SELECTION_INDICATOR->identity == target_identity)// Current Target Is Desired Target
					{
						P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
						return 1;
					}
					// Current Target Is NOT Desired Target
					P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity); // Saves the current target to pLastTarget
					P_TARGETING_MODULE->set_target(target_identity, false);
					P_ENGINE_CLIENT_ANARCHY->n3_msg_use_item(inv_slot_identity, false);
					P_TARGETING_MODULE->set_target(*P_LAST_TARGET, false); // Switches the target back to the previous target
					return 1;
				}
				return 0;
			}
			return 0;		
		}

		DWORD AOEcho(int argc, char *argv[])
		{
			if (argc > 1)
			{
				bool chat_type_used = false;
				char chat_color_name[MAX_VARSTRING] = "ct_system";
				char chat_type[MAX_VARSTRING];
				char first_arg[MAX_VARSTRING];
				if (argv[1][0] == '-' && argc > 2) // check for chat config type
				{
					strcpy_s(first_arg, MAX_VARSTRING, argv[1]);
					_strlwr_s(first_arg);
					// ReSharper disable StringLiteralTypo
					if (!strcmp(first_arg, "-chattype"))
					{
						strcpy_s(chat_type, MAX_VARSTRING, argv[2]);
						_strlwr_s(chat_type);
						if (!strcmp(chat_type, "black"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "black");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "green"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "green");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "silver"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "silver");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "lime"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "lime");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "gray"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "gray");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "olive"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "olive");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "white"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "white");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "yellow"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "yellow");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "maroon"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "maroon");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "navy"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "navy");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "red"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "red");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "blue"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "blue");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "purple"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "purple");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "teal"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "teal");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "fuchsia"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "fuchsia");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "aqua"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "aqua");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "error"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ct_error");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "system"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ct_system");
							chat_type_used = true;
						}

						else if (!strcmp(chat_type, "cmdfeedback"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ct_cmd_feedback");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "otell"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ct_otell");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "itell"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ct_itell");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "admin"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_admin");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "clan"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_clan");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "emote"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_emote");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "gm"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_gm");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "misc"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_misc");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "newbie"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_newbie");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "news"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_news");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "pgroup"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_pgroup");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "seekingteam"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_seekingteam");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "shout"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_shout");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "team"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_team");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "raid"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_raid");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "tell"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_tell");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "vicinity"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_vicinity");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "whisper"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_whisper");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "tower"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_tower");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "mypet"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_mypet");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "otherpet"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_otherpet");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "research"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "ctch_research");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "none"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNoneColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "comm"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCCommColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "mehitbynano"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCMeHitByNanoColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "otherhitbynano"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCOtherHitByNanoColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "monsterhitme"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCMonsterHitMeColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "playerhitme"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCPlayerHitMeColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "mehitother"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCMeHitOtherColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "otherhitothermypet"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCOtherHitOtherMyPetColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "mehealed"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCMeHealedColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "megotxp"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCMeGotXpColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "mecastnano"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCMeCastNano");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "skill"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCSkillColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "showfullname"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCShowFullNameColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "link"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCLinkColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "tooltip"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCToolTipColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "cash"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCCashColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "infoheadline"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCInfoHeadline");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "infoheader"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCInfoHeader");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "infotext"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCInfoText");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "infotextbold"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCInfoTextBold");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "text"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCCCTextColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "header"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCCCHeaderColor");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "npcchat"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNPCChatText");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "npcooc"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNPCOOCText");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "npcemote"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNPCChatEmote");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "npcsystem"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNPCChatSystem");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "npcquestion"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNPCChatQuestion");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "npcdescription"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNPCChatDescription");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "npctrade"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCNPCChatTrade");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "itemunknown"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCItemUnknown");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "itemtrash"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCItemTrash");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "itemnormal"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCItemNormal");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "itemexotic"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCItemExotic");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "itemquest"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCItemQuest");
							chat_type_used = true;
						}
						else if (!strcmp(chat_type, "itemsocial"))
						{
							strcpy_s(chat_color_name, MAX_VARSTRING, "CCItemSocial");
							chat_type_used = true;
						}
						// ReSharper restore StringLiteralTypo
					}
				}
				string s;
				int i;
				if (chat_type_used)
					i = 3;
				else
					i = 1;
				// ReSharper disable once CppExpressionWithoutSideEffects
				for (i ; i < argc; i++)
				{
					if (i == argc - 1)
					{
						s += string(argv[i]);
					}
					else
					{
						s += string(argv[i]) + ' ';
					}
				}
				auto ao_message = "<font color=\"" + string(chat_color_name) + "\">" + s + "</font>";
				P_COMMAND_INTERPRETER->parse_text(ao_message);
				return 1;
			}
			return 0;
		}

		DWORD AOExecute(int argc, char *argv[])
		{
			if (argc > 1)
			{
				if (argv[1][0] != '/')
					return 0;
				string s;
				// Build the command string from argv
				for (auto i = 1; i < argc; i++)
				{
					// Check to see it is the last element. If it is, do not include a space at the end.
					if (i == argc - 1)
						s += string(argv[i]);
					else
						s += string(argv[i]) + ' ';
				}
				P_COMMAND_INTERPRETER->parse_text(s);
				return 1;
			}
			return 0;
		}

		DWORD Attack(int begin_inclusive, int argc, char *argv[])
		{
			if(argc >= (1 + begin_inclusive))
			{
				if(argc == (1 + begin_inclusive)) // exactly 1 argument provided
				{
					if (IsNumber(argv[0 + begin_inclusive]))
						return 0;
					char first_arg[MAX_VARSTRING];
					strcpy_s(first_arg, sizeof(first_arg), argv[0 + begin_inclusive]);
					_strlwr_s(first_arg);
					if(!strcmp(first_arg, "off"))
					{
						if(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_weapon_holder()->is_attacking())
							P_ENGINE_CLIENT_ANARCHY->n3_msg_stop_attack();
						return 1;
					}
					if(!strcmp(first_arg, "on"))
					{
						if (!P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_weapon_holder()->is_attacking() && P_SELECTION_INDICATOR) // not already attacking something and has a selection target
							P_ENGINE_CLIENT_ANARCHY->n3_msg_default_attack(P_SELECTION_INDICATOR->identity, true);
						return 1;
					}
					return 0;
				}
				if(argc > (1 + begin_inclusive))
				{
				
				}
			}
			return 0;
		}

		DWORD Cast(int begin_inclusive, int argc, char *argv[])
		{
			if(argc >= (1 + begin_inclusive))
			{
				if(argc == (1 + begin_inclusive) && IsNumber(argv[(0 + begin_inclusive)]))
				{
					const auto nano_id = atoi(argv[(0 + begin_inclusive)]);  // NOLINT(cert-err34-c)
					const ao::identity_t i(53019, nano_id);
					const ao::identity_t d(0, 0);
					ao::nano_item* p_nano_spell;
					if ((p_nano_spell = reinterpret_cast<ao::nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d))))
					{
						p_nano_spell->cast();
						return 1;
					}
					return 0;					
				}
				if (argc == (1 + begin_inclusive) && !IsNumber(argv[(0 + begin_inclusive)]))
				{
					char name[MAX_VARSTRING];
					char search_name[MAX_VARSTRING];
					strcpy_s(search_name, sizeof(search_name), argv[(0 + begin_inclusive)]);
					_strlwr_s(search_name);
					std::vector<DWORD> v;
					if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_spell_template_data()->get_nano_spell_list(v))
					{
						for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
						{
							const ao::identity_t i(53019, *it);
							const ao::identity_t d(0, 0);
							auto p_nano_spell = reinterpret_cast<ao::nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
							strcpy_s(name, sizeof(name), p_nano_spell->get_name());
							_strlwr_s(name);
							if (strstr(name, search_name))
							{
								p_nano_spell->cast();
								return 1;
							}
						}
					}				
					return 0;
				}
				if(argc >= (2 + begin_inclusive) && IsNumber(argv[(0 + begin_inclusive)]) && IsNumber(argv[(1 + begin_inclusive)])) // nano_id, target_id
				{
					const DWORD nano_id = atoi(argv[(0 + begin_inclusive)]);  // NOLINT(cert-err34-c)
					const ao::identity_t i(53019, nano_id);
					const ao::identity_t d(0, 0);
					const auto target_id = atoui64(argv[(1 + begin_inclusive)]);
					const auto t = ao::identity_t::get_identity_from_combined(target_id);
					const auto p_nano_item = reinterpret_cast<ao::nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
					const auto p_target = ao::dynel::get_dynel(t);
					if(p_nano_item && p_target)
					{
						P_ENGINE_CLIENT_ANARCHY->n3_msg_cast_nano_spell(i, t);
						return 1;
					}
					return 0;
				}
				if(argc >= (2 + begin_inclusive) && IsNumber(argv[(0 + begin_inclusive)]) && !IsNumber(argv[(1 + begin_inclusive)])) // nano_id, target_name
				{
					const DWORD nano_id = atoi(argv[(0 + begin_inclusive)]);  // NOLINT(cert-err34-c)
					const ao::identity_t i(53019, nano_id);
					const ao::identity_t d(0, 0);
					const auto p_nano_item = reinterpret_cast<ao::nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
					auto valid_target = false;
					char second_arg[MAX_VARSTRING];
					strcpy_s(second_arg, sizeof(second_arg), argv[(1 + begin_inclusive)]);
					_strlwr_s(second_arg);
					ao::identity_t t;
					if (!strcmp(second_arg, "me"))
					{
						P_ENGINE_CLIENT_ANARCHY->get_client_dynel_id(t);
						valid_target = true;
					}
					else
					{
						const std::string name(argv[(1 + begin_inclusive)]);
						valid_target = P_ENGINE_CLIENT_ANARCHY->n3_msg_name_to_id(name, t);
					}
					if (p_nano_item && valid_target)
					{
						P_ENGINE_CLIENT_ANARCHY->n3_msg_cast_nano_spell(i, t);
						return 1;
					}
					return 0;
				}
				if (argc >= (2 + begin_inclusive) && !IsNumber(argv[(0 + begin_inclusive)]) && IsNumber(argv[(1 + begin_inclusive)])) // nano_name, target_id
				{
					ao::identity_t i(53019, 0);
					const ao::identity_t d(0, 0);
					char name[MAX_VARSTRING];
					char search_name[MAX_VARSTRING];
					strcpy_s(search_name, sizeof(search_name), argv[(0 + begin_inclusive)]);
					_strlwr_s(search_name);
					std::vector<DWORD> v;
					if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_spell_template_data()->get_nano_spell_list(v))
					{
						for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
						{
							i.id = *it;
							auto p_nano_spell = reinterpret_cast<ao::nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
							strcpy_s(name, sizeof(name), p_nano_spell->get_name());
							_strlwr_s(name);
							if (strstr(name, search_name))
							{
								i = p_nano_spell->get_nano_identity();
								break;
							}
						}
					}				
					if (i.id == 0)
						return 0;
					const auto target_id = atoui64(argv[(1 + begin_inclusive)]);
					const auto t = ao::identity_t::get_identity_from_combined(target_id);
					const auto p_target = ao::dynel::get_dynel(t);
					if (!p_target)
						return 0;
					P_ENGINE_CLIENT_ANARCHY->n3_msg_cast_nano_spell(i, t);
					return 1;
				}
				if (argc >= (2 + begin_inclusive) && !IsNumber(argv[(0 + begin_inclusive)]) && !IsNumber(argv[(1 + begin_inclusive)])) // nano_name, target_name
				{
					ao::identity_t i(53019, 0);
					const ao::identity_t d(0, 0);
					char name[MAX_VARSTRING];
					char search_name[MAX_VARSTRING];
					strcpy_s(search_name, sizeof(search_name), argv[(0 + begin_inclusive)]);
					_strlwr_s(search_name);
					std::vector<DWORD> v;
					if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_spell_template_data()->get_nano_spell_list(v))
					{
						for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
						{
							i.id = *it;
							auto p_nano_spell = reinterpret_cast<ao::nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
							strcpy_s(name, sizeof(name), p_nano_spell->get_name());
							_strlwr_s(name);
							if (strstr(name, search_name))
							{
								i = p_nano_spell->get_nano_identity();
								break;
							}
						}
					}				
					if (i.id == 0)
						return 0;
					auto valid_target = false;
					char second_arg[MAX_VARSTRING];
					strcpy_s(second_arg, sizeof(second_arg), argv[(1 + begin_inclusive)]);
					_strlwr_s(second_arg);
					ao::identity_t t(0, 0);
					if (!strcmp(second_arg, "me"))
					{
						P_ENGINE_CLIENT_ANARCHY->get_client_dynel_id(t);
						valid_target = true;
					}
					else
					{
						const std::string target_name(argv[(0 + begin_inclusive)]);
						valid_target = P_ENGINE_CLIENT_ANARCHY->n3_msg_name_to_id(target_name, t);
					}
					if (valid_target)
					{
						P_ENGINE_CLIENT_ANARCHY->n3_msg_cast_nano_spell(i, t);
						return 1;
					}
					return 0;
				}
			}
			return 0;
		}

		DWORD DoAction(int argc, char* argv[])
		{
			if(argc >= 2)
			{
				if (argc == 2) // Only one argument provided
				{
					if(IsNumber(argv[1])) // ActionId 
					{
						ao::identity_t action_identity;
						action_identity.type = 57008;
						action_identity.id = atoi(argv[1]);  // NOLINT(cert-err34-c)
						P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action(action_identity);
						return 1;
					}
					char name[MAX_VARSTRING]; // ActionName
					char search_name[MAX_VARSTRING];
					strcpy_s(search_name, sizeof(search_name), argv[1]);
					_strlwr_s(search_name);
					std::vector<ao::special_action_template*> v;
					if(P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_special_action_holder()->get_special_actions(v))
					{
						const ao::identity_t dummy_identity;
						for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
						{
							const auto action_name = P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name((*it)->get_identity(), dummy_identity);
							strcpy_s(name, sizeof(name), action_name);
							_strlwr_s(name);
							if (strstr(name, search_name))
							{
								P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action((*it)->get_identity());
								return 1;
							}
						}
					}				
					return 0;
				}
				if (argc > 2) // At least two arguments provided
				{
					if(IsNumber(argv[1]) && IsNumber(argv[2])) // ActionId, TargetId
					{
						ao::identity_t action_identity;
						action_identity.type = 57008;
						action_identity.id = atoi(argv[1]);  // NOLINT(cert-err34-c)
						const auto comb_target_identity = atoui64(argv[2]);
						const auto target_identity = ao::identity_t::get_identity_from_combined(comb_target_identity);
						const auto p_dynel = ao::dynel::get_dynel(target_identity);
						if(p_dynel)
						{
							const auto has_current_target = P_SELECTION_INDICATOR != nullptr;
							const auto current_target_is_desired_target = (P_SELECTION_INDICATOR != nullptr) && (P_SELECTION_INDICATOR->identity == target_identity);
							if(!current_target_is_desired_target)
							{
								if(has_current_target)
									P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity); // Stores the old target's identity in pLastTarget
								P_TARGETING_MODULE->set_target(target_identity, false);
							}
							P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action(action_identity);
							if(!current_target_is_desired_target)
							{
								if (has_current_target)
									P_TARGETING_MODULE->set_target(*P_LAST_TARGET, false);
							}
							return 1;
						}
						return 0;
					}
					if(IsNumber(argv[1]) && !IsNumber(argv[2])) // ActionId, TargetName
					{
						ao::identity_t action_identity;
						action_identity.type = 57008;
						action_identity.id = atoi(argv[1]);  // NOLINT(cert-err34-c)
						ao::identity_t target_identity;
						const string target_name(argv[2]);
						const auto valid_target = P_ENGINE_CLIENT_ANARCHY->n3_msg_name_to_id(target_name, target_identity);
						if(valid_target)
						{
							const auto has_current_target = P_SELECTION_INDICATOR != nullptr;
							const auto current_target_is_desired_target = (P_SELECTION_INDICATOR != nullptr) && (P_SELECTION_INDICATOR->identity == target_identity);
							if (!current_target_is_desired_target)
							{
								if (has_current_target)
									P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity); // Stores the old target's identity in pLastTarget
								P_TARGETING_MODULE->set_target(target_identity, false);
							}
							P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action(action_identity);
							if (!current_target_is_desired_target)
							{
								if (has_current_target)
									P_TARGETING_MODULE->set_target(*P_LAST_TARGET, false);
							}
							return 1;
						}
						return 0;
					}
					if(!IsNumber(argv[1]) && IsNumber(argv[2])) // ActionName, TargetId
					{
						char name[MAX_VARSTRING]; // ActionName
						char search_name[MAX_VARSTRING];
						strcpy_s(search_name, sizeof(search_name), argv[1]);
						_strlwr_s(search_name);
						std::vector<ao::special_action_template*> v;
						if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_special_action_holder()->get_special_actions(v))
						{
							const ao::identity_t dummy_identity;
							ao::identity_t action_identity;
							auto valid_action = false;
							for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
							{
								const auto action_name = P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name((*it)->get_identity(), dummy_identity);
								strcpy_s(name, sizeof(name), action_name);
								_strlwr_s(name);
								if (strstr(name, search_name))
								{
									action_identity = (*it)->get_identity();
									valid_action = true;
									break;
								}
							}
							const auto comb_target_identity = atoui64(argv[2]);
							const auto target_identity = ao::identity_t::get_identity_from_combined(comb_target_identity);
							const auto p_dynel = ao::dynel::get_dynel(target_identity);
							if (valid_action && p_dynel)
							{
								const auto has_current_target = P_SELECTION_INDICATOR != nullptr;
								const auto current_target_is_desired_target = (P_SELECTION_INDICATOR != nullptr) && (P_SELECTION_INDICATOR->identity == target_identity);
								if (!current_target_is_desired_target)
								{
									if (has_current_target)
										P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity); // Stores the old target's identity in pLastTarget
									P_TARGETING_MODULE->set_target(target_identity, false);
								}
								P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action(action_identity);
								if (!current_target_is_desired_target)
								{
									if (has_current_target)
										P_TARGETING_MODULE->set_target(*P_LAST_TARGET, false);
								}
								return 1;
							}
						}					
						return 0;
					}
					if (!IsNumber(argv[1]) && !IsNumber(argv[2])) // ActionName, TargetName
					{
						char name[MAX_VARSTRING]; // ActionName
						char search_name[MAX_VARSTRING];
						strcpy_s(search_name, sizeof(search_name), argv[1]);
						_strlwr_s(search_name);
						std::vector<ao::special_action_template*> v;
						if (P_ENGINE_CLIENT_ANARCHY->get_client_char()->get_special_action_holder()->get_special_actions(v))
						{
							const ao::identity_t dummy_identity;
							ao::identity_t action_identity;
							auto valid_action = false;
							for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
							{
								const auto action_name = P_ENGINE_CLIENT_ANARCHY->n3_msg_get_name((*it)->get_identity(), dummy_identity);
								strcpy_s(name, sizeof(name), action_name);
								_strlwr_s(name);
								if (strstr(name, search_name))
								{
									action_identity = (*it)->get_identity();
									valid_action = true;
									break;
								}
							}
							ao::identity_t target_identity;
							const string target_name(argv[2]);
							const auto valid_target = P_ENGINE_CLIENT_ANARCHY->n3_msg_name_to_id(target_name, target_identity);
							if (valid_action && valid_target)
							{
								const auto has_current_target = P_SELECTION_INDICATOR != nullptr;
								const auto current_target_is_desired_target = (P_SELECTION_INDICATOR != nullptr) && (P_SELECTION_INDICATOR->identity == target_identity);
								if (!current_target_is_desired_target)
								{
									if (has_current_target)
										P_TARGETING_MODULE->remove_target(P_SELECTION_INDICATOR->identity); // Stores the old target's identity in pLastTarget
									P_TARGETING_MODULE->set_target(target_identity, false);
								}
								P_ENGINE_CLIENT_ANARCHY->n3_msg_perform_special_action(action_identity);
								if (!current_target_is_desired_target)
								{
									if (has_current_target)
										P_TARGETING_MODULE->set_target(*P_LAST_TARGET, false);
								}
								return 1;
							}					
						}
						return 0;
					}
				}
				return 0;
			}
			return 0;
		}

		DWORD Face(int argc, char *argv[])
		{
			if (argc > 1)
			{
				if (argc == 2 && !IsNumber(argv[1])) // Check to see if a name was provided
				{
					char search_name[MAX_VARSTRING];
					strcpy_s(search_name, MAX_VARSTRING, argv[1]);
					_strlwr_s(search_name);
					std::vector<ao::actor*> v;
					P_PLAYFIELD_DIR->get_playfield()->get_playfield_actors(v);
					for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
					{
						char name[MAX_VARSTRING];
						strcpy_s(name, MAX_VARSTRING, (*it)->get_name());
						_strlwr_s(name);
						if (strstr(name, search_name))
						{
							(*it)->do_face();
							return 1;
						}
					}
					return 0;
				}
				if (argc == 2 && IsNumber(argv[1])) // Check to see if a heading was provided
				{
					auto heading = float(atof(argv[1]));  // NOLINT(cert-err34-c)
					if (heading < 0.0f || heading > 360.0f)
						return 0;
					if (heading > 180.0f)
						heading -= 360.0f;
					heading = float(heading * 2 * M_PI / 360.0f);
					P_ENGINE_CLIENT_ANARCHY->get_client_char()->face(heading);
					return 1;
				}
				if (argc == 3 && IsNumber(argv[1]) && IsNumber(argv[2])) // Check to see if X and Z coords provided
				{
					ao::vector3_t v;
					v.x = float(atof(argv[1]));  // NOLINT(cert-err34-c)
					v.y = 0.0f;
					v.z = float(atof(argv[2]));  // NOLINT(cert-err34-c)
					P_ENGINE_CLIENT_ANARCHY->get_client_char()->face(v);
					return 1;
				}
				if (argc == 4 && IsNumber(argv[1]) && IsNumber(argv[2]) && IsNumber(argv[3]))
				{
					ao::vector3_t v;
					v.x = float(atof(argv[1]));  // NOLINT(cert-err34-c)
					v.y = 0.0f;
					v.z = float(atof(argv[3]));  // NOLINT(cert-err34-c)
					P_ENGINE_CLIENT_ANARCHY->get_client_char()->face(v);
					return 1;
				}
				return 0;
			}
			// If no arguments are provided, we should try to face our current target
			if (P_SELECTION_INDICATOR)
			{
				reinterpret_cast<ao::actor*>(ao::dynel::get_dynel(P_SELECTION_INDICATOR->identity))->do_face();
				return 1;
			}
			return 0;
		}

		DWORD Target(int argc, char *argv[])
		{
			if (argc < 2)
				return 0;
			if (IsNumber(argv[1]))	// Check to see if an Id was provided
			{
				const auto combined_identity = atoui64(argv[1]);
				const auto id = ao::identity_t::get_identity_from_combined(combined_identity);
				const auto p_dynel = ao::dynel::get_dynel(id);
				if (p_dynel)
				{
					P_TARGETING_MODULE->set_target(id, false);
					return 1;
				}
				return 0;
			}
			char arg[MAX_VARSTRING];
			strcpy_s(arg, MAX_VARSTRING, argv[1]);
			_strlwr_s(arg);		
			if (!strcmp(arg, "me")) // Check for me
			{
				P_TARGETING_MODULE->select_self();
				return 1;
			}
			std::vector<ao::actor*> v;
			P_PLAYFIELD_DIR->get_playfield()->get_playfield_actors(v);
			if (!strcmp(arg, "pc")) // Check for nearest pc
			{  
				for (auto it = v.begin(); it != v.end(); ++it)	// NOLINT(modernize-loop-convert)
				{
					if ((*it)->is_player() && !is_client_id((*it)->get_identity().id))
					{
						P_TARGETING_MODULE->set_target((*it)->get_identity(), false);
						return 1;
					}
				}
			}
			if (!strcmp(arg, "npc")) // check for nearest npc
			{
				for (auto it = v.begin(); it != v.end(); ++it)	// NOLINT(modernize-loop-convert)
				{
					if ((*it)->is_npc() && !(*it)->is_pet())
					{
						P_TARGETING_MODULE->set_target((*it)->get_identity(), false);
						return 1;
					}
				}
			}
			if (!strcmp(arg, "pet")) // check for nearest pet
			{
				for (auto it = v.begin(); it != v.end(); ++it)	// NOLINT(modernize-loop-convert)
				{
					if ((*it)->is_pet())
					{
						P_TARGETING_MODULE->set_target((*it)->get_identity(), false);
						return 1;
					}
				}
			}
			for (auto it = v.begin(); it != v.end(); ++it) // Assume it is a name	// NOLINT(modernize-loop-convert)
			{
				char name[MAX_VARSTRING];
				strcpy_s(name, MAX_VARSTRING, (*it)->get_name());
				_strlwr_s(name);
				if (strstr(name, arg))
				{
					P_TARGETING_MODULE->set_target((*it)->get_identity(), false);
					return 1;
				}
			}
			return 0;
		}
	}
}