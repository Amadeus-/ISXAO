#pragma once

class Actor : public Dynel
{
public:
	AOLIB_OBJECT DWORD Casting();
	AOLIB_OBJECT void DoFace();
	AOLIB_OBJECT void DoTarget();
	AOLIB_OBJECT float EstimatedDistanceTo(VECTOR3 &);
	AOLIB_OBJECT NanoTemplate* GetNCU(DWORD);
	AOLIB_OBJECT NanoTemplate* GetNCU(PCSTR);
	AOLIB_OBJECT DWORD GetNCUCount();
	AOLIB_OBJECT Actor* GetMaster();
	AOLIB_OBJECT DWORD GetMasterId();
	AOLIB_OBJECT Actor* GetPet(DWORD);
	AOLIB_OBJECT Actor* GetPet(PCSTR);
	AOLIB_OBJECT DWORD GetPetCount();
	AOLIB_OBJECT DWORD GetPetIDs(std::map<IDENTITY, DWORD>&);
	AOLIB_OBJECT PSIMPLECHAR GetSimpleCharData();
	AOLIB_OBJECT SpellTemplateData* GetSpellTemplateData();
	AOLIB_OBJECT Vehicle* GetVehicle();
	AOLIB_OBJECT WeaponHolder* GetWeaponHolder();
	AOLIB_OBJECT bool IsBackingUp();
	AOLIB_OBJECT bool IsCasting();
	AOLIB_OBJECT bool IsFightingMe();
	AOLIB_OBJECT bool IsFighting();
	AOLIB_OBJECT bool IsIdle();
	AOLIB_OBJECT bool IsInvis();
	AOLIB_OBJECT bool IsMovingForward();
	AOLIB_OBJECT bool IsNPC();
	AOLIB_OBJECT bool IsStrafingLeft();
	AOLIB_OBJECT bool IsStrafingRight();
	AOLIB_OBJECT bool HasPet();	
	AOLIB_OBJECT DWORD BuildLSNCU(LSIndex*);
	AOLIB_OBJECT DWORD BuildLSPets(LSIndex*);
};