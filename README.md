# The Data Structures and Algorithm Saga 

## Table of contents 


## Introduction
A data structure is a data organization, management, and storage format that is usually chosen for efficient access to data. In simple words, data structures are just a way to represent data in memory which makes storing, operating on them etc very efficient.

<img src = "https://i.ytimg.com/vi/Qmt0QwzEmh0/maxresdefault.jpg" alt = "Images of Data structure">

Some of the commonly used data structures are :-
1) Arrays
2) Stacks 
3) Queues 
4) Linked List
5) Tree
6) Heaps
7) Graphs

## Time complexity 

Consider the following algorithm for calculating nth Fibonacci number.

![image](https://user-images.githubusercontent.com/103832825/213064383-fde80516-e343-4982-92ad-4e36f17c0190.png)

Thus, we start by creating an array. We assigned the 0th element to 0. The first element to 1. Then, we have this big for loop where we set the i'th element to the sum of the i minus first and i minus second elements and then at the end of the day we return the nth element. So we determined that when we ran this program we executed about 2n + 2 lines of code. 

But we should really ask ourselves, is this number of lines of code executed really sort of an accurate description of the runtime of the algorithm? Somehow, implicitly, this measure of lines of code assumes that, sort of, any two lines of code are sort of comparable to each other, which may not be true always.

Thus, the time it will take for the computer to run this code depends on severaal factors such as system architecture, compiler, memory organizations etc. which may vary from computer to computer drastically. Thus this is not such an efficient measure of time.

Hence, we find time complexity such that it tells us how our <b>runtime</b> scales with <b>input size</b>, and not necessarily how long it actually takes in terms of real seconds, minutes, and hours. 

This is generally denoted by <b>Big-O</b> such as O(nlogn)

![image](https://user-images.githubusercontent.com/103832825/213328248-1b7095f6-08e0-4202-ab2a-7ef6acfbf2eb.png)

<a href = "https://github.com/PritK99/data-structures-and-algorihms/blob/main/bigO.md" >Click here</a> to see plots of various functions (such as logarithm, polynomial, exponent) and understand rules of Big-O.

### A few noteworthy points :- 
1) Pointers always take up 8 bytes of space in 64 bit architecture 
2) Struct involves padding while allocating memory , so even a struct of an int and char takes 8 bytes , while the struct of char takes 1 byte 

### References


