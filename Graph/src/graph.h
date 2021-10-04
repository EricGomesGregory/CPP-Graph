#include "node.h"

class Graph
{
public:
	int verts;
	int edges;
	Node **adj;

	Graph(int verts);

	void InsertEdge(int vert, int w);
	void RemoveEdge(int vert, int w);
	void Print();

	~Graph();
};