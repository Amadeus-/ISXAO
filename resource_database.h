#pragma once

class ResourceDatabase
{
public:
	p_db_object_t GetDbObject(const identity_t&);
	void GetIdentityVec(vector<identity_t>&, int);
private:
	resource_database_t resource_database_;
};