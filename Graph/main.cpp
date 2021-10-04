#include <iostream>

#include "src/graph.h"

int main(int argc, char const *argv[])
{
	std::cout << "Hello World" << std::endl;

	Graph *graph = new Graph(5);
	graph->Print();

	return 0;
}