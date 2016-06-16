#pragma once

class GraphPathFinder
{
public:
	GraphPathFinder(DWORD);
	GraphPathFinder(GraphPathFinder&);
	~GraphPathFinder();
	void Configure(int, int, float, float);
	void CreateFromData(PVOID);
	int FindPath(const VECTOR3&, const VECTOR3&, vector<VECTOR3>&, PVOID, bool, bool);
	PVOID GenerateGraph(vector<VECTOR3>&, float, float, float, float, PVOID, bool);
	void Init();
	//void GenerateGraphForRoom()
	void SetSpaceForGraph(PVOID);
	void SetSurface(PVOID);
//private:
	GRAPHPATHFINDER graph_path_finder_;
};