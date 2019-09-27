#include "isxao_main.h"

namespace ao
{

	bool inventory_item::can_apply_on_fighting_target()
	{
		return (get_can_flags() & ICF_APPLY_ON_FIGHTING_TARGET) == 1;
	}

	bool inventory_item::can_apply_on_friendly()
	{
		return (get_can_flags() & ICF_APPLY_ON_FRIENDLY) == 1;
	}

	bool inventory_item::can_apply_on_hostile()
	{
		return (get_can_flags() & ICF_APPLY_ON_HOSTILE) == 1;
	}

	bool inventory_item::can_apply_on_self()
	{
		return (get_can_flags() & ICF_APPLY_ON_SELF) == 1;
	}

	bool inventory_item::can_be_split()
	{
		return (get_can_flags() & ICF_CANT_SPLIT) == 0;
	}

	bool inventory_item::can_use()
	{
		return (get_can_flags() & ICF_USE) == 1;
	}

	DWORD inventory_item::get_can_flags()
	{
		return get_skill(ST_CAN);
	}

	DWORD inventory_item::get_mass()
	{
		return get_skill(ST_VOLUMEMASS);
	}

	DWORD inventory_item::get_none_flags()
	{
		return get_skill(ST_FLAGS);
	}

	DWORD inventory_item::get_ql()
	{
		return get_skill(ST_LEVEL);
	}

	PCSTR inventory_item::get_rarity()
	{
		return ao::engine_client_anarchy::get_item_rarity_str(get_skill(ST_RARITY));
	}

	DWORD inventory_item::get_value()
	{
		return get_skill(ST_PRICE);
	}

	LONG inventory_item::get_skill(DWORD stat)
	{
		identity_t dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		auto result = 1234567890;
		if (P_ENGINE_CLIENT_ANARCHY)
			result = P_ENGINE_CLIENT_ANARCHY->n3_msg_get_skill(get_identity(), stat, 2, dummy_identity);
		return result;
	}

	bool inventory_item::is_armor()
	{
		return get_skill(ST_ITEMCLASS) == IT_ARMOR;
	}

	bool inventory_item::is_consumable()
	{
		return (get_can_flags() & ICF_CONSUME) == 1;
	}

	bool inventory_item::is_implant()
	{
		return get_skill(ST_ITEMCLASS) == IT_IMPLANT;
	}

	bool inventory_item::is_misc()
	{
		return get_skill(ST_ITEMCLASS) == IT_MISC;
	}

	bool inventory_item::is_npc()
	{
		return get_skill(ST_ITEMCLASS) == IT_NPC;
	}

	bool inventory_item::is_spirit()
	{
		return get_skill(ST_ITEMCLASS) == IT_SPIRIT;
	}

	bool inventory_item::is_stackable()
	{
		return (get_can_flags() & ICF_STACKABLE) == 1;
	}

	bool inventory_item::is_tower()
	{
		return get_skill(ST_ITEMCLASS) == IT_TOWER;
	}

	bool inventory_item::is_utility()
	{
		return get_skill(ST_ITEMCLASS) == IT_UTILITY;
	}

	bool inventory_item::is_weapon()
	{
		return get_skill(ST_ITEMCLASS) == IT_WEAPON;
	}

	bool inventory_item::must_sit_to_use()
	{
		return (get_can_flags() & ICF_SIT) == 1;
	}

}