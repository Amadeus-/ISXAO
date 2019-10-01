#include "isxao_main.h"
#include "character.h"
#include "engine_client_anarchy.h"
#include "nano_item.h"

namespace ao
{
	
	bool nano_item::can_apply_on_fighting_target()
	{
		return (get_nano_can_flags() & ICF_APPLY_ON_FIGHTING_TARGET) != 0;
	}

	bool nano_item::can_apply_on_friendly()
	{
		return (get_nano_can_flags() & ICF_APPLY_ON_FRIENDLY) != 0;
	}

	bool nano_item::can_apply_on_hostile()
	{
		return (get_nano_can_flags() & ICF_APPLY_ON_HOSTILE) != 0;
	}

	bool nano_item::can_apply_on_self()
	{
		return (get_nano_can_flags() & ICF_APPLY_ON_SELF) != 0;
	}

	void nano_item::cast()
	{
		if(P_SELECTION_INDICATOR)
			P_ENGINE_CLIENT_ANARCHY->get_client_char()->cast_nano_spell(get_nano_identity(), P_SELECTION_INDICATOR->identity);
	}

	float nano_item::get_attack_delay()
	{
		return get_skill(ST_ITEMDELAY) / 100.0f;
	}

	unsigned long nano_item::get_attack_range()
	{
		return get_skill(ST_ATTACKRANGE);
	}

	float nano_item::get_cooldown_remaining()
	{
		unsigned long a;
		unsigned long b;
		auto c = P_ENGINE_CLIENT_ANARCHY->n3_msg_get_formula_progress(get_nano_identity(), a, b);
		return float((1.0 - c)*b);
	}

	double nano_item::get_formula_progress(unsigned long &a, unsigned long &b)
	{
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_get_formula_progress(get_nano_identity(), a, b);
	}

	unsigned long nano_item::get_formula_radius()
	{
		return get_nano_item_data()->radius;
	}

	unsigned long nano_item::get_nano_can_flags()
	{
		return get_skill(ST_CAN);
	}

	identity_t nano_item::get_nano_identity()
	{
		return get_nano_item_data()->nano_identity;
	}

	p_nano_item_t nano_item::get_nano_item_data()
	{
		return p_nano_item_t(get_data());
	}

	unsigned long nano_item::get_ncu_cost()
	{
		return get_skill(ST_LEVEL);
	}

	unsigned long nano_item::get_nano_none_flags()
	{
		return get_skill(ST_FLAGS);
	}

	unsigned long nano_item::get_nano_points()
	{
		return get_skill(ST_NANOPOINTS);
	}

	unsigned long nano_item::get_nano_school()
	{
		return get_skill(ST_SCHOOL);
	}

	unsigned long nano_item::get_nano_strain()
	{
		return get_skill(ST_METATYPE);
	}

	float nano_item::get_recharge_delay()
	{
		return get_skill(ST_RECHARGEDELAY) / 100.0f;
	}

	long nano_item::get_skill(unsigned long stat)
	{
		identity_t dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(identity_t));
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_get_skill(get_nano_identity(), stat, 2, dummy_identity);
	}

	unsigned long nano_item::get_stacking_order()
	{
		return get_skill(ST_STACKINGORDER);
	}

	bool nano_item::is_ready()
	{
		return P_ENGINE_CLIENT_ANARCHY->n3_msg_is_formula_ready(get_nano_identity());
	}

	bool nano_item::is_buff()
	{
		return (get_nano_none_flags() & NNF_IS_BUFF) != 0;
	}

	bool nano_item::is_hostile()
	{
		return (get_nano_none_flags() & NNF_IS_HOSTILE) != 0;
	}

	bool nano_item::is_nano_self_only()
	{
		return get_nano_item_data()->is_nano_self_only == 1;
	}

	bool nano_item::is_no_resist_cannot_fumble()
	{
		return (get_nano_none_flags() & NNF_NO_RESIST_CANNOT_FUMBLE) != 0;
	}

	bool nano_item::is_shape_change_nano()
	{
		return (get_nano_none_flags() & NNF_IS_SHAPE_CHANGE_NANO) != 0;
	}

	bool nano_item::is_team_nano()
	{
		return P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamNano(get_nano_identity());
	}

	bool nano_item::will_break_on_attack()
	{
		return (get_nano_none_flags() & NNF_BREAK_ON_ATTACK) != 0;
	}

	bool nano_item::will_break_on_debuff()
	{
		return (get_nano_none_flags() & NNF_BREAK_ON_DEBUFF) != 0;
	}

	bool nano_item::will_break_on_spell_attack()
	{
		return (get_nano_none_flags() & NNF_BREAK_ON_SPELL_ATTACK) != 0;
	}

}