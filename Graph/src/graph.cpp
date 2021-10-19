#include <iostream>
#include "graph.h"

Graph::Graph(int v)
{
	this->verts = v;
	this->edges = 0;

	this->adj = new Node*[v];
	this->depth = new int[v];
	this->breadth = new int[v];
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

void Graph::DepthFirstSearch()
{
}


void Graph::BreadthFirstSearch(int v)
{
	int *qeuee = new int[this->verts];
	int first = 0;
	int last  = 0;

	int *visited = new int[this->verts];
	int u;

	visited[v] = 1;
	qeuee[first] = v;
	last++;

	std::cout << "Breadth First Search: ";

	while(first != last)
	{
		u = qeuee[first];
		qeuee[first] = 0;
		std::cout << u << " ";
		first++;

		Node *node = this->adj[u];
		while(node)
		{
			int w = node->w;
			if(visited[w] == 0)
			{
				this->breadth[w] = u;
				visited[w] = 1;
				qeuee[last] = w;
				last++;
			}

			node = node->next;
		}
	}
	std::cout << std::endl;
}

void BPath(Graph *graph, int from, int to)
{
	if(from == to)
	{
		std::cout << from << " ";
		return;
	}

	BPath(graph, from, graph->breadth[to]);
	std::cout << to << " ";
}

void Graph::BreadthPath(int from, int to)
{
	std::cout << "Path: ";
	BPath(this, from, to);
	std::cout << std::endl;
}