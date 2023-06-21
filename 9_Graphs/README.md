# Graphs
<img src = "https://miro.medium.com/max/1400/1*dtmsuTMqRvYzkUCS25tLDA.jpeg" alt= "image of graph">

# Introduction

A Graph is a data structure which represents objects and connections between them. A graph is a pair (V, E), where V is a set of nodes, called vertices (which represent objects), and E is a collection of pairs of vertices, called edges (hich represent connections).

For example, the Internet often can be thought of as a graph, where you've got various web pages and theyre connected to each other by links. 

![image](https://user-images.githubusercontent.com/103832825/209884707-4b8529f3-0a38-421b-aa07-4b65aacdc4e1.png)

Another example is maps, you can think of maps as a graph, sort of where you have intersections that are connected by roads. For example, we might be interested in questions like: “What’s the fastest way to go from home to college?” or “What is the cheapest way to go from home to college”. Graphs are data structures used for solving these kinds of problems.

<img src = "https://www.mapsofindia.com/maps/gujarat/railways/bharuch_railway.jpg" alt = "Image of a city map">

# Representaion
Three ways to represent a graph are :-

## 1) Edge list
## 2) Adjacency Matrix

In this method, we use a matrix with size V × V. The values of matrix are boolean. The value of matrix[u][v] is set to 1 if there is an edge from vertex u to vertex v.

Adjacency matrix are useful to represent dense graphs.

## 3) Adjacency List

In this representation all the vertices connected to a vertex v are listed on A linked list for that vertex v.

Adjacency list are useful to represent sparse graphs.

![image](https://user-images.githubusercontent.com/103832825/209886437-a8edaa8b-4709-44cc-b5a5-0e2c300f8b4c.png)