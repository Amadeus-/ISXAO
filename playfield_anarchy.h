#pragma once

class PlayfieldAnarchy
{
public:
	//void GetDynelsInVicinity(std::vector<identity_t, std::allocator<identity_t>> &, DWORD);
	LONG GetPFWorldXPos() const;
	LONG GetPFWorldZPos() const;
	DWORD GetPlayfieldActors(std::vector<ao::actor*> &v);
	ao::playfield_anarchy_t GetPlayfieldData() const;
	DWORD GetPlayfieldInstance() const;
	PCSTR GetPlayfieldName() const;
	float GetSizeX() const;
	float GetSizeZ() const;
	bool IsDungeon() const;
	bool LineOfSight(const ao::vector3_t &, const ao::vector3_t &, int, bool);
	ao::p_grid_space_t GetGridSpace() const;
	ao::p_n3_tile_map_surface_t GetTilemapSurface() const;
private:
	ao::playfield_anarchy_t playfield_anarchy_;
};

class PlayfieldDir
{
public:
	PlayfieldAnarchy* GetPlayfield() const;
private:
	ao::playfield_dir_t playfield_dir_;
};