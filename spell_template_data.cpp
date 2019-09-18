#include "isxao_main.h"

namespace ao
{

	DWORD spell_template_data::build_ls_nano_spell_list(LSIndex* p_index) const
	{
		std::vector<DWORD> v;
		this->get_nano_spell_list(v);
		for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			const identity_t i(53019, (*it));
			identity_t d(0, 0);
			auto item = reinterpret_cast<nano_item*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
			if (item)
				p_index->AddItem(reinterpret_cast<LSOBJECTDATA&>(item));
		}
		return p_index->GetContainerUsed();
	}

	DWORD spell_template_data::get_active_nano_effects(std::vector<identity_t> &v) const
	{
		auto nano_identity_vector = this->get_spell_template_data_data().active_nanos;
		for (auto it = nano_identity_vector.begin(); it != nano_identity_vector.end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(*(*it));
		std::sort(v.begin(), v.end(), less<>());
		return v.size();
	}

	casting_data* spell_template_data::get_casting_data() const
	{
		auto casting_data_list = this->get_spell_template_data_data().p_spellcasting_info;
		if (this->is_casting())
		{			
			return reinterpret_cast<casting_data*>(*casting_data_list->begin());
		}
		return nullptr;
	}

	DWORD spell_template_data::get_nano_being_cast() const
	{
		auto result = 0;
		if (this->is_casting())
			result = this->get_casting_data()->get_nano_id();
		return result;
	}

	DWORD spell_template_data::get_nano_spell_list(std::vector<DWORD> &v) const
	{
		// this->get_spell_template_data_data().spell_list.copy_list(v);
		auto nano_list = this->get_spell_template_data_data().spell_list;
		for (auto it = nano_list.begin(); it != nano_list.end(); ++it)  // NOLINT(modernize-loop-convert)
			v.push_back(*it);
		std::sort(v.begin(), v.end(), less<>());
		return v.size();
	}

	DWORD spell_template_data::get_nano_template_list(std::vector<nano_template> &v) const
	{
		auto l = this->get_spell_template_data_data().nano_template_list;
		for (auto it = l.begin(); it != l.end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			auto t = *it;
			v.push_back(*reinterpret_cast<nano_template*>(&t));
		}
		std::sort(v.begin(), v.end(), nano_template::nano_template_compare);
		return v.size();
	}

	spell_template_data_t spell_template_data::get_spell_template_data_data() const
	{
		return spell_template_data_;
	}

	bool spell_template_data::is_casting() const
	{
		return !get_spell_template_data_data().p_spellcasting_info->empty();
	}

}