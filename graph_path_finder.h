#pragma once

class graph_path_finder  // NOLINT(hicpp-special-member-functions, cppcoreguidelines-special-member-functions)
{
public:
	graph_path_finder(graph_path_finder&);
	graph_path_finder(DWORD);	
	~graph_path_finder();
	void configure(int, int, float, float);
	void create_from_data(PVOID);
	int find_path(const vector3_t&, const vector3_t&, vector<vector3_t>&, PVOID, bool, bool);
	void generate_graph(vector<vector3_t>&, float, float, float, float, PVOID, bool);
	void init();
	void set_space_for_graph(PVOID);
	void set_surface(PVOID);
//private:
	// ReSharper disable once CppInconsistentNaming
	graph_path_finder_t graph_path_finder_;
};