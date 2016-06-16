#pragma once

class DummyItemBase
{
public:
	AOLIB_OBJECT PVOID GetData();
	AOLIB_OBJECT PDUMMYITEMBASE GetDummyItemBaseData();
	AOLIB_OBJECT PCSTR GetDescription();
	AOLIB_OBJECT IDENTITY GetIdentity();
	AOLIB_OBJECT PCSTR GetName();
	AOLIB_OBJECT IDENTITY GetParentIdentity();
private:
	DUMMYITEMBASE dummy_item_base_;
};