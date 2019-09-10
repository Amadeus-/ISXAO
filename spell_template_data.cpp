#include "isxao_main.h"

namespace isxao_classes
{

	DWORD SpellTemplateData::BuildLSNanoSpellList(LSIndex* pIndex) const
	{
		std::vector<DWORD> v;
		GetNanoSpellList(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			identity_t i(53019, (*it));
			identity_t d(0, 0);
			auto item = reinterpret_cast<NanoItem*>(P_ENGINE_CLIENT_ANARCHY->get_item_by_template(i, d));
			if (item)
				pIndex->AddItem((LSOBJECTDATA&)item);
		}
		return pIndex->GetContainerUsed();
	}

	DWORD SpellTemplateData::GetActiveNanoEffects(std::vector<identity_t> &v) const
	{
		std::vector<p_identity_t> nano_identity_vector = GetSpellTemplateDataData().active_nanos;
		for (auto it = nano_identity_vector.begin(); it != nano_identity_vector.end(); ++it)
			v.push_back(*(*it));
		std::sort(v.begin(), v.end(), less<identity_t>());
		return v.size();
	}

	CastingData* SpellTemplateData::GetCastingData() const
	{
		std::list<casting_data_t*>* casting_data_list = GetSpellTemplateDataData().p_spellcasting_info;
		if (IsCasting())
		{
			for (auto it = casting_data_list->begin(); it != casting_data_list->end(); ++it)
				return reinterpret_cast<CastingData*>(*it);
		}
		return nullptr;
	}

	DWORD SpellTemplateData::GetNanoBeingCast() const
	{
		auto result = 0;
		if (IsCasting())
			result = GetCastingData()->GetNanoId();
		return result;
	}

	DWORD SpellTemplateData::GetNanoSpellList(std::vector<DWORD> &v) const
	{
		std::list<DWORD> nano_spell_list = GetSpellTemplateDataData().spell_list;
		for (auto it = nano_spell_list.begin(); it != nano_spell_list.end(); ++it)
			v.push_back(*it);
		std::sort(v.begin(), v.end(), less<DWORD>());
		return v.size();
	}

	DWORD SpellTemplateData::GetNanoTemplateList(std::vector<NanoTemplate> &v) const
	{
		std::list<nano_template_t> l = GetSpellTemplateDataData().nano_template_list;
		for (auto it = l.begin(); it != l.end(); ++it)
		{
			auto t = *it;
			v.push_back(*reinterpret_cast<NanoTemplate*>(&t));
		}
		std::sort(v.begin(), v.end(), NanoTemplate::NanoTemplateCompare);
		return v.size();
	}

	spell_template_data_t SpellTemplateData::GetSpellTemplateDataData() const
	{
		return spell_template_data_;
	}

	bool SpellTemplateData::IsCasting() const
	{
		return GetSpellTemplateDataData().p_spellcasting_info->size() > 0;
	}

}