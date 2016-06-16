#pragma once

class PlayfieldAnarchy
{
public:
	//void GetDynelsInVicinity(std::vector<IDENTITY, std::allocator<IDENTITY>> &, DWORD);
	AOLIB_OBJECT LONG GetPFWorldXPos() const;
	AOLIB_OBJECT LONG GetPFWorldZPos() const;
	AOLIB_OBJECT DWORD GetPlayfieldActors(std::vector<Actor*> &v);
	AOLIB_OBJECT PLAYFIELDANARCHY GetPlayfieldData() const;
	AOLIB_OBJECT DWORD GetPlayfieldInstance() const;
	AOLIB_OBJECT PCSTR GetPlayfieldName() const;
	AOLIB_OBJECT float GetSizeX() const;
	AOLIB_OBJECT float GetSizeZ() const;
	AOLIB_OBJECT bool IsDungeon() const;
	AOLIB_OBJECT bool LineOfSight(const VECTOR3 &, const VECTOR3 &, int, bool);
	AOLIB_OBJECT PGRIDSPACE GetGridSpace() const;
	AOLIB_OBJECT PN3TILEMAPSURFACE GetTilemapSurface() const;
private:
	PLAYFIELDANARCHY playfield_anarchy_;
};

class PlayfieldDir
{
public:
	PlayfieldAnarchy* GetPlayfield() const;
private:
	PLAYFIELDDIR playfield_dir_;
};