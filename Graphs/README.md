# Graphs
<img src = "https://cdn-media-1.freecodecamp.org/images/9KFiyFYi9bMktsJkMKLKaeJl31heUN9A-xrr" alt= "image of graph">

# Introduction

Graph: A graph is a pair (V, E), where V is a set of nodes, called vertices, and £ is a collection of pairs of vertices, called edges.

In the real world, many problems are represented in terms of objects and connections between them. For example, in an railway map, we might be interested in questions like: “What’s the fastest way to go from home to college?” or “What is the cheapest way to go from home to college”. Graphs are data structures used for solving these kinds of problems.

# Representaion

Three ways to represent a graph are :-
1) Adjacency Matrix
2) Adjacency List
3) Adjacency Set


## Adjecency Matrix
In this method, we use a matrix with size V × V. The values of matrix are boolean. The value matrix[u][v] is set to 1 if there is an edge from vertex u to vertex v and 0
otherwise.

![image](https://user-images.githubusercontent.com/103832825/205418525-12985bed-d22d-4db0-8808-58304748678f.png)
![image](https://user-images.githubusercontent.com/103832825/205418536-5f32e9b6-a0d2-4811-b51e-02e90c8f14a8.png)

The adjacency matrix representation is good if the graphs are dense. The matrix requires O(V^2) bits of storage and O(V^2) time for initialization. If the number of edges is proportional to V^2, then there is no problem because V^2 steps are required to read the edges. If the graph is sparse, the initialization of the matrix dominates the running time of the algorithm as it takes takes O(V^2).

## Adjecency list
In this representation all the vertices connected to a vertex v are listed on an adjacency list for that vertex v. This can be easily implemented with linked lists. That means, for each vertex v we use a linked list and list nodes represents the connections between v and other vertices to which v has an edge.

<img src = "https://www.softwaretestinghelp.com/wp-content/qa/uploads/2020/05/7-6.png" alt = "Image of adjacency list">

## Comparison

![image](https://user-images.githubusercontent.com/103832825/205418780-9021d6f0-4d99-4265-b95a-63c7cea1faea.png)

# Traversal

# Minimum Spanning Trees 

For any Graph G = ( V , E ) , E' is a subset of E with minimum total weight such that G' = ( V , E' ) is a connected.

It is called as Minimum sice we try to output the edges with minumum total weight. Further, the graph so obtained is always a tree such that E' = V - 1 .

Imagine you have a set of comuters, and you want all of the computers to be accessible to each other directly or indirectly, and with the minimum amount of wires.
What we require in this case is a minimum spanning tree , weher each computer is a node and length of wires is edges and their cost. 

![146b47a](https://user-images.githubusercontent.com/103832825/206368911-f9f81771-ae27-4cbb-a3fa-70295fdc5436.jpg)

Prim's and Kruskal's algorithm are two such algorithms which help us in obtaining minimum spanning trees.

Prim's and Kruskal's algorithm are essentially <b>greedy algorithms</b> based on the <b>cut property</b>.
According to the cut property, If a Graph G ( V , E ) is cut into two sections such that one has X edges and other has V - X edges , where X is a subset of V, then in that case the minimum weighted edge that connects both the partions is always a part of the Minimum Spanning Tree.

![WhatsApp Image 2022-12-08 at 3 10 34 PM](https://user-images.githubusercontent.com/103832825/206412365-0501f7b4-00c4-4052-a57f-e9491c1bfcdc.jpeg)

## Kruskal's Algorithm

For Kruskal's algorithm, the underlying data structure is disjoint sets.
