# Linked Lists 

## Why Linked lists ?
Stacks and Queues are great data structures to store data. However, there are a few limitations to use of stacks and queues.
Both stacks and queues are statically allocated memory, which means that the amount of memory allocated to stack or queue is fixed and cannot be changed.

Imagine that you allocate an array of MAX_SIZE 100 to a stack. Now, even if there are 20 elements in your stack, the remaining space of 80 elements can not be used by the program. Tommorow, if you want to insert the 101th element, it is not possible to insert it directly since you are out of space.
Linked Lists solve this problem using dynamic memory allocation. Whenever we need to store an element, we create a node in linked list using malloc() / new function and once we are done with the element, we destroy the node using free() / delete()  functions, hence making that memory usable by program for other tasks.

## Introduction 
Every element in a Linked list is stored in the form of a node. A node comprises of two things, data and the the address of the next node.
We also have an external pointer called head poinying at the first node of linked list.
