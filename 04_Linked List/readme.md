# Linked Lists 

## Why Linked lists ?
Stacks and Queues are great data structures to store data. However, there are a few limitations to use of stacks and queues.
Both stacks and queues are statically allocated memory, which means that the amount of memory allocated to stack or queue is fixed and cannot be changed.

Imagine that you allocate an array of MAX_SIZE 100 to a stack. Now, even if there are 20 elements in your stack, the remaining space of 80 elements can not be used by the program. Tommorow, if you want to insert the 101th element, it is not possible to insert it directly since you are out of space.
Linked Lists solve this problem using dynamic memory allocation. Whenever we need to store an element, we create a node in linked list using malloc() / new function and once we are done with the element, we destroy the node using free() / delete()  functions, hence making that memory usable by program for other tasks.

## Introduction 
Every element in a Linked list is stored in the form of a node. A node comprises of two things, data and the the address of the next node.
We also have an external pointer called head poinying at the first node of linked list.

## Types of Linked List
1) Singly Linked List
2) Doubly Linked List
3) Circular Linked List
4) Circular Doubly Linked List 

## Proof for Floyd Cycle Detection Algorithm

<img src="../assets/Floyd Cycle Detection.jpeg" alt="Floyd Cycle Detection">

Here, we know that ```k``` has to be a node in the loop, only then can the slow pointer and fast pointer intersect. Now, the slow pointer may take ```m + Al + k``` steps and fast pointer may take ```m + Bl + k``` steps where ```A``` and ```B``` are constants which can be any number. The idea being that the slow or fast pointer might have to move full loops ```A``` or ```B``` times respectively before intersection, where ```B > A```. But we also know that,
```
fast = 2*slow
```
```
m + Bl + k = 2*(m + Al + k)
```
```
(B - 2A)l = m+k
```
```
constant*l = m+k
```
Thus, ```m+k = c*l```, where c is an integer constant.

This signifies that ```m+k``` steps are equivalent to looping ```c``` number of times in the loop and coming back to same position.

Now as per algorithm, we reset fast pointer to head, and make it now behave like slow. Doing this, it is guranteed that the next intersection point is the node which marks the start of cycle.

This is because, now the fast pointer has to take ```m``` steps to reach the first node of cycle. Thus, the slow pointer will make ```c*l - k``` steps. This ensures that the position of slow pointer after ```c*l - k``` steps will be the first node of cycle.
