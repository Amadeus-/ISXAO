#include "isxao_main.h"

namespace isxao_classes
{

	DWORD TeamRaid::BuildLSTeam(LSIndex *pIndex) const
	{
		std::vector<team_entry*> v;
		GetTeam(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		return pIndex->GetContainerUsed();
	}

	DWORD TeamRaid::BuildLSRaid(LSIndex *pIndex) const
	{
		std::vector<team_entry*> v;
		GetRaid(v);
		for (auto it = v.begin(); it != v.end(); ++it)
			pIndex->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		return pIndex->GetContainerUsed();
	}

	void TeamRaid::CreateRaid()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_create_raid();
	}

	team_entry* TeamRaid::GetTeamLeader() const
	{
		std::vector<team_entry*> raid_vector;
		GetRaid(raid_vector);
		for (auto it = raid_vector.begin(); it != raid_vector.end(); ++it)
		{
			if (P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamLeader((*it)->get_identity()))
				return (*it);
		}
		return nullptr;
	}

	DWORD TeamRaid::GetRaid(std::vector<team_entry*> &v) const
	{
		if (!IsRaid())
		{
			GetTeam(v, 0);
			return v.size();
		}			
		for (auto i = 0; i < 6; i++)
		{
			std::vector<team_entry*> team_entry_vector;
			GetTeam(team_entry_vector, i);
			for (auto it = team_entry_vector.begin(); it != team_entry_vector.end(); ++it)
			{
				if(!IsClientId((*it)->get_identity().id))
					v.push_back(*it);
			}				
		}
		return v.size();
	}

	DWORD TeamRaid::GetRaidCount() const
	{
		std::vector<team_entry*> raid_vector;
		GetRaid(raid_vector);
		return raid_vector.size();
	}

	team_entry* TeamRaid::GetRaidMember(DWORD index) const
	{
		std::vector<team_entry*> raid_vector;
		GetRaid(raid_vector);
		if (index < 0 || index >= raid_vector.size())
			return nullptr;
		return raid_vector[index];
	}

	team_entry* TeamRaid::GetRaidMember(PCSTR raid_member_name) const
	{
		char name[MAX_STRING] = { 0 };
		char search_name[MAX_STRING];
		strcpy_s(search_name, MAX_STRING, raid_member_name);
		_strlwr_s(search_name);
		std::vector<team_entry*> raid_vector;
		GetRaid(raid_vector);
		for (auto it = raid_vector.begin(); it != raid_vector.end(); ++it)
		{
			strcpy_s(name, MAX_STRING, (*it)->get_name());
			_strlwr_s(name);
			if (strstr(name, search_name))
				return (*it);
		}
		return nullptr;
	}

	DWORD TeamRaid::GetTeam(std::vector<team_entry*> &v) const
	{
		if (!IsRaid())
		{
			GetTeam(v, 0);
			return v.size();
		}
		GetTeam(v, GetTeamRaidIndex());
		return v.size();
	}

	DWORD TeamRaid::GetTeam(std::vector<team_entry*> &v, DWORD index) const
	{
		if (index < 0 || index > 5)
			return 0;
		auto team_entry_vector = GetTeamRaidData().p_team_list[index];
		for (auto it = team_entry_vector->begin(); it != team_entry_vector->end(); ++it)
		{
			auto entry = reinterpret_cast<team_entry*>(*it);
			if (!IsClientId(entry->get_identity().id))
				v.push_back(entry);
		}
		return v.size();
	}

	DWORD TeamRaid::GetTeamCount() const
	{
		std::vector<team_entry*> v;
		GetTeam(v);
		return v.size();
	}

	team_entry* TeamRaid::GetTeamMember(DWORD index) const
	{
		std::vector<team_entry*> team_entry_vector;
		GetTeam(team_entry_vector);
		if (index < 0 || index >= team_entry_vector.size())
			return nullptr;
		return team_entry_vector[index];
	}

	team_entry* TeamRaid::GetTeamMember(PCSTR team_member_name) const
	{
		char name[MAX_STRING] = { 0 };
		char search_name[MAX_STRING];
		strcpy_s(search_name, MAX_STRING, team_member_name);
		_strlwr_s(search_name);
		std::vector<team_entry*> team_entry_vector;
		GetTeam(team_entry_vector);
		for (auto it = team_entry_vector.begin(); it != team_entry_vector.end(); ++it)
		{
			strcpy_s(name, MAX_STRING, (*it)->get_name());
			_strlwr_s(name);
			if (strstr(name, search_name))
				return (*it);
		}
		return nullptr;
	}

	identity_t TeamRaid::GetTeamIdentity() const
	{
		return GetTeamRaidData().team_identity;
	}

	identity_t TeamRaid::GetTeamLeaderID() const
	{
		return GetTeamRaidData().team_leader_identity;
	}

	team_raid_holder_t TeamRaid::GetTeamRaidData() const
	{
		return team_raid_holder_;
	}

	DWORD TeamRaid::GetTeamRaidIndex() const
	{
		return GetTeamRaidData().raid_team_index;
	}

	bool TeamRaid::IsRaid() const
	{
		return GetTeamRaidData().raid_team_index != -1;
	}

}