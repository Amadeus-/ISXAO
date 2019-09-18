#pragma once

class graph_path_finder  // NOLINT(hicpp-special-member-functions, cppcoreguidelines-special-member-functions)
{
public:
	graph_path_finder(graph_path_finder&);
	graph_path_finder(DWORD);
	~graph_path_finder();
	void configure(int, int, float, float);
	void create_from_data(PVOID);
	int find_path(const ao::vector3_t&, const ao::vector3_t&, std::vector<ao::vector3_t>&, PVOID, bool, bool);
	void generate_graph(std::vector<ao::vector3_t>&, float, float, float, float, PVOID, bool);
	void init();
	void set_space_for_graph(PVOID);
	void set_surface(PVOID);
//private:
	// ReSharper disable once CppInconsistentNaming
	ao::graph_path_finder_t graph_path_finder_;
};