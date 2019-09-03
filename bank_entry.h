#pragma once

class BankEntry
{
public:
	AOLIB_OBJECT bank_entry_t GetBankEntryData() const;
	AOLIB_OBJECT DWORD GetInventory(std::vector<InventoryData*> &v) const;
	AOLIB_OBJECT identity_t GetInventoryIdentity() const;
	AOLIB_OBJECT DWORD GetInventorySize() const;
private:
	bank_entry_t bank_entry_;
};