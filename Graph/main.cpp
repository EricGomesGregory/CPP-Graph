#include <iostream>

#include "src/graph.h"

int main(int argc, char const *argv[])
{
	int n; // Number of nodes
	int run = 1;
	int option;
	int vert, w;

	std::cout << "Dynamic list Graph" << std::endl;

	std::cout << "Input number of nodes in the graph:";
	std::cin  >> n;

	while(n <= 0)
	{
		std::cout << "Input number of nodes in the graph:";
		std::cin  >> n;
	}

	std::cout << "Graph | Nodes: [" << n << "]" << std::endl;

	Graph *graph = new Graph(n);

	while(run)
	{
		std::cout << "0- Exit" << std::endl;
		std::cout << "1- Insert Edge" << std::endl;
		std::cout << "2- Remove Edge" << std::endl;
		std::cout << "3- Print" << std::endl;

		std::cout << "Input Option:";
		std::cin  >> option;

		while(option < 0 || option > 3)
		{
			std::cout << std::endl << "Input valid option" << std::endl << std::endl;

			std::cout << "0- Exit" << std::endl;
			std::cout << "1- Insert Edge" << std::endl;
			std::cout << "2- Remove Edge" << std::endl;
			std::cout << "3- Print" << std::endl;

			std::cout << "Option:";
			std::cin  >> option;
		}

		switch(option)
		{
			case 0:
			run = 0;
			break;

			case 1:
			std::cout << "Insert Edge" << std::endl;
			
			std::cout << "Input origin vert:";
			std::cin  >> vert;

			while(vert < 0 || vert > graph->verts)
			{
				std::cout << std::endl << "Input valid origin vert" << std::endl << std::endl;

				std::cout << "Input origin vert:";
				std::cin  >> vert;
			}

			std::cout << "Input destination vert:";
			std::cin  >> w;

			while(w < 0 || w > graph->verts)
			{
				std::cout << std::endl << "Input valid destination vert" << std::endl << std::endl;

				std::cout << "Input destination vert:";
				std::cin  >> w;
			}

			graph->InsertEdge(vert, w);
			break;

			case 2:
			std::cout << "Remove Edge" << std::endl;
			
			std::cout << "Input origin vert:";
			std::cin  >> vert;

			while(vert < 0 || vert > graph->verts)
			{
				std::cout << std::endl << "Input valid origin vert" << std::endl << std::endl;

				std::cout << "Input origin vert:";
				std::cin  >> vert;
			}

			std::cout << "Input destination vert:";
			std::cin  >> w;

			while(w < 0 || w > graph->verts)
			{
				std::cout << std::endl << "Input valid destination vert" << std::endl << std::endl;

				std::cout << "Input destination vert:";
				std::cin  >> w;
			}

			graph->RemoveEdge(vert, w);
			break;

			case 3:
			std::cout << "Print" << std::endl;
			
			graph->Print();
			break;
		}
	}

	graph->~Graph();
	return 0;
}