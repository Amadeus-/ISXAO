#include "isxao_main.h"

namespace isxao_classes
{

	PVOID DummyItemBase::GetData()
	{
		return &dummy_item_base_;
	}

	PDUMMYITEMBASE DummyItemBase::GetDummyItemBaseData()
	{
		return PDUMMYITEMBASE(GetData());
	}

	PCSTR DummyItemBase::GetDescription()
	{
		return GetDummyItemBaseData()->Description;
	}

	IDENTITY DummyItemBase::GetIdentity()
	{
		return GetDummyItemBaseData()->Identity;
	}

	IDENTITY DummyItemBase::GetParentIdentity()
	{
		return GetDummyItemBaseData()->ParentIdentity;
	}

	PCSTR DummyItemBase::GetName()
	{
		return GetDummyItemBaseData()->Name;
	}

}

