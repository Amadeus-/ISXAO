#include "isxao_main.h"
namespace isxao_classes
{

	IDENTITY CastingData::GetCaster() const
	{
		return GetCastingData().Caster;
	}

	DWORD CastingData::GetNanoId() const
	{
		return GetCastingData().NanoId;
	}

	CASTINGDATA CastingData::GetCastingData() const
	{
		return casting_data_;
	}

	NanoItem* CastingData::GetNanoItem() const
	{
		return reinterpret_cast<NanoItem*>(GetCastingData().pNanoItem);
	}

	IDENTITY CastingData::GetTarget() const
	{
		return GetCastingData().Target;
	}

}