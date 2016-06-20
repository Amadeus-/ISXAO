#ifndef TOPLEVELOBJECT
#define TOPLEVELOBJECT_SELF
#define TOPLEVELOBJECT(name,funcname) extern bool funcname(int argc, char *argv[], LSTYPEVAR &Ret);
#endif

// ----------------------------------------------------
// Top-Level Objects

TOPLEVELOBJECT("AO",TLO_AO);
TOPLEVELOBJECT("ISXAO", TLO_ISXAO);
TOPLEVELOBJECT("Me", TLO_ME);
TOPLEVELOBJECT("Target", TLO_SELECTIONTARGET);
TOPLEVELOBJECT("WeaponTarget", TLO_ATTACKTARGET);
TOPLEVELOBJECT("Actor", TLO_ACTORSEARCH);
TOPLEVELOBJECT("ActorCount", TLO_ACTORSEARCHCOUNT);
TOPLEVELOBJECT("NanoSpell", TLO_NANOSPELL);
TOPLEVELOBJECT("TeamRaid", TLO_TEAMRAID);
TOPLEVELOBJECT("Playfield", TLO_PLAYFIELD);
TOPLEVELOBJECT("SpecialAction", TLO_SPECIALACTION);













// ----------------------------------------------------
#ifdef TOPLEVELOBJECT_SELF
#undef TOPLEVELOBJECT_SELF
#undef TOPLEVELOBJECT
#endif