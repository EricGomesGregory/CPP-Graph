#include <iostream>
#include "graph.h"

Graph::Graph(int v)
{
	this->verts = v;
	this->edges = 0;

	this->adj = new Node*[v];
}

void Graph::InsertEdge(int vert, int w)
{

}

void Graph::RemoveEdge(int vert, int w)
{

}

void Graph::Print()
{
	for (int v = 0; v < this->verts; ++v)
	{
		Node *node = this->adj[v];
		
		std::cout << v << ":";
		while(node)
		{
			std::cout << node->w << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}
}

Graph::~Graph()
{

}