#include "isxao_main.h"

namespace isxao
{
	namespace events
	{
		int GetEventId(PCSTR pszEvent)
		{
			return pISInterface->RegisterEvent(pszEvent);
		}

		bool RegisterEvents()
		{
			pISInterface->RegisterEvent("AO_onActorDespawned");
			pISInterface->RegisterEvent("AO_onActorSpawned");
			pISInterface->RegisterEvent("AO_onAddPet");
			pISInterface->RegisterEvent("AO_onAttack");
			pISInterface->RegisterEvent("AO_onCastNanoSpell");
			pISInterface->RegisterEvent("AO_onCastNanoSpell_TargetSelf");
			pISInterface->RegisterEvent("AO_onCastNanoSpell_TargetOther");
			pISInterface->RegisterEvent("AO_onCastNanoSpell_CasterSelf");
			pISInterface->RegisterEvent("AO_onCastNanoSpell_CasterOther");
			pISInterface->RegisterEvent("AO_onFinishedCastingNano");
			pISInterface->RegisterEvent("AO_onFollowTarget");
			pISInterface->RegisterEvent("AO_onGamestateChanged");
			pISInterface->RegisterEvent("AO_onGroupMessageReceived");
			pISInterface->RegisterEvent("AO_onIncomingSystemText");
			pISInterface->RegisterEvent("AO_onNanoApplied");
			pISInterface->RegisterEvent("AO_onRemovePet");
			pISInterface->RegisterEvent("AO_onStand");
			pISInterface->RegisterEvent("AO_onTellReceived");
			pISInterface->RegisterEvent("AO_onVicinityMessageReceived");
			pISInterface->RegisterEvent("AO_onZoneBegin");
			pISInterface->RegisterEvent("AO_onZoneEnd");

			return true;
		}
	}
}