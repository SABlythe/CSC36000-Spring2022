DBG = -g
OPTS = $(DBG) -Wall -ansi -pedantic -std=c++20

CC = g++ -c $(OPTS)
LN = g++

OBJS = main.o Graph.o Vertex.o VertexPQ.o

dijkstra: $(OBJS)
	$(LN) -o dijkstra $(OBJS)

main.o: main.cpp Graph.hpp Vertex.hpp
	$(CC) main.cpp

Graph.o: Graph.cpp Graph.hpp Vertex.hpp
	$(CC) Graph.cpp

Vertex.o: Vertex.cpp Vertex.hpp
	$(CC) Vertex.cpp

VertexPQ.o: VertexPQ.cpp VertexPQ.hpp Vertex.hpp
	$(CC) VertexPQ.cpp


clean:
	/bin/rm -rf $(OBJS) dijkstra *~
