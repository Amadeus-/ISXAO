#include "isxao_main.h"

namespace isxao_classes
{

	LONG PlayfieldAnarchy::GetPFWorldXPos() const
	{
		return playfield_anarchy_.PFWorldXPos;
	}

	LONG PlayfieldAnarchy::GetPFWorldZPos() const
	{
		return playfield_anarchy_.PFWorldZPos;
	}

	DWORD PlayfieldAnarchy::GetPlayfieldActors(std::vector<Actor*> &v)
	{
		for (auto it = playfield_anarchy_.DynelChildren.begin(); it != playfield_anarchy_.DynelChildren.end(); ++it)
		{
			if ((*it)->Identity.Type == 50000)
				v.push_back(reinterpret_cast<Actor*>(*it));
		}
		std::sort(v.begin(), v.end(), Dynel::pDynelCompare);
		return v.size();
	}

	PLAYFIELDANARCHY PlayfieldAnarchy::GetPlayfieldData() const
	{
		return playfield_anarchy_;
	}

	DWORD PlayfieldAnarchy::GetPlayfieldInstance() const
	{
		return playfield_anarchy_.InstanceID.Id;
	}

	PCSTR PlayfieldAnarchy::GetPlayfieldName() const
	{
		return playfield_anarchy_.pRDBPlayfield->Name;
	}

	float PlayfieldAnarchy::GetSizeX() const
	{
		return playfield_anarchy_.pn3Tilemap->pRDBTileMap->MapSizeMultiplier * playfield_anarchy_.pn3Tilemap->pRDBTileMap->Width;
	}

	float PlayfieldAnarchy::GetSizeZ() const
	{
		return playfield_anarchy_.pn3Tilemap->pRDBTileMap->MapSizeMultiplier * playfield_anarchy_.pn3Tilemap->pRDBTileMap->Height;
	}

	bool PlayfieldAnarchy::IsDungeon() const
	{
		return playfield_anarchy_.pn3Tilemap->pRDBTileMap->IsDungeon == 1;
	}

#ifdef n3Playfield_t__LineOfSight_x
	FUNCTION_AT_ADDRESS(bool PlayfieldAnarchy::LineOfSight(const VECTOR3 &, const VECTOR3 &, int, bool), n3Playfield_t__LineOfSight);
#endif

	PGRIDSPACE PlayfieldAnarchy::GetGridSpace() const
	{
		return playfield_anarchy_.pSpace_i;
	}

	PN3TILEMAPSURFACE PlayfieldAnarchy::GetTilemapSurface() const
	{
		return playfield_anarchy_.pSurface_i;
	}


#pragma endregion

#pragma region PlayfieldDir

	PlayfieldAnarchy* PlayfieldDir::GetPlayfield() const
	{
		return reinterpret_cast<PlayfieldAnarchy*>(playfield_dir_.Root->Node->pPlayfield);
	}

#pragma endregion

}

