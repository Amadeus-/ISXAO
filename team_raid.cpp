#include "isxao_main.h"

namespace isxao_classes
{

	DWORD TeamRaid::BuildLSTeam(LSIndex *pIndex) const
	{
		std::vector<TeamEntry*> v;
		GetTeam(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		return pIndex->GetContainerUsed();
	}

	DWORD TeamRaid::BuildLSRaid(LSIndex *pIndex) const
	{
		std::vector<TeamEntry*> v;
		GetRaid(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		return pIndex->GetContainerUsed();
	}

	void TeamRaid::CreateRaid()
	{
		P_ENGINE_CLIENT_ANARCHY->N3Msg_CreateRaid();
	}

	TeamEntry* TeamRaid::GetTeamLeader() const
	{
		std::vector<TeamEntry*> raid_vector;
		GetRaid(raid_vector);
		for (auto it = raid_vector.begin(); it != raid_vector.end(); ++it)
		{
			if (P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamLeader((*it)->GetIdentity()))
				return (*it);
		}
		return nullptr;
	}

	DWORD TeamRaid::GetRaid(std::vector<TeamEntry*> &v) const
	{
		if (!IsRaid())
		{
			GetTeam(v, 0);
			return v.size();
		}			
		for (auto i = 0; i < 6; i++)
		{
			std::vector<TeamEntry*> team_entry_vector;
			GetTeam(team_entry_vector, i);
			for (auto it = team_entry_vector.begin(); it != team_entry_vector.end(); ++it)
			{
				if(!IsClientId((*it)->GetIdentity().Id))
					v.push_back(*it);
			}				
		}
		return v.size();
	}

	DWORD TeamRaid::GetRaidCount() const
	{
		std::vector<TeamEntry*> raid_vector;
		GetRaid(raid_vector);
		return raid_vector.size();
	}

	TeamEntry* TeamRaid::GetRaidMember(DWORD index) const
	{
		std::vector<TeamEntry*> raid_vector;
		GetRaid(raid_vector);
		if (index < 0 || index >= raid_vector.size())
			return nullptr;
		return raid_vector[index];
	}

	TeamEntry* TeamRaid::GetRaidMember(PCSTR raid_member_name) const
	{
		char name[MAX_STRING] = { 0 };
		char search_name[MAX_STRING];
		strcpy_s(search_name, MAX_STRING, raid_member_name);
		_strlwr_s(search_name);
		std::vector<TeamEntry*> raid_vector;
		GetRaid(raid_vector);
		for (auto it = raid_vector.begin(); it != raid_vector.end(); ++it)
		{
			strcpy_s(name, MAX_STRING, (*it)->GetName());
			_strlwr_s(name);
			if (strstr(name, search_name))
				return (*it);
		}
		return nullptr;
	}

	DWORD TeamRaid::GetTeam(std::vector<TeamEntry*> &v) const
	{
		if (!IsRaid())
		{
			GetTeam(v, 0);
			return v.size();
		}
		GetTeam(v, GetTeamRaidIndex());
		return v.size();
	}

	DWORD TeamRaid::GetTeam(std::vector<TeamEntry*> &v, DWORD index) const
	{
		if (index < 0 || index > 5)
			return 0;
		auto team_entry_vector = GetTeamRaidData().pTeamList[index];
		for (auto it = team_entry_vector->begin(); it != team_entry_vector->end(); ++it)
		{
			auto entry = reinterpret_cast<TeamEntry*>(*it);
			if (!IsClientId(entry->GetIdentity().Id))
				v.push_back(entry);
		}
		return v.size();
	}

	DWORD TeamRaid::GetTeamCount() const
	{
		std::vector<TeamEntry*> v;
		GetTeam(v);
		return v.size();
	}

	TeamEntry* TeamRaid::GetTeamMember(DWORD index) const
	{
		std::vector<TeamEntry*> team_entry_vector;
		GetTeam(team_entry_vector);
		if (index < 0 || index >= team_entry_vector.size())
			return nullptr;
		return team_entry_vector[index];
	}

	TeamEntry* TeamRaid::GetTeamMember(PCSTR team_member_name) const
	{
		char name[MAX_STRING] = { 0 };
		char search_name[MAX_STRING];
		strcpy_s(search_name, MAX_STRING, team_member_name);
		_strlwr_s(search_name);
		std::vector<TeamEntry*> team_entry_vector;
		GetTeam(team_entry_vector);
		for (auto it = team_entry_vector.begin(); it != team_entry_vector.end(); ++it)
		{
			strcpy_s(name, MAX_STRING, (*it)->GetName());
			_strlwr_s(name);
			if (strstr(name, search_name))
				return (*it);
		}
		return nullptr;
	}

	IDENTITY TeamRaid::GetTeamIdentity() const
	{
		return GetTeamRaidData().TeamIdentity;
	}

	IDENTITY TeamRaid::GetTeamLeaderID() const
	{
		return GetTeamRaidData().TeamLeaderIdentity;
	}

	TEAMRAIDHOLDER TeamRaid::GetTeamRaidData() const
	{
		return team_raid_holder_;
	}

	DWORD TeamRaid::GetTeamRaidIndex() const
	{
		return GetTeamRaidData().RaidTeamIndex;
	}

	bool TeamRaid::IsRaid() const
	{
		return GetTeamRaidData().RaidTeamIndex != -1;
	}

}