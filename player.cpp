#include "isxao_main.h"

namespace isxao_classes
{

	TeamRaid* Player::GetTeamRaid()
	{
		return reinterpret_cast<TeamRaid*>(GetSimpleCharData()->pTeamRaidInfo);
	}

	bool Player::IsInMyTeam()
	{
		return IsInTeam() && GetTeamRaid()->GetTeamIdentity() == pEngineClientAnarchy->GetClientChar()->GetTeamRaid()->GetTeamIdentity();
	}

	bool Player::IsInTeam()
	{
		return GetTeamRaid()->GetTeamIdentity().Type != 0;
	}

	bool Player::IsInRaid()
	{
		return IsInTeam() && GetTeamRaid()->GetTeamRaidIndex() != -1;
	}

	bool Player::IsTeamLeader()
	{
		auto result = false;
		if (pEngineClientAnarchy && IsInTeam() && IsInMyTeam())
			result = pEngineClientAnarchy->N3Msg_IsTeamLeader(GetIdentity());
		return result;
	}

	bool Player::SendTeamInvite()
	{
		return pEngineClientAnarchy->N3Msg_TeamJoinRequest(GetIdentity(), true);
	}

}