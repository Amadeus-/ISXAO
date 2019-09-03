#pragma once

class DummyItemBase
{
public:
	AOLIB_OBJECT PVOID GetData();
	AOLIB_OBJECT p_dummy_item_base_t GetDummyItemBaseData();
	AOLIB_OBJECT PCSTR GetDescription();
	AOLIB_OBJECT identity_t GetIdentity();
	AOLIB_OBJECT PCSTR GetName();
	AOLIB_OBJECT identity_t GetParentIdentity();
private:
	dummy_item_base_t dummy_item_base_;
};