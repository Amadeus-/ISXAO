#pragma once

class GraphPathFinder
{
public:
	GraphPathFinder(DWORD);
	GraphPathFinder(GraphPathFinder&);
	~GraphPathFinder();
	void Configure(int, int, float, float);
	void CreateFromData(PVOID);
	int FindPath(const vector3_t&, const vector3_t&, vector<vector3_t>&, PVOID, bool, bool);
	PVOID GenerateGraph(vector<vector3_t>&, float, float, float, float, PVOID, bool);
	void Init();
	//void GenerateGraphForRoom()
	void SetSpaceForGraph(PVOID);
	void SetSurface(PVOID);
//private:
	graph_path_finder_t graph_path_finder_;
};