# Graphs

## Introduction

## Representaion

Three ways to represent a graph are :-
1) Adjacency Matrix
2) Adjacency List
3) Adjacency Set


### Adjecency Matrix
In this method, we use a matrix with size V × V. The values of matrix are boolean. The value matrix[u][v] is set to 1 if there is an edge from vertex u to vertex v and 0
otherwise.

The adjacency matrix representation is good if the graphs are dense. The matrix requires O(V^2) bits of storage and O(V^2) time for initialization. If the number of edges is proportional to V^2, then there is no problem because V^2 steps are required to read the edges. If the graph is sparse, the initialization of the matrix dominates the running time of the algorithm as it takes takes O(V^2).

## Adjecency list
In this representation all the vertices connected to a vertex v are listed on an adjacency list for that vertex v. This can be easily implemented with linked lists. That means, for each vertex v we use a linked list and list nodes represents the connections between v and other vertices to which v has an edge.


