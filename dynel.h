#pragma once

class Dynel
{
public:
	AOLIB_OBJECT PVOID GetData();
	AOLIB_OBJECT float GetDistanceToClient();
	AOLIB_OBJECT float GetDistanceTo(vector3_t&);
	AOLIB_OBJECT float GetDistance3DTo(vector3_t&);
	AOLIB_OBJECT float GetDistance3DToSquared(vector3_t&);
	AOLIB_OBJECT float GetDistanceToSquared(vector3_t&);
	AOLIB_OBJECT float GetDistanceXTo(vector3_t&);
	AOLIB_OBJECT float GetDistanceYTo(vector3_t&);
	AOLIB_OBJECT float GetDistanceZTo(vector3_t&);
	AOLIB_OBJECT p_n3_dynel_t GetDynelData();
	AOLIB_OBJECT float GetHeading();
	AOLIB_OBJECT float GetHeadingTo(vector3_t &);
	AOLIB_OBJECT float GetHeadingToLoc(vector3_t &, vector3_t &);
	AOLIB_OBJECT identity_t GetIdentity();
	AOLIB_OBJECT PCSTR GetName();
	AOLIB_OBJECT vector3_t GetPosition();
	AOLIB_OBJECT quaternion_t GetRotation();
	AOLIB_OBJECT LONG GetSkill(DWORD);
	AOLIB_OBJECT bool IsInfoRequestCompleted();
	AOLIB_OBJECT void Interact();
	AOLIB_OBJECT bool IsContainer();
	AOLIB_OBJECT bool IsCorpse();
	AOLIB_OBJECT bool IsDoor();
	AOLIB_OBJECT bool IsInLineOfSight();
	AOLIB_OBJECT bool IsInLineOfSight(vector3_t &);
	AOLIB_OBJECT bool IsCharacter();
	AOLIB_OBJECT bool IsActor();
	AOLIB_OBJECT bool IsPet();
	AOLIB_OBJECT bool IsPlayer();
	AOLIB_OBJECT bool IsTeamMember();
	AOLIB_OBJECT bool IsVendingMachine();
	AOLIB_OBJECT bool IsWeaponInstance();
	AOLIB_OBJECT void SendIIRToObservers(InfoItemRemote*);
	AOLIB_OBJECT Actor* ToActor();
	AOLIB_OBJECT character* ToCharacter();
	AOLIB_OBJECT Pet* ToPet();
	AOLIB_OBJECT Player* ToPlayer();
	AOLIB_OBJECT TeamMember* ToTeamMember();
	AOLIB_OBJECT void UpdateLocalityListeners();
	AOLIB_OBJECT static bool pDynelCompare(Dynel *pA, Dynel *pB);
private: 
	n3_dynel_t n3_dynel_;
};