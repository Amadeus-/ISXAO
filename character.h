#pragma once

class Character : public TeamMember
{
public:
	// Holders
	AOLIB_OBJECT InventoryHolder* GetInventoryHolder();
	AOLIB_OBJECT PerkHolder* GetPerkHolder();
	AOLIB_OBJECT NpcHolder* GetNPCHolder();
	AOLIB_OBJECT SpecialActionHolder* GetSpecialActionHolder();
	AOLIB_OBJECT StatHolder* GetStatHolder();

	// Info
	AOLIB_OBJECT bool CheckLOS(Dynel*);
	AOLIB_OBJECT bool GetWeaponTarget(IDENTITY&);
	AOLIB_OBJECT bool GetTarget(IDENTITY&);
	AOLIB_OBJECT bool HasWeaponTarget();
	AOLIB_OBJECT bool HasTarget();

	// Actions
	AOLIB_OBJECT void CastNanoSpell(IDENTITY const &, IDENTITY const &) const;
	AOLIB_OBJECT void DefaultAttack(IDENTITY const &) const;
	AOLIB_OBJECT void Face(float heading);
	AOLIB_OBJECT void Face(VECTOR3 &location);
	AOLIB_OBJECT void MakeTeamLeader(const IDENTITY &);
	AOLIB_OBJECT bool PerformSpecialAction(const IDENTITY &) const;
	AOLIB_OBJECT void SetRotation(const QUATERNION&);
	AOLIB_OBJECT void StopAttack() const;
	AOLIB_OBJECT void UseItem(IDENTITY const &);

private:
	AOLIB_OBJECT void GetStatMap(std::map<DWORD, LONG>&);

};