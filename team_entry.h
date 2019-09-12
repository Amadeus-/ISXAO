#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class team_entry
{
public:
	AOLIB_OBJECT PCSTR get_name() const;
	AOLIB_OBJECT identity_t get_identity() const;
	AOLIB_OBJECT team_entry_t get_team_entry_data() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	team_entry_t team_entry_;
};
