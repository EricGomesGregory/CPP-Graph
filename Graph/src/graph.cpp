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
	if(vert < 0 || vert > this->verts) return;

	Node *node = this->adj[vert];

	while(node)
	{
		if(node->w == w)
		{
			this->adj[vert] = node->next;
			this->edges--;
			return;
		}

		node = node->next;
	}
}

void Graph::Print()
{
	std::cout << "Verst: " << this->verts;
	std::cout << " | ";
	std::cout << "Edges: " << this->edges;
	std::cout << std::endl;

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
	std::cout << std::endl;
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
			delete(prev);
		}
	}
	delete(this->adj);
}