#include "isxao_main.h"
namespace isxao_classes
{

	identity_t CastingData::GetCaster() const
	{
		return GetCastingData().caster;
	}

	DWORD CastingData::GetNanoId() const
	{
		return GetCastingData().nano_id;
	}

	casting_data_t CastingData::GetCastingData() const
	{
		return casting_data_;
	}

	NanoItem* CastingData::GetNanoItem() const
	{
		return reinterpret_cast<NanoItem*>(GetCastingData().p_nano_item);
	}

	identity_t CastingData::GetTarget() const
	{
		return GetCastingData().target;
	}

}