#include "isxao_main.h"
#include "engine_client_anarchy.h"

namespace ao
{

	bool special_action_item::can_apply_on_fighting_target()
	{
		return (get_skill(ST_CAN) & ICF_APPLY_ON_FIGHTING_TARGET) == 1;
	}

	bool special_action_item::can_apply_on_friendly()
	{
		return (get_skill(ST_CAN) & ICF_APPLY_ON_FRIENDLY) == 1;
	}

	bool special_action_item::can_apply_on_hostile()
	{
		return (get_skill(ST_CAN) & ICF_APPLY_ON_HOSTILE) == 1;
	}

	bool special_action_item::can_apply_on_self()
	{
		return (get_skill(ST_CAN) & ICF_APPLY_ON_SELF) == 1;
	}

	bool special_action_item::can_use()
	{
		return (get_skill(ST_CAN) & ICF_USE) == 1;
	}

	float special_action_item::get_attack_delay()
	{
		return float(get_skill(ST_ITEMDELAY) / 100.0f);
	}

	DWORD special_action_item::get_range()
	{
		return get_skill(ST_ATTACKRANGE);
	}

	LONG special_action_item::get_skill(DWORD stat)
	{
		identity_t dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_get_skill(get_identity(), stat, 2, dummy_identity);
	}

	bool special_action_item::is_buff()
	{
		return (get_skill(ST_FLAGS) & NNF_IS_BUFF) == 1;
	}

	bool special_action_item::is_general_action()
	{
		return get_skill(ST_ACTIONCATEGORY) == 2;
	}

	bool special_action_item::is_hostile()
	{
		return (get_skill(ST_FLAGS) & NNF_IS_HOSTILE) == 1;
	}

	bool special_action_item::is_no_remove_no_ncu_is_friendly()
	{
		return (get_skill(ST_FLAGS) & NNF_NO_REMOVE_NO_NCU_IS_FRIENDLY) == 1;
	}

	bool special_action_item::is_no_resist()
	{
		return (get_skill(ST_FLAGS) & NNF_NO_RESIST) == 1;
	}

	bool special_action_item::is_no_resist_no_fumble()
	{
		return (get_skill(ST_FLAGS) & NNF_NO_RESIST_CANNOT_FUMBLE) == 1;
	}

	bool special_action_item::is_not_removable()
	{
		return (get_skill(ST_FLAGS) & NNF_NOT_REMOVABLE) == 1;
	}

	bool special_action_item::is_perk()
	{
		return get_skill(ST_ACTIONCATEGORY) == 1;
	}

	bool special_action_item::is_special_action()
	{
		return get_skill(ST_ACTIONCATEGORY) == 3;
	}

	bool special_action_item::will_break_on_attack()
	{
		return (get_skill(ST_FLAGS) & NNF_BREAK_ON_ATTACK) == 1;
	}

	bool special_action_item::will_break_on_debuff()
	{
		return (get_skill(ST_FLAGS) & NNF_BREAK_ON_DEBUFF) == 1;
	}

	bool special_action_item::will_break_on_spell_attack()
	{
		return (get_skill(ST_FLAGS) & NNF_BREAK_ON_SPELL_ATTACK) == 1;
	}


}