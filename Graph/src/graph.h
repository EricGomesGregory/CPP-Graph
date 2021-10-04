class Graph
{
protected:

public:
	Graph();

	void InsertEdge(int vert, int w);
	void RemoveEdge(int vert, int w);
	void Print();

	~Graph();
};