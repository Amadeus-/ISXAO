#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class team_entry
{
public:
	PCSTR get_name() const;
	ao::identity_t get_identity() const;
	ao::team_entry_t get_team_entry_data() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::team_entry_t team_entry_;
};
