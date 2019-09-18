#pragma once

class inventory_item : public ao::dummy_item_base
{
public:
	bool can_apply_on_fighting_target();
	bool can_apply_on_friendly();
	bool can_apply_on_hostile();
	bool can_apply_on_self();
	bool can_be_split();
	bool can_use();
	DWORD get_can_flags();
	DWORD get_mass();
	DWORD get_none_flags();
	DWORD get_ql();
	PCSTR get_rarity();
	LONG get_skill(DWORD);
	DWORD get_value();
	bool is_armor();
	bool is_consumable();
	bool is_implant();
	bool is_misc();
	bool is_npc();
	bool is_spirit();
	bool is_stackable();
	bool is_tower();
	bool is_weapon();
	bool is_utility();
	bool must_sit_to_use();
};