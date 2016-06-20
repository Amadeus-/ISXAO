#ifndef DATATYPE
#define DATATYPE_SELF
#define DATATYPE(_class_,_variable_,_inherits_) extern class _class_ *_variable_
#endif
// ----------------------------------------------------
// data types

// sample data type is the AOType class, and we're making a variable called pAOType.
// this type does not inherit from another type, so we use 0.  If it did inherit from another single type,
// we would use the pointer to the definition of that type, such as pStringType
DATATYPE(AOType,pAOType,0);
DATATYPE(ISXAOType, pISXAOType, 0);
DATATYPE(IdentityType, pIdentityType, 0);
DATATYPE(DynelType, pDynelType, 0);
DATATYPE(ActorType, pActorType, pDynelType);
DATATYPE(PlayerType, pPlayerType, pActorType);
DATATYPE(TeamMemberType, pTeamMemberType, pPlayerType);
DATATYPE(PetType, pPetType, pActorType);
DATATYPE(CharacterType, pCharacterType, pActorType);
DATATYPE(NanoSpellType, pNanoSpellType, 0);
DATATYPE(TeamEntryType, pTeamEntryType, 0);
DATATYPE(TeamRaidType, pTeamRaidType, 0);
DATATYPE(NanoTemplateType, pNanoTemplateType, 0);
DATATYPE(InventoryItemType, pInventoryItemType, 0);
DATATYPE(InventorySlotType, pInventorySlotType, 0);
DATATYPE(PlayfieldType, pPlayfieldType, 0);
DATATYPE(SpecialActionTemplateType, pSpecialActionTemplateType, 0);
DATATYPE(ActionLockType, pActionLockType, 0);
DATATYPE(SpecialActionType, pSpecialActionType, 0);









// ----------------------------------------------------
#ifdef DATATYPE_SELF
#undef DATATYPE_SELF
#undef DATATYPE
#endif