#pragma once

class PlayfieldAnarchy
{
public:
	//void GetDynelsInVicinity(std::vector<identity_t, std::allocator<identity_t>> &, DWORD);
	AOLIB_OBJECT LONG GetPFWorldXPos() const;
	AOLIB_OBJECT LONG GetPFWorldZPos() const;
	AOLIB_OBJECT DWORD GetPlayfieldActors(std::vector<actor*> &v);
	AOLIB_OBJECT playfield_anarchy_t GetPlayfieldData() const;
	AOLIB_OBJECT DWORD GetPlayfieldInstance() const;
	AOLIB_OBJECT PCSTR GetPlayfieldName() const;
	AOLIB_OBJECT float GetSizeX() const;
	AOLIB_OBJECT float GetSizeZ() const;
	AOLIB_OBJECT bool IsDungeon() const;
	AOLIB_OBJECT bool LineOfSight(const vector3_t &, const vector3_t &, int, bool);
	AOLIB_OBJECT p_grid_space_t GetGridSpace() const;
	AOLIB_OBJECT p_n3_tile_map_surface_t GetTilemapSurface() const;
private:
	playfield_anarchy_t playfield_anarchy_;
};

class PlayfieldDir
{
public:
	PlayfieldAnarchy* GetPlayfield() const;
private:
	playfield_dir_t playfield_dir_;
};