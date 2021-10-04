#include <iostream>

#include "src/graph.h"

int main(int argc, char const *argv[])
{
	Graph *graph = new Graph(4);

	graph->InsertEdge(0, 1);
	graph->InsertEdge(1, 2);
	graph->InsertEdge(2, 3);
	graph->InsertEdge(3, 0);

	graph->Print();

	graph->RemoveEdge(3, 0);

	graph->Print();

	graph->~Graph();
	return 0;
}