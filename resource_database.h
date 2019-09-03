#pragma once

class ResourceDatabase
{
public:
	PDBOBJECT GetDbObject(const identity_t&);
	void GetIdentityVec(vector<identity_t>&, int);
private:
	RESOURCEDATABASE resource_database_;
};