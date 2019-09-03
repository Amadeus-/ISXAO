#include "isxao_main.h"
namespace isxao_classes
{

	identity_t CastingData::GetCaster() const
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

	identity_t CastingData::GetTarget() const
	{
		return GetCastingData().Target;
	}

}