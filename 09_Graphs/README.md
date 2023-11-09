# Graphs
<img src = "https://miro.medium.com/max/1400/1*dtmsuTMqRvYzkUCS25tLDA.jpeg" alt= "image of graph">

# Introduction

A Graph is a data structure which represents connections between objects. It is a pair (V, E), where V is a set of nodes, called vertices (which represent objects), and E is a collection of pairs of vertices, called edges (which represent connections).

For example, the Internet often can be thought of as a graph, where web pages are connected to each other by links. 

Another example is maps, you can think of maps as a graph, sort of where you have intersections that are connected by roads. For example, we might be interested in questions like: “What’s the fastest way to go from home to college?” or “What is the cheapest way to go from home to college”. Graphs are data structures used for solving these kinds of problems.

# Graph Representation
Three ways to represent a graph are :-

## 1) Edge list
## 2) Adjacency Matrix

In this method, we use a matrix with size V × V. The values of matrix are boolean. The value of matrix[u][v] is set to 1 if there is an edge from vertex u to vertex v.

Adjacency matrix are useful to represent dense graphs.

## 3) Adjacency List

In this representation all the vertices connected to a vertex v are listed on A linked list for that vertex v.

Adjacency list are useful to represent sparse graphs.

<img src="../assets/Graph_Representations.png" alt="Graph Representation">

# Graph Traversals
Two ways to traverse a graph are :-

1) DFS
2) BFS

Every problem of graph is simply a modification of DFS and BFS algorithm. Whenever we try to solve graph problems, we need to think to traversal which fits the best for problem statement and the modifications which we need to make to the traversal. For eg. maintaining a simple counter during dfs previsit and postvisit allows us to count number of connected components in graph.