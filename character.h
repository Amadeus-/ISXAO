#pragma once

class Character : public TeamMember
{
public:
	AOLIB_OBJECT DWORD BuildLSInventory(LSObjectCollection *pMap);
	AOLIB_OBJECT DWORD BuildLSInventory(LSIndex *pIndex);
	AOLIB_OBJECT void CastNanoSpell(IDENTITY const &, IDENTITY const &) const;
	AOLIB_OBJECT bool CheckLOS(Dynel*);
	AOLIB_OBJECT void DefaultAttack(IDENTITY const &) const;
	//AOLIB_OBJECT InventoryItem* GetBankInventoryItem(DWORD);
	//AOLIB_OBJECT InventoryItem* GetBankInventoryItem(PCSTR);
	//AOLIB_OBJECT DWORD GetBankInventoryCount();
	AOLIB_OBJECT std::map<IDENTITY, InventoryItem*> GetInventory();
	AOLIB_OBJECT DWORD GetInventoryCount();
	AOLIB_OBJECT InventoryHolder* GetInventoryHolder();
	AOLIB_OBJECT InventoryItem* GetInventoryItem(DWORD);
	AOLIB_OBJECT InventoryItem* GetInventoryItem(PCSTR);
	AOLIB_OBJECT INVENTORYSLOT GetInventorySlot(DWORD);
	AOLIB_OBJECT INVENTORYSLOT GetInventorySlot(PCSTR);
	AOLIB_OBJECT PerkHolder* GetPerkHolder();
	AOLIB_OBJECT void GetPerkMap(std::map<IDENTITY, DWORD>&);
	AOLIB_OBJECT void GetSpecialActions(std::vector<SpecialAction>&);
	AOLIB_OBJECT SpecialActionHolder* GetSpecialActionHolder();
	AOLIB_OBJECT StatHolder* GetStatHolder();
	AOLIB_OBJECT bool GetWeaponTarget(IDENTITY&);
	AOLIB_OBJECT bool GetTarget(IDENTITY&);
	AOLIB_OBJECT bool HasWeaponTarget();
	AOLIB_OBJECT bool HasTarget();
	AOLIB_OBJECT void MakeTeamLeader(const IDENTITY &);
	AOLIB_OBJECT bool PerformSpecialAction(const IDENTITY &) const;
	AOLIB_OBJECT void SetRotation(const QUATERNION&);
	AOLIB_OBJECT void StopAttack() const;
	AOLIB_OBJECT void UseItem(IDENTITY const &);
	AOLIB_OBJECT DWORD GetPetMap(std::map<IDENTITY, DWORD>&);
	AOLIB_OBJECT std::vector<DWORD> GetNanoSpellList();
	AOLIB_OBJECT NpcHolder* GetNPCHolder();
	AOLIB_OBJECT void Face(float heading);
	AOLIB_OBJECT void Face(VECTOR3 &location);
private:
	
	static
		AOLIB_OBJECT bool GetInvSlotIdentity(AOData::ArmorSlot_e, IDENTITY &);
	static
		AOLIB_OBJECT bool GetInvSlotIdentity(AOData::WeaponSlot_e, IDENTITY &);
	static
		AOLIB_OBJECT bool GetInvSlotIdentity(AOData::ImplantSlot_e, IDENTITY &);
	static
		AOLIB_OBJECT bool GetInvSlotIdentity(DWORD, IDENTITY &);
	AOLIB_OBJECT void GetStatMap(std::map<DWORD, LONG>&);

};