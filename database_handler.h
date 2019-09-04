#pragma once

class DatabaseHandler
{
public:
	ResourceDatabase* GetResourceDatabase() const;
private:
	n3_database_handler_t n3_database_handler_;
};