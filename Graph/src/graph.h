#include "node.h"

class Graph
{
public:
	int verts;
	int edges;
	Node **adj;

	int *depth;
	int *breadth;

	Graph(int verts);

	void InsertEdge(int vert, int w);
	void RemoveEdge(int vert, int w);
	void Print();

	void DepthFirstSearch(int v);
	void DepthPath(int vert, int w);

	void BreadthFirstSearch(int v);
	void BreadthPath(int vert, int w);

	~Graph();
};