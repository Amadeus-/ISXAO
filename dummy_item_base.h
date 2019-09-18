#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class dummy_item_base
{
public:
	PVOID get_data();
	ao::p_dummy_item_base_t get_dummy_item_base_data();
	PCSTR get_description();
	ao::identity_t get_identity();
	PCSTR get_name();
	ao::identity_t get_parent_identity();
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::dummy_item_base_t dummy_item_base_;
};
