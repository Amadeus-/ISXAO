#include "isxao_main.h"

namespace isxao_classes
{
	
#ifdef GRAPH_PATH_FINDER_T__GRAPH_PATH_FINDER_T_1_USE_NATIVE
	// ReSharper disable once CppPossiblyUninitializedMember
	FUNCTION_AT_ADDRESS(graph_path_finder::graph_path_finder(graph_path_finder&), graph_path_finder_t__graph_path_finder_t_1)
#else
	static_assert(false, "graph_path_finder::graph_path_finder(graph_path_finder&) requires a native function.");
#endif

#ifdef GRAPH_PATH_FINDER_T__GRAPH_PATH_FINDER_T_2_USE_NATIVE
	// ReSharper disable once CppPossiblyUninitializedMember
	FUNCTION_AT_ADDRESS(graph_path_finder::graph_path_finder(DWORD), graph_path_finder_t__graph_path_finder_t_2)
#else
	static_assert(false, "graph_path_finder::graph_path_finder(DWORD) requires a native function.");
#endif

#ifdef GRAPH_PATH_FINDER_T__D_GRAPH_PATH_FINDER_T_USE_NATIVE
	FUNCTION_AT_ADDRESS(graph_path_finder::~graph_path_finder(), graph_path_finder_t__d_graph_path_finder_t)
#else
	static_assert(false, "graph_path_finder::~graph_path_finder() requires a native function.");
#endif

#ifdef GRAPH_PATH_FINDER_T__CONFIGURE_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(void graph_path_finder::configure(int grid_x, int grid_z, float total_x, float total_z), graph_path_finder_t__configure)
#else
	static_assert(false, "graph_path_finder::configure(int grid_x, int grid_z, float total_x, float total_z) requires a native function.");
#endif

#ifdef GRAPH_PATH_FINDER_T__CREATE_FROM_DATA_USE_NATIVE
	// ReSharper disable once CppMemberFunctionMayBeStatic
	FUNCTION_AT_ADDRESS(void graph_path_finder::create_from_data(PVOID), graph_path_finder_t__create_from_data)
#else
	static_assert(false, "graph_path_finder::create_from_data(PVOID) requires a native function.");
#endif

	FUNCTION_AT_ADDRESS(int graph_path_finder::find_path(const vector3_t&, const vector3_t&, vector<vector3_t>&, PVOID, bool, bool), GraphPathFinder_t__FindPath);

	FUNCTION_AT_ADDRESS(PVOID graph_path_finder::generate_graph(vector<vector3_t>&, float, float, float, float, PVOID, bool), GraphPathFinder_t__GenerateGraph);

	FUNCTION_AT_ADDRESS(void graph_path_finder::init(), GraphPathFinder_t__Init);

	FUNCTION_AT_ADDRESS(void graph_path_finder::set_space_for_graph(PVOID), GraphPathFinder_t__SetSpaceForGraph);

	FUNCTION_AT_ADDRESS(void graph_path_finder::set_surface(PVOID), GraphPathFinder_t__SetSurface);


}