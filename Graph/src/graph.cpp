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
	Node *newNode;

	Node *node = this->adj[vert];
	Node *prev = nullptr;

	while(node && w >= node->w)
	{
		if(w == node->w) return;

		prev = node;
		node = node->next;
	}

	newNode = new Node(w, node);

	if(prev == nullptr)
		this->adj[vert] = newNode;
	else
		prev->next = newNode;

	this->edges++;
}

void Graph::RemoveEdge(int vert, int w)
{
	Node *node = this->adj[vert];

	while(node)
	{

	}
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
	for (int v = 0; v < this->verts; ++v)
	{
		Node *node = this->adj[v];
		Node *prev = nullptr;

		while(node)
		{
			prev = node;
			node = node->next;
			delete(node);
		}
	}
	delete(this->adj);
	delete(this);
}