#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class resource_database
{
public:
	p_db_object_t get_db_object(const identity_t&);
	void get_identity_vec(std::vector<identity_t>&, int);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	resource_database_t resource_database_;
};
