#pragma once

class SpellTemplateData
{
public:
	AOLIB_OBJECT DWORD BuildLSNanoSpellList(LSIndex*) const;
	AOLIB_OBJECT DWORD GetActiveNanoEffects(std::vector<identity_t>&) const;
	AOLIB_OBJECT CastingData* GetCastingData() const;
	AOLIB_OBJECT DWORD GetNanoBeingCast() const;
	AOLIB_OBJECT DWORD GetNanoSpellList(std::vector<DWORD>&) const;
	AOLIB_OBJECT DWORD GetNanoTemplateList(std::vector<NanoTemplate>&) const;
	AOLIB_OBJECT spell_template_data_t GetSpellTemplateDataData() const;
	AOLIB_OBJECT bool IsCasting() const;
private:
	spell_template_data_t spell_template_data_;
};