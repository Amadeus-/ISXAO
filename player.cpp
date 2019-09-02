#include "isxao_main.h"

namespace isxao_classes
{

	//TeamRaid* Player::GetTeamRaid()
	//{
	//	return reinterpret_cast<TeamRaid*>(GetSimpleCharData()->pTeamRaidInfo);
	//}

	//bool Player::IsInMyTeam()
	//{
	//	return IsInTeam() && GetTeamRaid()->GetTeamIdentity() == P_ENGINE_CLIENT_ANARCHY->GetClientChar()->GetTeamRaid()->GetTeamIdentity();
	//}

	//bool Player::IsInTeam()
	//{
	//	return GetTeamRaid()->GetTeamIdentity().Type != 0;
	//}

	//bool Player::IsInRaid()
	//{
	//	return IsInTeam() && GetTeamRaid()->GetTeamRaidIndex() != -1;
	//}

	//bool Player::IsTeamLeader()
	//{
	//	auto result = false;
	//	if (P_ENGINE_CLIENT_ANARCHY && IsInTeam() && IsInMyTeam())
	//		result = P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamLeader(GetIdentity());
	//	return result;
	//}

	//bool Player::SendTeamInvite()
	//{
	//	return P_ENGINE_CLIENT_ANARCHY->N3Msg_TeamJoinRequest(GetIdentity(), true);
	//}

}