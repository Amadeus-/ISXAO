#pragma once

class DatabaseHandler
{
public:
	ResourceDatabase* GetResourceDatabase() const;
private:
	N3DATABASEHANDLER n3_database_handler_;
};