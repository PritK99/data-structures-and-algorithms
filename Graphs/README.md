# Graphs
<img src = "https://cdn-media-1.freecodecamp.org/images/9KFiyFYi9bMktsJkMKLKaeJl31heUN9A-xrr" alt= "image of graph">

## Introduction

Graph: A graph is a pair (V, E), where V is a set of nodes, called vertices, and £ is a collection of pairs of vertices, called edges.

In the real world, many problems are represented in terms of objects and connections between them. For example, in an railway map, we might be interested in questions like: “What’s the fastest way to go from Mumbai to Delhi?” or “What is the cheapest way to go from Mumbai to Delhi”. Graphs are data structures used for solving these kinds of problems.

## Representaion

Three ways to represent a graph are :-
1) Adjacency Matrix
2) Adjacency List
3) Adjacency Set


### Adjecency Matrix
In this method, we use a matrix with size V × V. The values of matrix are boolean. The value matrix[u][v] is set to 1 if there is an edge from vertex u to vertex v and 0
otherwise.

![image](https://user-images.githubusercontent.com/103832825/205418525-12985bed-d22d-4db0-8808-58304748678f.png)
![image](https://user-images.githubusercontent.com/103832825/205418536-5f32e9b6-a0d2-4811-b51e-02e90c8f14a8.png)

The adjacency matrix representation is good if the graphs are dense. The matrix requires O(V^2) bits of storage and O(V^2) time for initialization. If the number of edges is proportional to V^2, then there is no problem because V^2 steps are required to read the edges. If the graph is sparse, the initialization of the matrix dominates the running time of the algorithm as it takes takes O(V^2).

### Adjecency list
In this representation all the vertices connected to a vertex v are listed on an adjacency list for that vertex v. This can be easily implemented with linked lists. That means, for each vertex v we use a linked list and list nodes represents the connections between v and other vertices to which v has an edge.

<img src = "https://www.softwaretestinghelp.com/wp-content/qa/uploads/2020/05/7-6.png" alt = "Image of adjacency list">

### Comparison
<img src = "https://i.stack.imgur.com/P8UiR.png" alt = "comparison between different graph representation methods" width = "750" height = "300">

