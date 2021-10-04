main: node.o graph.o main.o
	g++ node.o graph.o main.o -o main

node.o: src/node.h src/node.cpp
	g++ -c src/node.cpp

graph.o: src/graph.h src/graph.cpp
	g++ -c src/graph.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o main