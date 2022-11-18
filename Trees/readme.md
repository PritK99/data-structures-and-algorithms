# Trees

## Introduction 
A tree is a data structure similar to a linked list but instead of each node pointing simply to the next node in a linear fashion, each node points to a number of nodes. Tree is an example of a non linear data structure.
A tree structure is a way of representing the hierarchical nature of a structure in a graphical form.

<img src = "https://qph.cf2.quoracdn.net/main-qimg-cafdb4368095621b0b6cd00738c19f95-pjlq" alt = "Image of tree">

## Basic Terminology

![image](https://user-images.githubusercontent.com/103832825/202587670-af19129c-3a8d-46fc-a3e1-4bf80a59858e.png)

1) The set of all nodes at a given depth is called the <b>level</b> of the tree. The root node is at level zero (eg. Nodes B, C and D lie at level 1)
2) The <b>depth of a node</b> is the length of the path from the root to the node (eg. depth of G is 2, A – C – G).
3) The <b>height of a node</b> is the length of the path from that node to the deepest node. The height of a tree is the length of the path from the root to the deepest node in the tree(eg. the height of B is 2, B – F – J)
4) Height of the tree is the maximum height among all the nodes in the tree and depth of the tree is the maximum depth among all the nodes in the tree. For a given tree, depth and height returns the same value. But for individual nodes we may get different results.
5) If every node in a tree has only one child (except leaf nodes) then we call such trees <b>skew trees</b>. If every node has only left child then we call them left skew trees. Similarly, if every node has only right child then we call them right skew trees.
