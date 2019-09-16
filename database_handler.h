#pragma once

// ReSharper disable once CppClassNeedsConstructorBecauseOfUninitializedMember
class database_handler
{
public:
	isxao_classes::resource_database* get_resource_database() const;
private:
	// ReSharper disable once CppUninitializedNonStaticDataMember
	n3_database_handler_t n3_database_handler_;
};