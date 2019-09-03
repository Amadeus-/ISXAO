#include "isxao_main.h"

namespace isxao_classes
{
	
	GraphPathFinder::GraphPathFinder(DWORD i)
	{
		typedef void(__thiscall *tGraphPathFinder)(GraphPathFinder*, DWORD);
		auto pGraphFinder = tGraphPathFinder(GraphPathFinder_t__GraphPathFinder_t);
		pGraphFinder(this, i);
	}

	GraphPathFinder::GraphPathFinder(GraphPathFinder& g)
	{
		typedef void(__thiscall *tGraphPathFinder)(GraphPathFinder*, GraphPathFinder&);
		auto pGraphPathFinder = tGraphPathFinder(GraphPathFinder_t__GraphPathFinder_t_Copy);
		pGraphPathFinder(this, g);
	}

	GraphPathFinder::~GraphPathFinder()
	{
		typedef void(__thiscall * tdGraphPathFinder)(GraphPathFinder*);
		auto pdGraphPathFinder = tdGraphPathFinder(GraphPathFinder_t__dGraphPathFinder_t);
		pdGraphPathFinder(this);
	}

	FUNCTION_AT_ADDRESS(void GraphPathFinder::Configure(int grid_x, int grid_z, float total_x, float total_z), GraphPathFinder_t__Configure);

	FUNCTION_AT_ADDRESS(void GraphPathFinder::CreateFromData(PVOID), GraphPathFinder_t__CreateFromData);

	FUNCTION_AT_ADDRESS(int GraphPathFinder::FindPath(const vector3_t&, const vector3_t&, vector<vector3_t>&, PVOID, bool, bool), GraphPathFinder_t__FindPath);

	FUNCTION_AT_ADDRESS(PVOID GraphPathFinder::GenerateGraph(vector<vector3_t>&, float, float, float, float, PVOID, bool), GraphPathFinder_t__GenerateGraph);

	FUNCTION_AT_ADDRESS(void GraphPathFinder::Init(), GraphPathFinder_t__Init);

	FUNCTION_AT_ADDRESS(void GraphPathFinder::SetSpaceForGraph(PVOID), GraphPathFinder_t__SetSpaceForGraph);

	FUNCTION_AT_ADDRESS(void GraphPathFinder::SetSurface(PVOID), GraphPathFinder_t__SetSurface);


}