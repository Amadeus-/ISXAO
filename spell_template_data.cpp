#include "isxao_main.h"

namespace isxao_classes
{

	DWORD SpellTemplateData::BuildLSNanoSpellList(LSIndex* pIndex) const
	{
		std::vector<DWORD> v;
		GetNanoSpellList(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			auto item = isxao_utilities::GetNanoItem((*it));
			if (item)
				pIndex->AddItem((LSOBJECTDATA&)item);
		}
		return pIndex->GetContainerUsed();
	}

	DWORD SpellTemplateData::GetActiveNanoEffects(std::vector<IDENTITY> &v) const
	{
		std::vector<PIDENTITY> nano_identity_vector = GetSpellTemplateDataData().ActiveNanos;
		for (auto it = nano_identity_vector.begin(); it != nano_identity_vector.end(); ++it)
			v.push_back(*(*it));
		std::sort(v.begin(), v.end(), less<IDENTITY>());
		return v.size();
	}

	CastingData* SpellTemplateData::GetCastingData() const
	{
		std::list<CASTINGDATA*>* casting_data_list = GetSpellTemplateDataData().pSpellcastingInfo;
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
		std::list<DWORD> nano_spell_list = GetSpellTemplateDataData().SpellList;
		for (auto it = nano_spell_list.begin(); it != nano_spell_list.end(); ++it)
			v.push_back(*it);
		std::sort(v.begin(), v.end(), less<DWORD>());
		return v.size();
	}

	DWORD SpellTemplateData::GetNanoTemplateList(std::vector<NanoTemplate> &v) const
	{
		std::list<NANOTEMPLATE> l = GetSpellTemplateDataData().NanoTemplateList;
		for (auto it = l.begin(); it != l.end(); ++it)
		{
			auto t = *it;
			v.push_back(*reinterpret_cast<NanoTemplate*>(&t));
		}
		std::sort(v.begin(), v.end(), NanoTemplate::NanoTemplateCompare);
		return v.size();
	}

	SPELLTEMPLATEDATA SpellTemplateData::GetSpellTemplateDataData() const
	{
		return spell_template_data_;
	}

	bool SpellTemplateData::IsCasting() const
	{
		return GetSpellTemplateDataData().pSpellcastingInfo->size() > 0;
	}

}