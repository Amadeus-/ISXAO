#ifndef COMMAND
#define COMMAND_SELF
#define COMMAND(name,cmd,parse,hide) extern int cmd(int argc, char *argv[])
#endif
// ----------------------------------------------------
// commands

// sample
COMMAND("AO",CMD_AO,true,false);
COMMAND("STRUCTS", CMD_TESTSTRUCTS, false, false);
COMMAND("INTERFACE", CMD_TESTINTERFACE, false, false);
COMMAND("DUMPSTATS", CMD_DUMPSTATS, false, false);
COMMAND("ATTACK", CMD_ATTACK, false, false);
COMMAND("DUMPSAS", CMD_DUMPSPECIALACTIONS, false, false);

COMMAND("Activate", CMD_ACTIVATE, true, false);
COMMAND("AOEcho", CMD_AOECHO, true, false);
COMMAND("AOExecute", CMD_AOEXECUTE, true, false);
COMMAND("Face", CMD_FACE, true, false);
COMMAND("Target", CMD_TARGET, true, false);

// ----------------------------------------------------
#ifdef COMMAND_SELF
#undef COMMAND_SELF
#undef COMMAND
#endif