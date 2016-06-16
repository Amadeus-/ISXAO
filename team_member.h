#pragma once

class TeamMember : public Player
{
public:
	AOLIB_OBJECT void Kick();
	AOLIB_OBJECT void MakeLeader();
	AOLIB_OBJECT bool IsInMyRaidTeam();
};