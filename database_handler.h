#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class database_handler
{
public:
	ao::resource_database* get_resource_database() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	ao::n3_database_handler_t n3_database_handler_;
};