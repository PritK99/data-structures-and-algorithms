# Introduction
A queue is defined as a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order. One end is always used to insert data (enqueue) and the other is used to remove data (dequeue).

## Types of Queue 
1) Simple Queue
2) Circular Queue
3) Priority Queue (PQ)
4) Double ended Queue (DEQUE)

## Data we need for Queues 
1) Space for storing elements
2) Front pointer - usually for deletion
3) Rear pointer - usually for insertion 

## Basic operations on Queue
1) Enqueue() : To insert an element to queue
2) Dequeue() : To delete an element from to queue
3) IsEmpty() : To check if queue is empty
4) IsFull() : To check if queue is full 

## Implenting Queues
There are two methods to implement queues 
1) Using arrays 
2) Using Linked List 

# Circular Queues

# DEQueues 
Double-Ended-Queues (DEQueues) are a type of queue, which do not follow FIFO exactly.In simple queues, front is used to delete an element and rear is used to insert an element. However, Double-Ended-Queue allow insertion and deletion at both ends , front and rear.
Further subtypes of DEQueue :-
1) Input-Resticted-Dequeue - Insertion only takes place at rear end, while deletion can take place at either of ends
2) Output-Resticted-Dequeue - Deletion only takes place at front end, while insertion can take place at either of ends

# Priority Queues
