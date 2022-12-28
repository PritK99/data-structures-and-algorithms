# Graphs
<img src = "https://cdn-media-1.freecodecamp.org/images/9KFiyFYi9bMktsJkMKLKaeJl31heUN9A-xrr" alt= "image of graph">

# Introduction

Graph: A graph is a pair (V, E), where V is a set of nodes, called vertices, and £ is a collection of pairs of vertices, called edges.

In the real world, many problems are represented in terms of objects and connections between them. 

For example, the Internet often can be thought of as a graph, where you've got various web pages and theyre connected to each other by links. On the other hand, if you want to do something like Google's page rank algorithm, make sort of heavy use of this very high level view of the Internet and connectivity within it. 

![image](https://user-images.githubusercontent.com/103832825/209884707-4b8529f3-0a38-421b-aa07-4b65aacdc4e1.png)

Another example is maps, you can think of maps as a graph, sort of where you have intersections that are connected by roads. For example, we might be interested in questions like: “What’s the fastest way to go from home to college?” or “What is the cheapest way to go from home to college”. Graphs are data structures used for solving these kinds of problems.

<img src = "https://www.mapsofindia.com/maps/gujarat/railways/bharuch_railway.jpg" alt = "Image of a city map">

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

The adjacency matrix representation is good if the graphs are dense. 

The matrix requires O(V^2) bits of storage and O(V^2) time for initialization. If the number of edges is proportional to V^2, then there is no problem because V^2 steps are required to read the edges. If the graph is sparse, the initialization of the matrix dominates the running time of the algorithm as it takes takes O(V^2).

## Adjecency list

In this representation all the vertices connected to a vertex v are listed on an adjacency list for that vertex v. This can be easily implemented with linked lists. That means, for each vertex v we use a linked list and list nodes represents the connections between v and other vertices to which v has an edge.

<br>
<img src = "https://www.softwaretestinghelp.com/wp-content/qa/uploads/2020/05/7-6.png" alt = "Image of adjacency list">

<br>

# Types of Graph

There are several types of graphs. Description of some of common types of graph is given below :-

## Undirected graph

## Directed Graph

Many a times, we deal with Directed graphs, or graphs where there is only a one-way relationship

![image](https://user-images.githubusercontent.com/103832825/206919370-1c11880e-d9a2-42e6-bcf7-67b3da328e42.png)

For eg. If we were to a city map as a graph, It has to be a directed graph since many roads are One-way i.e. there is only a one way relationship

Another example can be of hyperlinks. You may go to a page B from page A via a hyperlink, but then you may not be able to come back from B to A.

Another example is social networks. For eg. if you are a friend with someone, that is a symmetric relation, but if you are follower of a certain celebrity (say emma watson) , that becomes a one way relation.

## DAG - Directed Acyclic graph

A DAG is simply a Directed graph with no cycles. Hence, we can linearly order DAGs.

This linearly ordering of DAGs is called as Topological sorting.

The above graph is also a DAG, and hence when we sort it, we know we have to first Wake up, take a shower, dress up and then go to work. This is the linear order.

Also, since a DAG can always be linearly ordered, It has a source and a sink node.

<a href = "https://www.gatevidyalay.com/tag/connected-graph-definition/" alt="Referance to several types of graph">Click Here</a> to learn about several types of graph in detail.

### Strong connected components in a directed graph

For a given Directed graph, it can always be divided into a set of strongly connected components.

U and V strongly connected if there is a path from U to reach V and a path from V to reach U. In other words, U and V will be part of a cycle. Each set of strongly connected components can become a node in metagraph.

<img src = "https://images.slideplayer.com/19/5917165/slides/slide_12.jpg" alt = "Metagraph image">

# Traversal

The two of most popular traversing algorithm are DFS and BFS.

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
