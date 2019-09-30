#include "isxao_main.h"
#include "engine_client_anarchy.h"
#include "team_entry.h"
#include "team_raid.h"

namespace ao
{

	unsigned long team_raid::build_ls_team(LSIndex *p_index)
	{
		std::vector<team_entry*> v;
		if (this->get_team(v))
		{
			for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
				p_index->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		}		
		return p_index->GetContainerUsed();
	}

	unsigned long team_raid::build_ls_raid(LSIndex *p_index)
	{
		std::vector<team_entry*> v;
		if (this->get_raid(v))
		{
			for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
				p_index->AddItem(reinterpret_cast<LSOBJECTDATA&>(*it));
		}		
		return p_index->GetContainerUsed();
	}

	void team_raid::create_raid()
	{
		P_ENGINE_CLIENT_ANARCHY->n3_msg_create_raid();
	}

	team_entry* team_raid::get_team_leader()
	{
		std::vector<team_entry*> v;
		if (this->get_raid(v))
		{
			for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				if (P_ENGINE_CLIENT_ANARCHY->N3Msg_IsTeamLeader((*it)->get_identity()))
					return (*it);
			}
		}		
		return nullptr;
	}

	unsigned long team_raid::get_raid(std::vector<team_entry*> &v)
	{
		if (!this->is_raid())
		{
			return this->get_team(v, 0);
		}			
		for (auto i = 0; i < 6; i++)
		{
			std::vector<team_entry*> team_entry_vector;
			if (this->get_team(team_entry_vector, i))  
			{
				for (auto it = team_entry_vector.begin(); it != team_entry_vector.end(); ++it)// NOLINT(modernize-loop-convert)
				{
					if (!isxao::is_client_id((*it)->get_identity().id))
						v.push_back(*it);
				}
			}							
		}
		return v.size();
	}

	unsigned long team_raid::get_raid_count()
	{
		std::vector<team_entry*> raid_vector;
		return this->get_raid(raid_vector);
	}

	team_entry* team_raid::get_raid_member(const unsigned long index)
	{
		std::vector<team_entry*> v;
		if (this->get_raid(v))
		{
			if (index > 0 && index < v.size())				
				return v[index];
		}
		return nullptr;
	}

	team_entry* team_raid::get_raid_member(const char* raid_member_name)
	{
		char name[MAX_VARSTRING] = { 0 };
		char search_name[MAX_VARSTRING];
		strcpy_s(search_name, MAX_VARSTRING, raid_member_name);
		_strlwr_s(search_name);
		std::vector<team_entry*> v;
		if (this->get_raid(v))
		{
			for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				strcpy_s(name, MAX_VARSTRING, (*it)->get_name());
				_strlwr_s(name);
				if (strstr(name, search_name))
					return (*it);
			}
		}		
		return nullptr;
	}

	unsigned long team_raid::get_team(std::vector<team_entry*> &v)
	{
		if (!is_raid())
			return get_team(v, 0);
		return this->get_team(v, get_team_raid_index());
	}

	unsigned long team_raid::get_team(std::vector<team_entry*> &v, const unsigned long index)
	{
		if (index < 0 || index > 5)
			return 0;
		auto team_entry_vector = get_data()->p_team_list[index];
		for (auto it = team_entry_vector->begin(); it != team_entry_vector->end(); ++it)  // NOLINT(modernize-loop-convert)
		{
			auto entry = reinterpret_cast<team_entry*>(*it);
			if (!isxao::is_client_id(entry->get_identity().id))
				v.push_back(entry);
		}
		return v.size();
	}

	unsigned long team_raid::get_team_count()
	{
		std::vector<team_entry*> v;
		return get_team(v);;
	}

	team_entry* team_raid::get_team_member(const unsigned long index)
	{
		std::vector<team_entry*> v;
		if (this->get_team(v))
		{
			if (index > 0 && index < v.size())
				return v[index];
		}
		return nullptr;
	}

	team_entry* team_raid::get_team_member(const char* team_member_name)
	{
		char name[MAX_VARSTRING] = { 0 };
		char search_name[MAX_VARSTRING];
		strcpy_s(search_name, MAX_VARSTRING, team_member_name);
		_strlwr_s(search_name);
		std::vector<team_entry*> v;
		if (this->get_team(v))
		{
			for (auto it = v.begin(); it != v.end(); ++it)  // NOLINT(modernize-loop-convert)
			{
				strcpy_s(name, MAX_VARSTRING, (*it)->get_name());
				_strlwr_s(name);
				if (strstr(name, search_name))
					return (*it);
			}
		}		
		return nullptr;
	}

	identity_t team_raid::get_team_identity()
	{
		return get_data()->team_identity;
	}

	identity_t team_raid::get_team_leader_id()
	{
		return get_data()->team_leader_identity;
	}

	unsigned long team_raid::get_team_raid_index()
	{
		return get_data()->raid_team_index;
	}

	bool team_raid::is_raid()
	{
		return get_data()->raid_team_index != -1;
	}

}