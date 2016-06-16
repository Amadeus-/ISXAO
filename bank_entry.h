#pragma once

class BankEntry
{
public:
	AOLIB_OBJECT BANKENTRY GetBankEntryData() const;
	AOLIB_OBJECT DWORD GetInventory(std::vector<InventoryData*> &v) const;
	AOLIB_OBJECT IDENTITY GetInventoryIdentity() const;
	AOLIB_OBJECT DWORD GetInventorySize() const;
private:
	BANKENTRY bank_entry_;
};