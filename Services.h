#ifndef SERVICE
#define SERVICE_SELF
#define SERVICE(_name_,_callback_,_variable_) extern HISXSERVICE _variable_;extern void __cdecl _callback_(ISXInterface *pClient, unsigned int MSG, void *lpData);
#endif
// ----------------------------------------------------
// services

SERVICE("AO Service", AOService, hAOService);
SERVICE("AO Actor Service", ActorService, hActorService);
SERVICE("AO Teleport Service", TeleportService, hTeleportService);
SERVICE("AO Playfield Service", PlayfieldService, hPlayfieldService);
SERVICE("AO Gamestate Service", GamestateService, hGamestateService);











// ----------------------------------------------------
#ifdef SERVICE_SELF
#undef SERVICE_SELF
#undef SERVICE
#endif