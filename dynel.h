#pragma once

class Dynel
{
public:
	AOLIB_OBJECT PVOID GetData();
	AOLIB_OBJECT float GetDistanceToClient();
	AOLIB_OBJECT float GetDistanceTo(VECTOR3&);
	AOLIB_OBJECT float GetDistance3DTo(VECTOR3&);
	AOLIB_OBJECT float GetDistance3DToSquared(VECTOR3&);
	AOLIB_OBJECT float GetDistanceToSquared(VECTOR3&);
	AOLIB_OBJECT float GetDistanceXTo(VECTOR3&);
	AOLIB_OBJECT float GetDistanceYTo(VECTOR3&);
	AOLIB_OBJECT float GetDistanceZTo(VECTOR3&);
	AOLIB_OBJECT PN3DYNEL GetDynelData();
	AOLIB_OBJECT float GetHeading();
	AOLIB_OBJECT float GetHeadingTo(VECTOR3 &);
	AOLIB_OBJECT float GetHeadingToLoc(VECTOR3 &, VECTOR3 &);
	AOLIB_OBJECT IDENTITY GetIdentity();
	AOLIB_OBJECT PCSTR GetName();
	AOLIB_OBJECT VECTOR3 GetPosition();
	AOLIB_OBJECT QUATERNION GetRotation();
	AOLIB_OBJECT LONG GetSkill(DWORD);
	AOLIB_OBJECT bool IsInfoRequestCompleted();
	AOLIB_OBJECT void Interact();
	AOLIB_OBJECT bool IsContainer();
	AOLIB_OBJECT bool IsCorpse();
	AOLIB_OBJECT bool IsDoor();
	AOLIB_OBJECT bool IsInLineOfSight();
	AOLIB_OBJECT bool IsInLineOfSight(VECTOR3 &);
	AOLIB_OBJECT bool IsCharacter();
	AOLIB_OBJECT bool IsActor();
	AOLIB_OBJECT bool IsPet();
	AOLIB_OBJECT bool IsPlayer();
	AOLIB_OBJECT bool IsTeamMember();
	AOLIB_OBJECT bool IsVendingMachine();
	AOLIB_OBJECT bool IsWeaponInstance();
	AOLIB_OBJECT void SendIIRToObservers(InfoItemRemote*);
	AOLIB_OBJECT Actor* ToActor();
	AOLIB_OBJECT Character* ToCharacter();
	AOLIB_OBJECT Pet* ToPet();
	AOLIB_OBJECT Player* ToPlayer();
	AOLIB_OBJECT TeamMember* ToTeamMember();
	AOLIB_OBJECT void UpdateLocalityListeners();
	AOLIB_OBJECT static bool pDynelCompare(Dynel *pA, Dynel *pB);
private: 
	N3DYNEL n3_dynel_;
};