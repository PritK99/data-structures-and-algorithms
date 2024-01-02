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

# Dijkstra's Algorithm

Dijkstra's Algorithm is essentially BFS + Heuristics. It allows us to calculate shortest path from a given source node to all other nodes in the graph. 

<img src="../assets/djikstras intuition.png" alt="Djikstra's Intution">

Consider we are at a node A, which is connected to node B and C by weights 3 and 5 respectively. Here, we can not be sure that distance between A and C i.e. 5, is the shortest one between A and C. This is beacuse, chances are B and C might be connected by weight 1, which makes shortest path between A and C as A -> B -> C of length 4. However, we can be sure, that the distance between A and B is the shortest possible distance between A and B. This is because there is no other possibility which can give path shorter than A -> B directly. Here A -> C -> B will definitely be more expensive since A -> C itself is more expensive than A -> B.

A naive approach can be to keep on relaxing edges in a while loop till there comes a state where no edge is relaxed in the entire loop. However, the above intuition allows us to relax edges in certain order. 

The time complexity of Dijkstra's algorithm depends on the underlying data structure. If our priority queue is based on heap, the Time Complexity is ```O((|V| + |E|)log(|V|))```. On the other hand, if our priority queue is array bases, it takes ```O(|V|^2)```. It is important to note that in case of dense graphs, array implementation of Priority Queue works better than Heap implementation. Thus, the choice of data structure depends on the sparsity of graph.

# Bellman-Ford Algorithm

The intuition which we had for dijkstra's algorithm fails when we take negative edges in account. Because now for the above example, A -> C -> B can be cheaper than A -> B, if C -> B were to become negative. Hence for graphs with negative weights, we use Bellman Ford Algorithm.

The idea behind bellman ford algorithm is a naive version of Dijkstra's algorithm. It doesnt follow any sense of heuristic to relax edges. We keep on relaxing all the edges in the graph for |V|-1 times. Thus the time complexity is ```O(|V||E|)```. However, this algorithm currently works only for graphs with no negative cycles. In presence of negative cycles, the distances can be relaxed infinitely. Thus we slightly modify the code to accommodate negative distances as well.

# Minimum Spanning Tree

A minimum spanning tree (MST) of a connected, undirected graph G(V, E) is a subset of the edges E' that forms a tree (i.e., it is connected and acyclic) and spans all the vertices in V. Furthermore, the sum of the weights of the edges in the minimum spanning tree is minimized.

# Kruskal Algorithm

The core idea is indeed to add edges to the growing minimum spanning tree in increasing order of their weights, as long as adding the edge does not form a cycle.

# Prims Algorithm
