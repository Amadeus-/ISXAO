#include "isxao_main.h"

namespace isxao_classes
{

	PVOID DummyItemBase::GetData()
	{
		return &dummy_item_base_;
	}

	p_dummy_item_base_t DummyItemBase::GetDummyItemBaseData()
	{
		return p_dummy_item_base_t(GetData());
	}

	PCSTR DummyItemBase::GetDescription()
	{
		return GetDummyItemBaseData()->description;
	}

	identity_t DummyItemBase::GetIdentity()
	{
		return GetDummyItemBaseData()->identity;
	}

	identity_t DummyItemBase::GetParentIdentity()
	{
		return GetDummyItemBaseData()->parent_identity;
	}

	PCSTR DummyItemBase::GetName()
	{
		return GetDummyItemBaseData()->name;
	}

}

