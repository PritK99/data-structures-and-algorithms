# Trees

<img src = "https://qph.cf2.quoracdn.net/main-qimg-cafdb4368095621b0b6cd00738c19f95-pjlq" alt = "Image of tree">

## Introduction 
A tree is a data structure similar to a linked list but instead of each node pointing simply to the next node in a linear fashion, each node points to a number of nodes. Tree is an example of a non linear data structure.
A tree structure is a way of representing the hierarchical nature of a structure in a graphical form.

## Basic Terminology

![image](https://user-images.githubusercontent.com/103832825/202587670-af19129c-3a8d-46fc-a3e1-4bf80a59858e.png)

1) The set of all nodes at a given depth is called the <b>level</b> of the tree. The root node is at level zero (eg. Nodes B, C and D lie at level 1)
2) The <b>depth of a node</b> is the length of the path from the root to the node (eg. depth of G is 2, A – C – G).
3) The <b>height of a node</b> is the length of the path from that node to the deepest node. The height of a tree is the length of the path from the root to the deepest node in the tree(eg. the height of B is 2, B – F – J)
4) Height of the tree is the maximum height among all the nodes in the tree and depth of the tree is the maximum depth among all the nodes in the tree. For a given tree, depth and height returns the same value. But for individual nodes we may get different results.
5) If every node in a tree has only one child (except leaf nodes) then we call such trees <b>skew trees</b>. If every node has only left child then we call them left skew trees. Similarly, if every node has only right child then we call them right skew trees.

## Tree Traversals 

* Pre-ord

## Binary Trees
A tree is called binary tree if each node has zero child, one child or two children.

## AVL Trees

The tree data structure proves to be effective only when the tree is a balanced in nature. 

The runtime of the tree depends upon the depth of the tree. Only when the tree is a balance binary tree, we can perform the operations such as insertion, deletion, search, range, etc. in O(log(n)) time. 

Else, the time complexity moves to O(n). In the worst case, the tree data structure is skewed and simply behaves like a sorted linked-list. Thus, inorder to keep our runtimes limited to O(log(n)), we must ensure our tree are balanced at all times.

Height of a given tree helps to define the balance parameter. In general, for any given node, if it satisfies the given property, it is an AVL tree or a balanced binary tree

```|(Height of left subtree) - (Height of right subtree)| <= 1```

## CoC notes


* Always some sort of traversal
* Inverting a binary tree
* Always mention in comments your base case and rec case
* Lowest common ancestor
* In trees, you cant have a parent pointer as such. But then you can make use of recursion, you can return it and treat that as a parent link. This time I am making use of unwinding part
* For tree, call left, call right, return, get their results and club them up in parent