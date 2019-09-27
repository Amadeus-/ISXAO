#pragma once
#include "game_object.h"

namespace std
{
	template <typename _Tp, typename _Alloc>
	class vector;
}

namespace ao
{
	struct ao_graph_path_finder;
	struct ao_vector3;

	typedef ao_graph_path_finder graph_path_finder_t, *p_graph_path_finder_t;
	typedef ao_vector3 vector3_t, *p_vector3_t;

	class graph_path_finder : game_object<graph_path_finder_t>  // NOLINT(hicpp-special-member-functions)
	{
	public:
		graph_path_finder(graph_path_finder&);
		graph_path_finder(unsigned long);
		~graph_path_finder();
		void configure(int, int, float, float);
		void create_from_data(void*);
		int find_path(const ao::vector3_t&, const ao::vector3_t&, std::vector<ao::vector3_t>&, void*, bool, bool);
		void generate_graph(std::vector<ao::vector3_t>&, float, float, float, float, void*, bool);
		void init();
		void set_space_for_graph(void*);
		void set_surface(void*);
	};
}
