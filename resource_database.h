#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class resource_database
{
public:
	ao::p_db_object_t get_db_object(const ao::identity_t&);
	void get_identity_vec(std::vector<ao::identity_t>&, int);
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::resource_database_t resource_database_;
};
