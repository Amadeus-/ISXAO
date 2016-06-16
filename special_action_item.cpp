#include "isxao_main.h"

namespace isxao_classes
{

	LONG SpecialActionItem::GetSkill(DWORD stat)
	{
		IDENTITY dummy_identity;
		ZeroMemory(&dummy_identity, sizeof(IDENTITY));
		return pEngineClientAnarchy->N3Msg_GetSkill(GetIdentity(), stat, 2, dummy_identity);
	}

	bool SpecialActionItem::IsGeneralAction()
	{
		return GetSkill(ST_ACTIONCATEGORY) == 2;
	}

	bool SpecialActionItem::IsPerk()
	{
		return GetSkill(ST_ACTIONCATEGORY) == 1;
	}

	bool SpecialActionItem::IsSpecialAttack()
	{
		return GetSkill(ST_ACTIONCATEGORY) == 3;
	}


}