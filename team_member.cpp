#include "isxao_main.h"

namespace isxao_classes
{

	void TeamMember::Kick()
	{
		pEngineClientAnarchy->N3Msg_KickTeamMember(GetIdentity());
	}

	void TeamMember::MakeLeader()
	{
		pEngineClientAnarchy->GetClientChar()->MakeTeamLeader(GetIdentity());
	}

	bool TeamMember::IsInMyRaidTeam()
	{
		std::vector<TeamEntry*> v;
		pEngineClientAnarchy->GetClientChar()->GetTeamRaid()->GetTeam(v);
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			if ((*it)->GetIdentity() == GetIdentity())
				return true;
		}
		return false;
	}

}