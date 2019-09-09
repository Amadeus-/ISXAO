#pragma once

class character : public TeamMember
{
public:
	// Holders
	AOLIB_OBJECT InventoryHolder* GetInventoryHolder();
	AOLIB_OBJECT PerkHolder* GetPerkHolder();
	AOLIB_OBJECT NpcHolder* GetNPCHolder();
	AOLIB_OBJECT SpecialActionHolder* GetSpecialActionHolder();
	AOLIB_OBJECT StatHolder* GetStatHolder();

	// Info
	AOLIB_OBJECT bool check_los(dynel*);
	AOLIB_OBJECT bool GetWeaponTarget(identity_t&);
	AOLIB_OBJECT bool GetTarget(identity_t&);
	AOLIB_OBJECT bool HasWeaponTarget();
	AOLIB_OBJECT bool HasTarget();

	// Actions
	AOLIB_OBJECT void CastNanoSpell(identity_t const &, identity_t const &) const;
	AOLIB_OBJECT void DefaultAttack(identity_t const &) const;
	AOLIB_OBJECT void Face(float heading);
	AOLIB_OBJECT void Face(vector3_t &location);
	AOLIB_OBJECT void MakeTeamLeader(const identity_t &);
	AOLIB_OBJECT bool PerformSpecialAction(const identity_t &) const;
	AOLIB_OBJECT void SetRotation(const quaternion_t&);
	AOLIB_OBJECT void StopAttack() const;
	AOLIB_OBJECT void UseItem(identity_t const &);

private:
	AOLIB_OBJECT void GetStatMap(std::map<DWORD, LONG>&);

};