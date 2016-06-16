#pragma once

class ResourceDatabase
{
public:
	PDBOBJECT GetDbObject(const IDENTITY&);
	void GetIdentityVec(vector<IDENTITY>&, int);
private:
	RESOURCEDATABASE resource_database_;
};